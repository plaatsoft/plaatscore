#include <QtGui/QApplication>
#include "highscore.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HighScore w;
    w.show();
    return a.exec();
}
