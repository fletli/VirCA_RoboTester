#include "QtRoboTester.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtRoboTester w;
	w.show();
	return a.exec();
}
