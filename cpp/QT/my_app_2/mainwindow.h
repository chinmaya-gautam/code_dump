#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class MainWindow:public QMainWindow{
	Q_OBJECT
public:
	MainWindow();

private:
	QPushButton *buttons[10];
	QLabel *labels[10];
	QTimer *timer;
	
 protected:
 	void resizeEvent(QResizeEvent *re);

 private slots:
 	void resetChildWidgets();

 signals:
 		void sizeChanged();
};
#endif
