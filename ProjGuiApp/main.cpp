#include "ProjGuiApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjGuiApp w;
    w.show();
    return a.exec();
}
