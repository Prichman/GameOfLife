#include "HudManager.h"

#include "MainWindow.h"
#include "MenuLabel.h"
#include "SettingsMenu.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>

HudManager::HudManager( QObject * parent ):
	QObject( parent )
{
	_prevState = "";
}

HudManager::~HudManager()
{

}

void HudManager::loadState( const QString & state )
{
	if ( state == QString( "Menu" ) ) {
		createMenu();
	}
	else if ( state == QString( "Settings" ) ) {
		SettingsMenu * settings = new SettingsMenu;
		// connect( settings, &SettingsMenu::SOMESIGNAL, this, &HudManager::loadMenu );
		_mainWindow->setCentralWidget( settings );
	}
	else if ( state == QString( "Start" ) ) {
		_mainWindow->setMaximumSize( 1300, 820 );
		_mainWindow->resize( 1300, 820 );
		_mainWindow->startNewGame();

	}

	QRect rect = qApp->desktop()->rect();
	_mainWindow->move( (rect.width() - _mainWindow->width()) / 2, (rect.height() - _mainWindow->height()) / 2 );
}

void HudManager::setMainWindow( MainWindow * window )
{
	_mainWindow = window;
	connect( _mainWindow, &MainWindow::needForMenu, this, &HudManager::loadMenu );
	loadState( "Menu" );
}

void HudManager::startGame()
{
	loadState( "Start" );
}

void HudManager::loadSettings()
{
	loadState( "Settings" );
}

void HudManager::loadMenu()
{
	loadState( "Menu" );
}

void HudManager::createMenu()
{
	MenuLabel * mainMenu = new MenuLabel;
	connect( mainMenu, &MenuLabel::startButtonPressed, this, &HudManager::startGame );
	connect( mainMenu, &MenuLabel::settingButtonPressed, this, &HudManager::loadSettings );

	_mainWindow->setCentralWidget( mainMenu );
	_mainWindow->setFixedSize( mainMenu->size() );
}
