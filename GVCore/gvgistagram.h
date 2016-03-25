#ifndef GVGISTAGRAM_H
#define GVGISTAGRAM_H

#include "gvobject.h"
#include "GVCore/gvgistragramitem.h"
#include "gvgrid.h"

class GVGistagram : public GVObject
{
public:
    GVGistagram();
    GVGistagram(QList<GVGistragramItem *> &list);
    ~GVGistagram();

    void addGistoItem(GVGistragramItem *gisto);

    void draw(QGraphicsScene *scene);
    void drawWithMaxValue(QGraphicsScene *scene);
    void store(QDataStream &stream);
    void restore(QDataStream &stream);
    bool compare(GVGistagram &obj);
    int getSizeList();

    void setMaxValue(const double value);
    double getMaxValue() const;

private:
    QList<GVGistragramItem *> listGistoItems;
    QList<QGraphicsTextItem *> listTextItem;
    double maxValue = 0;
};

#endif // GVGISTAGRAM_H
