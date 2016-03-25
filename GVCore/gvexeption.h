#ifndef GVEXEPTION_H
#define GVEXEPTION_H

#include <QString>

class QString;

class GVExeption
{
public:
    GVExeption(QString strMessageExaption);

    inline QString getError() const { return strMessageExp; }
    void showErrorMessageBox();
private:
    QString strMessageExp;
};

#endif // GVEXEPTION_H
