#include "gvobject.h"
GVObject::GVObject()
{

}

GVObject::GVObject(QString str)
    : objectName(str)
{

}

GVObject::~GVObject()
{

}

void GVObject::store(QDataStream &stream)
{
    stream << objectName;
}

void GVObject::restore(QDataStream &stream)
{
    stream >> objectName;
}

bool GVObject::compareX(const GVObject &obj)
{
    return objectName == obj.getObjectName();
}

bool GVObject::compareY(const GVObject &obj)
{
    return objectName == obj.getObjectName();
}

bool GVObject::compare(const GVObject &obj)
{
    return objectName == obj.getObjectName();
}

void GVObject::draw(QGraphicsScene *scene)
{

}

QString GVObject::getObjectName() const
{
    return objectName;
}

void GVObject::setObjectName(const QString &str)
{
    objectName = str;
}

bool GVObject::chakedSerializationLabel(QDataStream &stream)
{
    QString strObjectName;
    stream >> strObjectName;
    return strObjectName == this->objectName;
}
