/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <console.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionQuit;
    QAction *actionConfigure;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionClearConsole;
    QAction *actionCurve;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_console;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_state;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_MotorAxis;
    QComboBox *MotorAxisBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_Start;
    QPushButton *button_Pause;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *button_Home;
    QPushButton *button_Stop;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_Speed;
    QSpinBox *box_Speed;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_Forward;
    QPushButton *button_Backward;
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Console;
    Console *console_Window;
    QMenuBar *menubar;
    QMenu *menuConnect;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(533, 404);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../serial_moter/motor.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icone/usb.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icone/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icone/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon3);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icone/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon4);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icone/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon5);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icone/Qt_logo_2016.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon6);
        actionClearConsole = new QAction(MainWindow);
        actionClearConsole->setObjectName(QString::fromUtf8("actionClearConsole"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icone/broom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearConsole->setIcon(icon7);
        actionCurve = new QAction(MainWindow);
        actionCurve->setObjectName(QString::fromUtf8("actionCurve"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("icone/curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCurve->setIcon(icon8);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_console = new QLabel(centralwidget);
        label_console->setObjectName(QString::fromUtf8("label_console"));

        gridLayout->addWidget(label_console, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_state = new QLabel(groupBox);
        label_state->setObjectName(QString::fromUtf8("label_state"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_state->setFont(font);
        label_state->setFrameShape(QFrame::Panel);
        label_state->setTextFormat(Qt::AutoText);
        label_state->setScaledContents(false);
        label_state->setWordWrap(false);

        verticalLayout_4->addWidget(label_state);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_MotorAxis = new QLabel(groupBox);
        label_MotorAxis->setObjectName(QString::fromUtf8("label_MotorAxis"));

        horizontalLayout_6->addWidget(label_MotorAxis);

        MotorAxisBox = new QComboBox(groupBox);
        MotorAxisBox->addItem(QString());
        MotorAxisBox->addItem(QString());
        MotorAxisBox->addItem(QString());
        MotorAxisBox->setObjectName(QString::fromUtf8("MotorAxisBox"));

        horizontalLayout_6->addWidget(MotorAxisBox);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_Start = new QPushButton(groupBox);
        button_Start->setObjectName(QString::fromUtf8("button_Start"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("icone/start green.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Start->setIcon(icon9);

        horizontalLayout_2->addWidget(button_Start);

        button_Pause = new QPushButton(groupBox);
        button_Pause->setObjectName(QString::fromUtf8("button_Pause"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("icone/Pause Normal Red.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Pause->setIcon(icon10);

        horizontalLayout_2->addWidget(button_Pause);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        button_Home = new QPushButton(groupBox);
        button_Home->setObjectName(QString::fromUtf8("button_Home"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("icone/house.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Home->setIcon(icon11);

        horizontalLayout_7->addWidget(button_Home);

        button_Stop = new QPushButton(groupBox);
        button_Stop->setObjectName(QString::fromUtf8("button_Stop"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("icone/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Stop->setIcon(icon12);

        horizontalLayout_7->addWidget(button_Stop);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        button_Speed = new QPushButton(groupBox);
        button_Speed->setObjectName(QString::fromUtf8("button_Speed"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/iconeMotor/icone/route.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Speed->setIcon(icon13);

        horizontalLayout_3->addWidget(button_Speed);

        box_Speed = new QSpinBox(groupBox);
        box_Speed->setObjectName(QString::fromUtf8("box_Speed"));

        horizontalLayout_3->addWidget(box_Speed);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_Forward = new QPushButton(groupBox);
        button_Forward->setObjectName(QString::fromUtf8("button_Forward"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("icone/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Forward->setIcon(icon14);

        horizontalLayout->addWidget(button_Forward);

        button_Backward = new QPushButton(groupBox);
        button_Backward->setObjectName(QString::fromUtf8("button_Backward"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("icone/backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Backward->setIcon(icon15);

        horizontalLayout->addWidget(button_Backward);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);


        horizontalLayout_4->addLayout(verticalLayout_4);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_Console = new QLabel(groupBox);
        label_Console->setObjectName(QString::fromUtf8("label_Console"));
        label_Console->setFrameShape(QFrame::NoFrame);
        label_Console->setFrameShadow(QFrame::Plain);

        verticalLayout_2->addWidget(label_Console);

        console_Window = new Console(groupBox);
        console_Window->setObjectName(QString::fromUtf8("console_Window"));
        console_Window->setEnabled(true);
        console_Window->setMaximumSize(QSize(10000000, 10000000));

        verticalLayout_2->addWidget(console_Window);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 533, 26));
        menuConnect = new QMenu(menubar);
        menuConnect->setObjectName(QString::fromUtf8("menuConnect"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuConnect->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuConnect->addAction(actionConnect);
        menuConnect->addAction(actionDisconnect);
        menuConnect->addSeparator();
        menuConnect->addSeparator();
        menuConnect->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClearConsole);
        menuTools->addAction(actionCurve);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        toolBar->addSeparator();
        toolBar->addAction(actionConnect);
        toolBar->addAction(actionDisconnect);
        toolBar->addAction(actionConfigure);
        toolBar->addAction(actionCurve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "motor Interface 1.1", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "&Connect", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "&Disconnect", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionClearConsole->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionCurve->setText(QCoreApplication::translate("MainWindow", "Curve", nullptr));
        label_console->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Motor Control :", nullptr));
        label_state->setText(QCoreApplication::translate("MainWindow", "Motor States : ", nullptr));
        label_MotorAxis->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\351\200\211\346\213\251", nullptr));
        MotorAxisBox->setItemText(0, QCoreApplication::translate("MainWindow", "X\350\275\264", nullptr));
        MotorAxisBox->setItemText(1, QCoreApplication::translate("MainWindow", "Y\350\275\264", nullptr));
        MotorAxisBox->setItemText(2, QCoreApplication::translate("MainWindow", "Z\350\275\264", nullptr));

        button_Start->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        button_Pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        button_Home->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        button_Stop->setText(QCoreApplication::translate("MainWindow", "\346\200\245\345\201\234", nullptr));
        button_Speed->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\237\345\272\246", nullptr));
        button_Forward->setText(QCoreApplication::translate("MainWindow", "\345\211\215\350\277\233", nullptr));
        button_Backward->setText(QCoreApplication::translate("MainWindow", "\345\220\216\351\200\200", nullptr));
        label_Console->setText(QCoreApplication::translate("MainWindow", "Console :", nullptr));
        menuConnect->setTitle(QCoreApplication::translate("MainWindow", "main", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
