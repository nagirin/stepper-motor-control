/********************************************************************************
** Form generated from reading UI file 'chartview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTVIEW_H
#define UI_CHARTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_ChartView
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QChartView *chart_Shear;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_Save;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_Clear;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *button_Export;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ChartView)
    {
        if (ChartView->objectName().isEmpty())
            ChartView->setObjectName(QString::fromUtf8("ChartView"));
        ChartView->resize(592, 537);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChartView->sizePolicy().hasHeightForWidth());
        ChartView->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icone/curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChartView->setWindowIcon(icon);
        gridLayout = new QGridLayout(ChartView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chart_Shear = new QChartView(ChartView);
        chart_Shear->setObjectName(QString::fromUtf8("chart_Shear"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chart_Shear->sizePolicy().hasHeightForWidth());
        chart_Shear->setSizePolicy(sizePolicy1);
        chart_Shear->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(chart_Shear);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_Save = new QPushButton(ChartView);
        button_Save->setObjectName(QString::fromUtf8("button_Save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icone/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Save->setIcon(icon1);

        horizontalLayout_2->addWidget(button_Save);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        button_Clear = new QPushButton(ChartView);
        button_Clear->setObjectName(QString::fromUtf8("button_Clear"));
        button_Clear->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icone/broom.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Clear->setIcon(icon2);

        horizontalLayout_2->addWidget(button_Clear);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        button_Export = new QPushButton(ChartView);
        button_Export->setObjectName(QString::fromUtf8("button_Export"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icone/output.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_Export->setIcon(icon3);

        horizontalLayout_2->addWidget(button_Export);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ChartView);

        QMetaObject::connectSlotsByName(ChartView);
    } // setupUi

    void retranslateUi(QWidget *ChartView)
    {
        ChartView->setWindowTitle(QCoreApplication::translate("ChartView", "Curve", nullptr));
        button_Save->setText(QCoreApplication::translate("ChartView", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        button_Clear->setText(QCoreApplication::translate("ChartView", "\346\270\205\351\231\244\346\233\262\347\272\277", nullptr));
        button_Export->setText(QCoreApplication::translate("ChartView", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartView: public Ui_ChartView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTVIEW_H
