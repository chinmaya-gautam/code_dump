#include <QApplication>
#include <QLabel>

int main(int argc, char **argv){
	QApplication app(argc, argv);
	QLabel *label = new QLabel("<center><h2><i>Hello</i><font color=red> Qt!</font></h2></center>");
	label->show();
	return app.exec();
}