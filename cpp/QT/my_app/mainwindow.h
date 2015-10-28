#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStatusBar;

class MainWindow : public QMainWindow{
	
public:
	MainWindow(QWidget *parent=0);	
	
private:
	QStatusBar *statusBar;
};
#endif