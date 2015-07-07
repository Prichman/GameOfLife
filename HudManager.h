#pragma once

#include <QtCore/QObject>

class MainWindow;

class HudManager : public QObject
{
	Q_OBJECT

public:
	HudManager( QObject * parent = 0 );
	~HudManager();

	void loadState( const QString & state );
	void setMainWindow( MainWindow * window );

	void startGame();
	void loadSettings();
	void loadMenu();

private:
	QString			_prevState;
	MainWindow *	_mainWindow;

	void createMenu();
};
