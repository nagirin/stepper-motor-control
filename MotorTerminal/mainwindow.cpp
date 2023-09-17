/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "serialworker.h"
#include "motorwork.h"
#include "protocol.h"
#include "chartview.h"
#include <QLabel>
#include <QMessageBox>

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_status(new QLabel),
    m_console(new Console),
    m_settings(new SettingsDialog),
    m_serial(new QSerialPort)
//! [1]
{
//! [0]
    m_ui->setupUi(this);

    m_console = m_ui->console_Window;
    m_serialM = new QSerialPort ;
    m_chart = new ChartView;
    m_infoHome = new QMessageBox(this);

    m_infoHome->setWindowModality(Qt::ApplicationModal);
    m_infoHome->setDefaultButton(QMessageBox::Ok);
    m_infoHome->setWindowTitle("back to the origin");
    m_infoHome->setText("Wait for the motor to return to the origin. "
"\nIf the motor is in the origin press ''Ok''. ");

    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);

    m_status = new QLabel;
    m_ui->statusbar->addWidget(m_status);

    initActionsConnections();
    initMotorCommand();
    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

        // 在主线程接收串口数据
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    connect(m_console, &Console::getData, this, &MainWindow::writeData);

    SerialWorker *serialWorker = new SerialWorker(m_serial);
    // 将串口和子类一同移入子线程
    serialWorker->moveToThread(&serialThread);

//    // 连接信号和槽
//        connect(&serialThread, &QThread::finished,
//                serialWorker, &QObject::deleteLater);           // 线程结束，自动删除对象
//        connect(this, &MainWindow::serialDataSend,
//                serialWorker, &SerialWorker::doDataSendWork);   // 主线程串口数据发送的信号
//        connect(m_serial, &QSerialPort::readyRead,
//                serialWorker, &SerialWorker::doDataReciveWork); // 主线程通知子线程接收数据的信号
//        connect(serialWorker, &SerialWorker::sendResultToGui,
//               this, &MainWindow::handleResults);             // 主线程收到数据结果的信号


        // 开始运行子线程
        serialThread.start();                   // 线程开始运行


}
//! [3]

MainWindow::~MainWindow()
{
    serialThread.quit();
    serialThread.wait();
    delete m_settings;
    delete m_ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        m_console->setEnabled(true);
        m_console->setLocalEchoEnabled(p.localEchoEnabled);
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    //m_console->setEnabled(false);
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}

void MainWindow::openCurve() {
    emit m_chart->show();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About motor"),
                       tr("The <b>motor</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    m_serial->clear(QSerialPort::AllDirections);
    m_serial->write(data);
    //m_serial->waitForBytesWritten();

    //emit serialDataSend(data);
    qDebug() <<data<< QThread::currentThreadId();
}
//! [6]

//主线程读数据
void MainWindow::readData()
{

    const QByteArray data = m_serial->readAll();
    qDebug() << data <<QThread::currentThreadId();
    qint8 cmd = data[6];
    qint8 Byte[4];
    float data_f;

    if(((data[0] <<  0) |
        (data[1] <<  8) |
        (data[2] << 16) |
        (data[3] << 24)) == FRAME_HEADER)
    {
        qDebug() <<"帧头正确";
        if (m_protocol->Crc8(data) == data[data.size()-1])
         {
             qDebug() <<"校验通过";
             switch(cmd)
                  {
                    case SEND_START_CMD:
                  {
                    applyStart();
             }break;
             case SEND_DATA_CMD:
           {
              Byte[0]=data[7];
              Byte[1]=data[8];
              Byte[2]=data[9];
              Byte[3]=data[10];
              data_f = *(float *)&Byte;
              qDebug() << "SEND_DATA_CMD"<<data_f;
      }break;


         }
    }
    //else
        m_console->putData(data);
}
}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::handleResults(QString result)
{
    //qDebug() <<  "主线程收到结果数据：" << result << "线程ID：" << QThread::currentThreadId();
    QByteArray data = result.toUtf8();
    m_console->putData(data);
}

void MainWindow::initActionsConnections()
{
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionClearConsole, &QAction::triggered, m_console, &Console::clear);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAbout_Qt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(m_ui->actionCurve, &QAction::triggered,this, &MainWindow::openCurve);
}

