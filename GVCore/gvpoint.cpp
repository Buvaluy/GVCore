#include "gvpoint.h"

GVPoint::GVPoint()
    :GVObject("Point")
{

}

GVPoint::GVPoint(qreal x, qreal y)
    :GVObject("Point")
{
    this->x = x;
    this->y = y * -1;
}

GVPoint::~GVPoint()
{

}

bool GVPoint::compareX(const GVPoint &obj)
{
    return this->x == obj.x;
}

bool GVPoint::compareY(const GVPoint &obj)
{
    return this->y == obj.y;
}

bool GVPoint::compare(const GVPoint &obj)
{
    return y == obj.y && x == obj.x;
}

void GVPoint::setX(const qreal &x){
    this->x = x;
}

void GVPoint::setY(const qreal &y){
    this->y = y * -1;
}

qreal GVPoint::getX() const{
    return this->x;
}

qreal GVPoint::getY() const{
    return this->y;
}

void GVPoint::store(QDataStream &stream)
{
    stream << this->getObjectName();
    stream << this->x;
    stream << this->y;
}

void GVPoint::restore(QDataStream &stream)
{
    if(!chakedSerializationLabel(stream))
    {
        throw GVExeption ("Error lable restore point");
    }
    stream >> this->x;
    stream >> this->y;
}
