#include "MainWindow.h"

#include "MenuLabel.h"

#include "HudManager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	HudManager * manager = new HudManager;

	 MainWindow * w = new MainWindow;
	manager->setMainWindow( w );
	// MenuLabel w;

	w->show();

	return a.exec();
}
