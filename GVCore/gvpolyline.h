#ifndef GVPOLYLINE_H
#define GVPOLYLINE_H

#include "gvobject.h"
#include "gvpoint.h"

#include <QList>

class GVPolyLine : public GVObject
{
public:
    GVPolyLine();
    GVPolyLine(QList<GVPoint *> &listPoint, QColor colorLine = Qt::blue);
    ~GVPolyLine();

    void addPoint(GVPoint *point);
    void removePoint(GVPoint *point);
    int countPoint() const;
    GVPoint *getPoint(int index);//почему указательная функция?

    void draw(QGraphicsScene *scene);
    void store(QDataStream &stream);
    void restore(QDataStream &stream);
    bool compare(GVPolyLine &obj);

    QColor getColorLine() const;
    void setColorLine(const QColor &value);



private:
    QList<GVPoint *> listPoint;
    QColor colorLine;
};

#endif // GVPOLYLINE_H
