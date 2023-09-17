/********************************************************************************
** Form generated from reading UI file 'chart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHART_H
#define UI_CHART_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chartview.h>

QT_BEGIN_NAMESPACE

class Ui_ChartView
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_curve;
    ChartView *chart_Shear;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_Save;
    QPushButton *button_Clear;
    QPushButton *button_Export;

    void setupUi(QWidget *ChartView)
    {
        if (ChartView->objectName().isEmpty())
            ChartView->setObjectName(QString::fromUtf8("ChartView"));
        ChartView->resize(456, 352);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icone/curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChartView->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(ChartView);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 421, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_curve = new QLabel(verticalLayoutWidget);
        label_curve->setObjectName(QString::fromUtf8("label_curve"));

        verticalLayout->addWidget(label_curve);

        chart_Shear = new ChartView(verticalLayoutWidget);
        chart_Shear->setObjectName(QString::fromUtf8("chart_Shear"));

        verticalLayout->addWidget(chart_Shear);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_Save = new QPushButton(verticalLayoutWidget);
        button_Save->setObjectName(QString::fromUtf8("button_Save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icone/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Save->setIcon(icon1);

        horizontalLayout->addWidget(button_Save);

        button_Clear = new QPushButton(verticalLayoutWidget);
        button_Clear->setObjectName(QString::fromUtf8("button_Clear"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icone/broom.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Clear->setIcon(icon2);

        horizontalLayout->addWidget(button_Clear);

        button_Export = new QPushButton(verticalLayoutWidget);
        button_Export->setObjectName(QString::fromUtf8("button_Export"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icone/output.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Export->setIcon(icon3);

        horizontalLayout->addWidget(button_Export);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChartView);

        QMetaObject::connectSlotsByName(ChartView);
    } // setupUi

    void retranslateUi(QWidget *ChartView)
    {
        ChartView->setWindowTitle(QCoreApplication::translate("ChartView", "Curve", nullptr));
        label_curve->setText(QCoreApplication::translate("ChartView", "\345\211\252\345\210\207\345\212\233\346\233\262\347\272\277\357\274\232", nullptr));
        button_Save->setText(QCoreApplication::translate("ChartView", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        button_Clear->setText(QCoreApplication::translate("ChartView", "\346\270\205\351\231\244\345\233\276\345\203\217", nullptr));
        button_Export->setText(QCoreApplication::translate("ChartView", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartView: public Ui_ChartView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_H