void MainWindow::initMotorCommand()
{
    connect(m_ui->button_Home, &QPushButton::clicked, this, &MainWindow::applyHome);
    connect(m_ui->button_Start, &QPushButton::clicked, this, &MainWindow::applyStart);
    connect(m_ui->button_Pause, &QPushButton::clicked, this, &MainWindow::applyPause);
    connect(m_ui->button_Stop, &QPushButton::clicked, this, &MainWindow::applyStop);
    connect(m_ui->button_Speed, &QPushButton::clicked, this, &MainWindow::applySpeed);
    connect(m_ui->button_Forward, &QPushButton::clicked, this, &MainWindow::applyForward);
    connect(m_ui->button_Backward, &QPushButton::clicked, this, &MainWindow::applyBackward);
    connect(m_ui->MotorAxisBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::selectMotor);

}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}
void MainWindow::showStateMotor(MotorState state)
{

    switch (state) {
    case XAxisRun:
        m_ui->label_state->setText("Current Motor : XAxis");
        break;
    case YAxisRun:
        m_ui->label_state->setText("Current Motor : YAxis");
        break;
    case ZAxisRun:
        m_ui->label_state->setText("Current Motor : ZAxis");
        break;
    case Idle:
        m_ui->label_state->setText("Motor States : Idle");
        break;
    }

}

void MainWindow::set_mcu_cmd(quint8 cmd, quint8 id)
{
  quint8 sum = 0;    // 校验和
  m_protocol = new Protocol;
  QByteArray set_packet;
  set_packet.resize(8);
  set_packet[0] =  0x59;    // 包头 0x59485A53
  set_packet[1] =  0x48;
  set_packet[2] =  0x5A;
  set_packet[3] =  0x53;
  set_packet[4] =  id;
  set_packet[5] =  0x08;
  set_packet[6] =  cmd;


  sum = m_protocol->Crc8(set_packet);       // 计算包头校验和
  set_packet[7] = sum;

  writeData(set_packet);
}

void MainWindow::set_motor_spedd(quint8 cmd, quint8 id, quint32 data)
{
    quint8 sum = 0;    // 校验和

    QByteArray set_packet;
    set_packet.resize(9);
    set_packet[0] =  0x59;    // 包头 0x59485A53
    set_packet[1] =  0x48;
    set_packet[2] =  0x5A;
    set_packet[3] =  0x53;
    set_packet[4] =  id;
    set_packet[5] =  0x09;
    set_packet[6] =  cmd;
    set_packet[7] =  data;
    sum = m_protocol->Crc8(set_packet);
    set_packet[8] =  sum;
    writeData(set_packet);
}

void MainWindow::applyHome()
{
    //回到原点
    quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
    set_mcu_cmd(RESET_CMD, id);
    m_infoHome->show();
}

 void MainWindow::applyStart()
 {
    //启动电机
    quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
    set_mcu_cmd(START_CMD, id);
    qDebug() <<"Start";
 }

 void MainWindow::applyPause()
 {
    //电机暂停
    quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
    set_mcu_cmd(PAUSE_CMD, id);
    //m_console->putData("Pause");
 }

 void MainWindow::applyStop()
 {
    //急停
     quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
     set_mcu_cmd(STOP_CMD, id);
     //m_console->putData("Stop");
 }

 void MainWindow::applySpeed()
 {
    //设置电机速度并发送给下位机
     int speed = m_ui->box_Speed->value();
     quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
     set_motor_spedd(SET_SPEED_CMD, id, speed);
    //QByteArray V = QByteArray::number(speed, 10);
     //m_console->putData(V);
 }

 void MainWindow::applyForward()
 {
    //单步向前移动
     quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
     set_mcu_cmd(FORWARD_CMD, id);
     //m_console->putData("Forward");
 }

 void MainWindow::applyBackward()
 {
    //单步向后移动
     quint8 id = m_ui->MotorAxisBox->currentIndex() + 1;
     set_mcu_cmd(BACKWARD_CMD, id);
     //m_console->putData("Backward");
 }

 void MainWindow::selectMotor()
 {
    //选择电机     
     switch (m_ui->MotorAxisBox->currentIndex()) {
     case 0:
         m_console->putData("XAxis \n");
         break;
     case 1:
         m_console->putData("YAxis \n");
         break;
     case 2:
         m_console->putData("ZAxis \n");
         break;

     }
 }

