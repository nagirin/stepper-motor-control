#include "chartview.h"
#include "ui_chartview.h"
#include<QDebug>
#include<QGraphicsView>
#include <QLegendMarker>
#include <QQueue>
#include <QtMath>
#include<QApplication>
#include<QCategoryAxis>

#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif

ChartView::ChartView(QWidget *parent) :
    QChartView(parent),      
    m_x(0),
    m_max(50),
    m_isTouching(false),
    m_ui(new Ui::ChartView),
    m_isBuoyShow(true)
{
    m_ui->setupUi(this);
    m_series=new QLineSeries;
    m_chart=new QChart;

    m_series->append(0,0);
    m_series->setName("ss");
    m_chart->addSeries(m_series);
    m_chart->createDefaultAxes();
    m_chart->setTitle("Shear Force Curve");

    m_axisX=new QValueAxis;
    m_axisX->setRange(0,60);
    m_axisX->setTitleText("Time(s)");
    m_axisX->setGridLineVisible(true);
    m_axisX->setTickCount(11);     //标记的个数
    m_axisX->setMinorTickCount(5); //次标记的个数

    m_axisY=new QValueAxis;
    m_axisY->setRange(0,20);
    m_axisY->setTitleText("Force(N)");
    m_axisY->setGridLineVisible(true);
    m_axisY->setTickCount(6);
    m_axisY->setMinorTickCount(2);

    m_chart->setAxisX(m_axisX,m_series);
    m_chart->setAxisY(m_axisY,m_series);

    m_chart->legend()->hide();

    m_ui->chart_Shear->setChart(m_chart);
    m_ui->chart_Shear->setRenderHint(QPainter::Antialiasing);
    m_ui->chart_Shear->setRubberBand(QChartView::RectangleRubberBand);    


    m_timer.setInterval(1000);
    m_timer.start();
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(handleTimeout()));

    connectMarkers();

    //浮框
    connect(m_series, SIGNAL(hovered(QPointF, bool)), this, SLOT(tooltip(QPointF,bool)));
    connect(m_ui->button_Clear, &QPushButton::clicked, this, &ChartView::applyClear);
    connect(m_ui->button_Save, &QPushButton::clicked, this, &ChartView::applySave);
    connect(m_ui->button_Export, &QPushButton::clicked, this, &ChartView::applyExport);
    this->setMouseTracking(true);


}

ChartView::~ChartView()
{
    delete m_ui;
}




qreal ChartView::getYValue(QPointF p1, QPointF p2, qreal x)
{
    qreal y=(p2.y()-p1.y())/(p2.x()-p1.x())*(x-p1.x())+p1.y();
    return y;

}

bool ChartView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {

        m_isTouching = true;

        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

void ChartView::resizeEvent(QResizeEvent *event)
{
    if (scene()) {
        scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
         m_chart->resize(event->size());
    }
    QChartView::resizeEvent(event);
}



void ChartView::connectMarkers()
{
    foreach (QLegendMarker* marker, m_chart->legend()->markers()) {
        QObject::disconnect(marker, SIGNAL(clicked()), this, SLOT(handleMarkerClicked()));
        QObject::connect(marker, SIGNAL(clicked()), this, SLOT(handleMarkerClicked()));
    }

}

void ChartView::handleMarkerClicked()
{

    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
    Q_ASSERT(marker);

    switch (marker->type())

    {
        case QLegendMarker::LegendMarkerTypeXY:
        {

        marker->setVisible(true);

        qreal alpha;

        QColor color;
        QPen pen = marker->pen();
        color = pen.color();

        if(color.alphaF()==1.0){
            //未点击
            alpha=0.2;

            QFont font=marker->font();
            font.setBold(true);
            marker->setFont(font);

        }else {
            //已点击
            alpha=1.0;

            QFont font=marker->font();
            font.setBold(false);
            marker->setFont(font);
        }

        QList<QAbstractSeries *> seriesList=m_chart->series();

        for(int i=0;i<seriesList.size();i++){

           QLineSeries* series=(QLineSeries*)seriesList.at(i);
           if(series!=marker->series()){
               QPen seriesPen=series->pen();
               QColor color=seriesPen.color();
               color.setAlphaF(alpha);
               seriesPen.setColor(color);
               series->setPen(seriesPen);


           }
        }

        color.setAlphaF(alpha);
        pen.setColor(color);
        marker->setPen(pen);



        break;
        }
    default:
        {
        qDebug() << "Unknown marker type";
        break;
        }
    }


}

void ChartView::tooltip(QPointF point, bool state)
{

}

void ChartView::handleTimeout()
{
//    if(this->isVisible())
//    {//在可视的情况下刷新数据
//        int y=1;
//        QVector<QPointF> points=m_series->pointsVector();
//        points.append(QPointF(m_x,4));

//        if(points.size()>m_max){//达到限值
//            points.pop_front();
//        }
//        m_series->replace(points);

//        if(m_x>60)
//        {
//            m_chart->axisX()->setRange(m_x-59,m_x);
//        }

//        m_x++;
//    }
}

void ChartView::applyClear()
{
    QVector<QPointF> points;
    m_series->replace(points);
}

void ChartView::applySave()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images(*.png *.bmp *.jpg)"));
    QChartView *view = new QChartView;
    QScreen* screen = QGuiApplication::primaryScreen();
    QPixmap p = screen->grabWindow(view->winId());
    QImage image = p.toImage();
    image.save(filename);
}

void ChartView::applyExport()
{

}
