#include "gvexeption.h"
#include <QMessageBox>

GVExeption::GVExeption(QString strMessageExaption)
    : strMessageExp(strMessageExaption)
{

}

void GVExeption::showErrorMessageBox()
{
    QMessageBox::warning(NULL, "Error", strMessageExp);
}
