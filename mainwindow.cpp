#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "GVCore/gvpolyline.h"
#include "GVCore/gvgistagram.h"
#include "GVCore/gvquarter.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    /*
    GVGrid *grid = new GVGrid(20, 300, 300, QColor(Qt::black));
    grid->draw(scene);
    */

    /*
    GVPolyLine *line = new GVPolyLine();
    line->addPoint(new GVPoint(0.0, 0.0));
    line->addPoint(new GVPoint(100.0, 0.0));
    line->addPoint(new GVPoint(20.0, 100.0));
    line->setColorLine(QColor(Qt::red));
    line->draw(scene);
    */

    GVQuarter *quarter = new GVQuarter(300, 400, QColor(Qt::gray), "Товары", "Популярность");
    quarter->draw(scene);

    GVGistagram *gisto = new GVGistagram();
    gisto->addGistoItem(new GVGistragramItem("first", 13, QColor(Qt::red)));
    gisto->addGistoItem(new GVGistragramItem("Second", 42, QColor(Qt::blue)));
    gisto->addGistoItem(new GVGistragramItem("Third", 52, QColor(Qt::green)));
    gisto->addGistoItem(new GVGistragramItem("Four", 33, QColor(Qt::yellow)));
   // gisto->setMaxValue(100);
    gisto->draw(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}
