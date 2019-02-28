#include "expediteur.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Expediteur w;
    w.show();

    return a.exec();
}
