#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QChartView>
#include<QGraphicsView>
#include<QMouseEvent>
#include<QWheelEvent>
#include <QGraphicsScene>
#include <QChart>
#include <QtCharts>
#include <QLineSeries>
#include <QSplineSeries>
#include<QGraphicsLineItem>
#include<QTimer>
#include<QChart>
#include <QValueAxis>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class ChartView;
}

class ChartView : public QChartView
{
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = 0);
    ~ChartView();
    qreal getYValue(QPointF p1,QPointF p2,qreal x);
    void createChart ();
    void prepareData();
    void updateFromChart();


protected:
    bool viewportEvent(QEvent *event)override;
    void resizeEvent(QResizeEvent *event);

public slots:
    void connectMarkers();
    void handleMarkerClicked();

    void tooltip(QPointF point, bool state);

private slots:
    void handleTimeout();
    void applyClear();
    void applySave();
    void applyExport();
private:
    QLineSeries* m_series;
    QChart* m_chart;
    QValueAxis* m_axisX;
    QValueAxis* m_axisY;
    QTimer m_timer;
    int m_x;
    int m_max;
    bool m_isTouching;
    Ui::ChartView* m_ui = nullptr;




public:
    bool m_isBuoyShow;

};

#endif // CHARTVIEW_H
