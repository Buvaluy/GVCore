#ifndef GVQUARTER_H
#define GVQUARTER_H

#include "gvobject.h"

class GVQuarter : public GVObject
{
public:
    GVQuarter();
    GVQuarter(double const height, double const width, QColor col, const QString nameX, const QString nameY);
    ~GVQuarter();

    void draw(QGraphicsScene *scene);
    void setRect(qreal const width, qreal const height);

    void store(QDataStream &stream);
    void restore(QDataStream &stream);

    bool compare(const GVQuarter &obj);

    qreal getHeight() const;
    void setHeight(const qreal &value);

    qreal getWidth() const;
    void setWidth(const qreal &value);

    QString getNameX() const;
    void setNameX(const QString nameX);

    QString getNameY() const;
    void setNameY(const QString nameY);

private:
    QString nameX = "x";
    QString nameY = "y";
    qreal height = 100;
    qreal width = 100;
    QColor color = Qt::black;
    QGraphicsTextItem *pX, *pY;
};

#endif // GVQUARTER_H
