#include "gvgistragramitem.h"

GVGistragramItem::GVGistragramItem()
    :GVObject("GVGistragramItem")
{

}

GVGistragramItem::GVGistragramItem(const QString name, const qreal value, const QColor color)
    :GVObject("GVGistragramItem")
{
    this->nameItem = name;
    this->value = value;
    this->colorItem = color;
}

GVGistragramItem::~GVGistragramItem()
{

}

void GVGistragramItem::store(QDataStream &stream)
{
    stream << this->getObjectName();
    stream << nameItem;
    stream << value;
    stream << colorItem.name();
}

void GVGistragramItem::restore(QDataStream &stream)
{
    if(!chakedSerializationLabel(stream))
    {
        throw GVExeption ("Error lable restore point");
    }
    QString colorTemp;
    stream >> nameItem;
    stream >> value;
    stream >> colorTemp;
    colorItem.setNamedColor(colorTemp);
}

bool GVGistragramItem::compare(const GVGistragramItem &obj)
{
    if(nameItem == obj.nameItem && value == obj.value && colorItem == obj.value){
        return true;
    }else{
        return false;
    }
}

void GVGistragramItem::setNameItem(const QString name)
{
    this->nameItem = name;
}

void GVGistragramItem::setValue(const qreal value)
{
    this->value = value;
}

void GVGistragramItem::setColor(const QColor color)
{
    this->colorItem = color;
}

void GVGistragramItem::setWidth(const qreal width)
{
    this->width = width;
}

void GVGistragramItem::setHeight(const qreal height)
{
    this->height = height;
}

void GVGistragramItem::setX(const qreal x)
{
    this->x = x;
}

void GVGistragramItem::setY(const qreal y)
{
    this->y = y;
}

QString GVGistragramItem::getNameItem() const
{
    return nameItem;
}

qreal GVGistragramItem::getValue() const
{
    return value;
}

qreal GVGistragramItem::getX() const
{
    return x;
}

qreal GVGistragramItem::getY() const
{
    return y;
}

qreal GVGistragramItem::getHeight() const
{
    return height;
}

qreal GVGistragramItem::getWidth() const
{
    return width;
}

QColor GVGistragramItem::getColorItem() const
{
    return colorItem;
}

