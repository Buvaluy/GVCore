#include "gvgrid.h"

GVGrid::GVGrid()
    :GVObject("Grid")
{

}

GVGrid::GVGrid(double const &step,
               double const height, double const width, QColor col)
    :GVObject("Grid")
{
    if(step <= 0 || height <= 0 || width <= 0){
        throw GVExeption ("Error. step or height or width <= 0");
    }
    this->step = step;
    this->height = height;
    this->width = width;
    color = col;
}

GVGrid::~GVGrid()
{

}

void GVGrid::draw(QGraphicsScene *scene)
{
    if(scene == NULL){
        throw GVExeption ("Error. In draw() scene == NULL");
    }
    int countRow = height / step;
    int countCol = width / step;
    for(int i = 0 ; i < countRow+2 ; i++ ){
        scene->addLine(0, i*step * -1, width, i*step * -1, QPen(color));
    }
    for( int i = 0 ; i < countCol+1 ; i++){
        scene->addLine(i*step, 0, i*step, height * -1, QPen(color));
    }
}

void GVGrid::setRect(const qreal width, const qreal height){
    this->width = width;
    this->height = height;
}

void GVGrid::store(QDataStream &stream)
{
    stream << this->getObjectName();
    stream << step;
    stream << width;
    stream << height;
    stream << color.name();//или color.colorNames();
}

void GVGrid::restore(QDataStream &stream)
{
    if(!chakedSerializationLabel(stream))
    {
        throw GVExeption ("Error lable restore grid");
    }
    QString colorTemp;
    stream >> step;
    stream >> width;
    stream >> height;
    stream >> colorTemp;
    color.setNamedColor(colorTemp);
}

bool GVGrid::compare(const GVGrid &obj)
{
    return height == obj.height && width == obj.width &&
            step == obj.step && color == obj.color;
}

double GVGrid::getStep() const
{
    return step;
}

void GVGrid::setStep(double value)
{
    step = value;
}

qreal GVGrid::getHeight() const
{
    return height;
}

void GVGrid::setHeight(const qreal &value)
{
    height = value;
}

qreal GVGrid::getWidth() const
{
    return width;
}

void GVGrid::setWidth(const qreal &value)
{
    width = value;
}
