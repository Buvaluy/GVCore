#ifndef GVPOINT_H
#define GVPOINT_H

#include <QtGlobal>
#include "gvobject.h"

class GVPoint : public GVObject
{
public:
    GVPoint();
    GVPoint(qreal x, qreal y);
    ~GVPoint();

    void store(QDataStream &stream);
    void restore(QDataStream &stream);

    bool compareX(const GVPoint &obj);
    bool compareY(const GVPoint &obj);
    bool compare(const GVPoint &obj);

    void setX(const qreal &x);
    void setY(const qreal &y);
    qreal getX() const;
    qreal getY() const;

protected:
    qreal x;
    qreal y;
};

#endif // GVPOINT_H
