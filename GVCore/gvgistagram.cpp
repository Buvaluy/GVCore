#include "gvgistagram.h"

GVGistagram::GVGistagram()
    :GVObject("GVGistagram")
{

}

GVGistagram::GVGistagram(QList<GVGistragramItem *> &list)
    :GVObject("GVGistagram")
{
    listGistoItems = list;
}

GVGistagram::~GVGistagram()
{
    qDeleteAll(listGistoItems);
    listGistoItems.clear();
    qDeleteAll(listTextItem);
    listTextItem.clear();
}

void GVGistagram::addGistoItem(GVGistragramItem *gisto)
{
    listGistoItems.append(gisto);
}

void GVGistagram::draw(QGraphicsScene *scene)
{
    if(scene == NULL)
        throw GVExeption("NULL scene draw for poligon");

    int sizeList = listGistoItems.size();
    qreal widthScene = scene->width();
    qreal heightScene = scene->height();
    GVGrid *grid = new GVGrid(heightScene / 10, heightScene, widthScene, QColor("#eee"));
    grid->draw(scene);
    int max = 0;
    int indexMax = 0;
    for(int i = 0; i < sizeList; i++){
        if(listGistoItems.at(i)->getValue() > max){
            max = listGistoItems.at(i)->getValue();
            indexMax = i;
        }
        listGistoItems.at(i)->setWidth(widthScene/sizeList - widthScene/15);
    }

    for(int i = 0; i < listGistoItems.size(); i++){
        if(i != indexMax){
            listGistoItems.at(i)->setHeight(listGistoItems.at(i)->getValue() / max * heightScene);
            listGistoItems.at(i)->setX(i * ((widthScene-15)/sizeList) + 10);
            listGistoItems.at(i)->setY(-1);
        }else{
            listGistoItems.at(i)->setHeight(heightScene);
            listGistoItems.at(i)->setX(i * ((widthScene-15)/sizeList) + 10);
            listGistoItems.at(i)->setY(-1);
        }
        QGraphicsTextItem *textItem = new QGraphicsTextItem(QString::number(listGistoItems.at(i)->getValue()));
        listTextItem.append(textItem);
        textItem->setPos(listGistoItems.at(i)->getX(), listGistoItems.at(i)->getY() + 10);
        scene->addItem(textItem);
    }

     for(int i = 0; i < listGistoItems.size(); i++){
         scene->addRect(listGistoItems.at(i)->getX(), listGistoItems.at(i)->getY(),
                        listGistoItems.at(i)->getWidth(), listGistoItems.at(i)->getHeight()*-1,
                        QPen(listGistoItems.at(i)->getColorItem()), QBrush(listGistoItems.at(i)->getColorItem()));

         QGraphicsTextItem *textItem = new QGraphicsTextItem(listGistoItems.at(i)->getNameItem());
         listTextItem.append(textItem);
         textItem->setPos(listGistoItems.at(i)->getX(), listGistoItems.at(i)->getY());
         scene->addItem(textItem);
     }
}

void GVGistagram::drawWithMaxValue(QGraphicsScene *scene)
{
    if(scene == NULL)
        throw GVExeption("NULL scene draw for poligon");
    if(0 >= maxValue)
        throw GVExeption("maxValue <=0 drawWithMaxValue()");
    int sizeList = listGistoItems.size();
    qreal widthScene = scene->width();
    qreal heightScene = scene->height();
    GVGrid *grid = new GVGrid(heightScene / 10, heightScene, widthScene, QColor("#eee"));
    grid->draw(scene);
    for(int i = 0; i < sizeList; i++){
        listGistoItems.at(i)->setWidth(widthScene/sizeList - widthScene/15);
    }

    for(int i = 0; i < listGistoItems.size(); i++){
        listGistoItems.at(i)->setHeight(listGistoItems.at(i)->getValue() / maxValue * heightScene);
        listGistoItems.at(i)->setX(i * ((widthScene-15)/sizeList) + 10);
        listGistoItems.at(i)->setY(-1);
        QGraphicsTextItem *textItem = new QGraphicsTextItem(QString::number(listGistoItems.at(i)->getValue() / maxValue * 100) + "%");
        listTextItem.append(textItem);
        textItem->setPos(listGistoItems.at(i)->getX(), listGistoItems.at(i)->getY() + 10);
        scene->addItem(textItem);
    }

     for(int i = 0; i < listGistoItems.size(); i++){
         scene->addRect(listGistoItems.at(i)->getX(), listGistoItems.at(i)->getY(),
                        listGistoItems.at(i)->getWidth(), listGistoItems.at(i)->getHeight()*-1,
                        QPen(listGistoItems.at(i)->getColorItem()), QBrush(listGistoItems.at(i)->getColorItem()));

         QGraphicsTextItem *textItem = new QGraphicsTextItem(listGistoItems.at(i)->getNameItem());
         listTextItem.append(textItem);
         textItem->setPos(listGistoItems.at(i)->getX(), listGistoItems.at(i)->getY());
         scene->addItem(textItem);
     }


}

void GVGistagram::store(QDataStream &stream)
{
    stream << objectName;
    stream << listGistoItems.size();
    for(int i = 0; i < listGistoItems.size(); i++){
        stream << listGistoItems.at(i); ////////////проверь на правельность
    }
}

void GVGistagram::restore(QDataStream &stream)
{
    if(!chakedSerializationLabel(stream))
    {
        throw GVExeption ("Error lable restore polyLine");
    }

    qDeleteAll(listGistoItems);
    listGistoItems.clear();

    int countGistoItem;
    stream >> countGistoItem;
    for(int i = 0; i < countGistoItem; i ++)
    {
       GVGistragramItem *pNewGistItem = new GVGistragramItem();
       try
       {
           //GVGistragramItem temp;
           //stream >> temp;
           //pNewGistItem = temp;   ///Не смог сделать востав.
       }
       catch(const GVExeption &exp)
       {
            throw GVExeption("Erorr restor Gisto");
       }
       this->listGistoItems.append(pNewGistItem);
    }

}

bool GVGistagram::compare(GVGistagram &obj)
{
    if(obj.getSizeList() != this->getSizeList()) return false;

    for(int i = 0; i < listGistoItems.size(); i ++)
    {
        /*
        if(!this->listGistoItems.at(i)->compare(obj.listGistoItems.at(i))){
            return false;
        }
        */      //проверь
    }

    return true;
}

int GVGistagram::getSizeList()
{
    return listGistoItems.size();
}

void GVGistagram::setMaxValue(const double value)
{
    this->maxValue = value;
}

double GVGistagram::getMaxValue() const
{
    return this->maxValue;
}

