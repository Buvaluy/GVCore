#ifndef GVGISTRAGRAMITEM_H
#define GVGISTRAGRAMITEM_H

#include"gvobject.h"

class GVGistragramItem : public GVObject
{
public:
    GVGistragramItem();
    GVGistragramItem(const QString name, const qreal value, const QColor color);
    ~GVGistragramItem();

     void store(QDataStream &stream);
     void restore(QDataStream &stream);

     bool compare(const GVGistragramItem &obj);

     void setNameItem(const QString name);
     void setValue(const qreal value);
     void setColor(const QColor color);
     void setWidth(const qreal width);
     void setHeight(const qreal height);
     void setX(const qreal x);
     void setY(const qreal y);

     QString getNameItem() const;
     QColor getColorItem() const;
     qreal getValue() const;
     qreal getX() const;
     qreal getY() const;
     qreal getHeight() const;
     qreal getWidth() const;

private:
    QString nameItem;
    QColor colorItem = Qt::gray;
    qreal value = 0;
    qreal x;
    qreal y;
    qreal height;
    qreal width;
};

#endif // GVGISTRAGRAMITEM_H
