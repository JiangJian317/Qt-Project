//#include "stdafx.h"
#include "LSMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LSMainWindow w;
	w.show();
	return a.exec();
}
