#include "rightshowdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rightshowdialog w;
    w.show();

    return a.exec();
}
