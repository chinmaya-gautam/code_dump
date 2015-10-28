#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow():QMainWindow(){
	//set dimentions
	setGeometry(50,50,600,300);
	//setup buttons and labels;
	for(int i=0;i<10;i++){
		buttons[i] = new QPushButton(tr("button %1").arg(i),this);
		buttons[i]->setGeometry(20,25*(i+1),50,20);
		labels[i] = new QLabel(tr("label %1").arg(i),this);
		labels[i]->setGeometry(100,25*(i+1),50,20);
	}
	timer = new QTimer;
	timer->start(0.05*1000);
	//connect(timer,SIGNAL(timeout()),this,SLOT(resetChildWidgets()));
	connect(this,SIGNAL(sizeChanged()),this,SLOT(resetChildWidgets()));
}

void MainWindow::resetChildWidgets(){
	qDebug()<<"resized"<<this->width()<<this->height();
	int width = this->width();
	int height = this->height();
	float xoffset_m = (1.0/600)*width;
	float yoffset_m = (1.0/300)*height;
	for(int i=0;i<10;i++){
		buttons[i]->setGeometry((int)20*xoffset_m,(int)25*(i+1)*yoffset_m,(int)50*xoffset_m,(int)20*yoffset_m);
		labels[i]->setGeometry((int)100*xoffset_m,(int)25*(i+1)*yoffset_m,(int)50*xoffset_m,(int)20*yoffset_m);;
	}
	
}

void MainWindow::resizeEvent(QResizeEvent *re){
	emit sizeChanged();
	
}