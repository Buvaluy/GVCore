#ifndef GVOBJECT_H
#define GVOBJECT_H

#include <QDataStream>
#include <QString>
#include "gvexeption.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class QDataStream;
class QString;
class GVExeption;
class QGraphicsScene;

class GVObject
{
public:
    GVObject();
    GVObject(QString str);
    virtual ~GVObject();

    virtual void store(QDataStream &stream);
    virtual void restore(QDataStream &stream);

    virtual bool compareX(const GVObject &obj);
    virtual bool compareY(const GVObject &obj);
    virtual bool compare(const GVObject &obj);

    virtual void draw(QGraphicsScene *scene);

    QString getObjectName() const;
    void setObjectName(const QString &str);

    bool chakedSerializationLabel(QDataStream &stream);

protected:
    QString objectName;
};

#endif // GVOBJECT_H
