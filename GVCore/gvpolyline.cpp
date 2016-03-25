#include "gvpolyline.h"

GVPolyLine::GVPolyLine()
    :GVObject("PolyLine")
{

}

GVPolyLine::GVPolyLine(QList<GVPoint *> &listPoint, QColor colorLine)
    :GVObject("PolyLine")
{
    this->listPoint = listPoint;
    this->colorLine = colorLine;
}

GVPolyLine::~GVPolyLine()
{
    qDeleteAll(listPoint);
    listPoint.clear();
}

void GVPolyLine::addPoint(GVPoint *point)
{
    listPoint.append(point);
}

void GVPolyLine::removePoint(GVPoint *point)
{
    listPoint.removeOne(point);
}

int GVPolyLine::countPoint() const
{
    return listPoint.size();
}

GVPoint *GVPolyLine::getPoint(int index)
{
    return this->listPoint.at(index);
}

void GVPolyLine::draw(QGraphicsScene *scene)
{
    if(scene == NULL)
        throw GVExeption("NULL scene draw");

    for(int i = 0; i < listPoint.size() - 1; i ++)
    {
        GVPoint *stP = listPoint.at(i);
        GVPoint *endP = listPoint.at(i + 1);
        scene->addLine(stP->getX(), stP->getY(),
                       endP->getX(), endP->getY(), QPen(colorLine));
    }
}

void GVPolyLine::store(QDataStream &stream)
{
    stream << objectName;
    stream << listPoint.size();
    for(int i = 0; i < listPoint.size(); i ++)
    {
        listPoint.at(i)->store(stream);
    }
}

void GVPolyLine::restore(QDataStream &stream)
{
    if(!chakedSerializationLabel(stream))
    {
        throw GVExeption ("Error lable restore polyLine");
    }

    qDeleteAll(listPoint);
    listPoint.clear();

    int countPiont;
    stream >> countPiont;

    for(int i = 0; i < countPiont; i ++)
    {
       GVPoint *pNewPoint = new GVPoint();
       try
       {
            pNewPoint->restore(stream);
       }
       catch(const GVExeption &exp)
       {
            throw GVExeption("Erorr restor polyLine");
       }
       this->listPoint.append(pNewPoint);
    }

}

bool GVPolyLine::compare(GVPolyLine &obj)
{
    if(obj.countPoint() != this->countPoint()) return false;

    for(int i = 0; i < listPoint.size(); i ++)
    {
        GVPoint *pCmp = getPoint(i), *pCmpObj = obj.getPoint(i);
        if(! pCmp->compare(*pCmpObj)) return false;
    }

    return true;
}

QColor GVPolyLine::getColorLine() const
{
    return colorLine;
}

void GVPolyLine::setColorLine(const QColor &value)
{
    colorLine = value;
}


