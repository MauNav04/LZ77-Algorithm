#include "src/ui/mainscreen.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainScreen screen;
    screen.show();
    return app.exec();
}