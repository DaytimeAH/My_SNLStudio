#include "myis_editor.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    myis_editor w;
    w.show();

    return a.exec();
}

