#ifndef GVGRID_H
#define GVGRID_H

#include "gvobject.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGlobal>
#include "gvexeption.h"

class GVGrid : public GVObject
{
public:
    GVGrid();
    GVGrid(double const &step, double const height, double const width, QColor col);
    ~GVGrid();
    void draw(QGraphicsScene *scene);
    void setRect(qreal const width, qreal const height);


    void store(QDataStream &stream);
    void restore(QDataStream &stream);

    bool compare(const GVGrid &obj);


    double getStep() const;
    void setStep(double value);

    qreal getHeight() const;
    void setHeight(const qreal &value);

    qreal getWidth() const;
    void setWidth(const qreal &value);

private:
    double step;
    qreal height = 100;
    qreal width = 100;
    QColor color = Qt::black;
};

#endif // GVGRID_H
