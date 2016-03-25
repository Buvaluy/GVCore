#include "gvquarter.h"

GVQuarter::GVQuarter()
    :GVObject("GVQuarter")
{

}

GVQuarter::GVQuarter(const double height, const double width, QColor col, const QString nameX, const QString nameY)
    :GVObject("GVQuarter")
{
    this->height = height;
    this->width = width;
    this->color = col;
    this->nameX = nameX;
    this->nameY = nameY;
}

GVQuarter::~GVQuarter()
{
    delete(pX);
    delete(pY);
}

void GVQuarter::draw(QGraphicsScene *scene)
{
    QPen *pen = new QPen();
    QFont font;
    font.setItalic(true);
    font.setBold(true);
    pen->setColor(color);
    pen->setWidth(2);
    if(scene == NULL){
        throw GVExeption ("Error. In draw() GVQuarter scene == NULL");
    }
    scene->addLine(0, 1, 0, height*-1, *pen);
    scene->addLine(0, 1, width, 1, *pen);
    pX = new QGraphicsTextItem(this->getNameX());
    pX->setPos(width - nameX.size()*8, 0);
    pX->setFont(font);
    scene->addItem(pX);
    pY = new QGraphicsTextItem(this->getNameY());
    pY->setPos(-20, (height*-1) + nameY.size()*8);
    pY->setRotation(-90);
    pY->setFont(font);
    scene->addItem(pY);
    delete(pen);
}

void GVQuarter::setRect(const qreal width, const qreal height)
{
    this->width = width;
    this->height = height;
}

void GVQuarter::store(QDataStream &stream)
{
    stream << this->getObjectName();
    stream << width;
    stream << height;
    stream << color.name();//или color.colorNames();
}

void GVQuarter::restore(QDataStream &stream)
{
    if(!chakedSerializationLabel(stream))
    {
        throw GVExeption ("Error lable restore grid");
    }
    QString colorTemp;
    stream >> width;
    stream >> height;
    stream >> colorTemp;
    color.setNamedColor(colorTemp);
}

bool GVQuarter::compare(const GVQuarter &obj)
{
    return height == obj.height && width == obj.width && color == obj.color;
}

qreal GVQuarter::getHeight() const
{
    return height;
}

void GVQuarter::setHeight(const qreal &value)
{
    this->height = value;
}

qreal GVQuarter::getWidth() const
{
    return width;
}

void GVQuarter::setWidth(const qreal &value)
{
    this->width = value;
}

QString GVQuarter::getNameX() const
{
    return nameX;
}

void GVQuarter::setNameX(const QString nameX)
{
    this->nameX = nameX;
}

QString GVQuarter::getNameY() const
{
    return nameY;
}

void GVQuarter::setNameY(const QString nameY)
{
    this->nameY = nameY;
}

