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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QSerialPort>
#include <QDebug>
#include <QThread>
QT_BEGIN_NAMESPACE

class SerialWorker;
class QRingBuffer;
class QLabel;
class Protocol;

enum MotorState{ XAxisRun = 0,
                 YAxisRun,
                 ZAxisRun,
                 Idle};

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class ChartView;
class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void serialDataSend(const QByteArray data);
    void sendToCmd(QByteArray cmd);
    void motorState(const bool state, const double position);
    void doHome();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void openCurve();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);
    void handleResults(QString result);
    void set_mcu_cmd(quint8 cmd, quint8 id);
    void set_motor_spedd(quint8 cmd, quint8 id, quint32 data);

//    void setHome();
//    void serialsendMessage();
//    void setPosition(const double position);
//    void errorSerial();


    void applyHome();
    void applyStart();
    void applyPause();
    void applyStop();
    void applySpeed();
    void applyForward();
    void applyBackward();
    void selectMotor();

private:
    void initActionsConnections();
    void initMotorCommand();
private:
    void showStatusMessage(const QString &message);
    void showStateMotor(MotorState state);


    Ui::MainWindow *m_ui = nullptr;
    QLabel *m_status = nullptr;

    QThread serialThread;
    QThread motorThread;
    QThread curveThread;

    Console *m_console = nullptr;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
    QSerialPort *m_serialM = nullptr;

    SerialWorker *serialWorker;

    QMessageBox *m_infoHome;
    ChartView *m_chart = nullptr;
    bool m_motorRun;

    QRingBuffer *ringBuffer;
    Protocol *m_protocol = nullptr;
    quint8 sum;
    quint8 *ptr = nullptr;

};

#endif // MAINWINDOW_H
