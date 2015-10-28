#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]){
QApplication app(argc, argv);
MainWindow *main = new MainWindow;
main->show();
return app.exec();

}