#include "MenuLabel.h"

#include "MenuItem.h"

#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>

MenuLabel::MenuLabel( QWidget * parent ):
	QLabel( parent )
{
	setPixmap( QPixmap( ":/pictures/StartingMenu.png" ) );
	resize( pixmap()->size() );

	_startButton = new MenuItem( this );
	_startButton->loadLabel( ":/pictures/Start.png" );
	_startButton->move( 100, 100 );
	connect( _startButton, &MenuItem::clicked, this, &MenuLabel::startButtonPressed );

	_settingsButton = new MenuItem( this );
	_settingsButton->loadLabel( ":/pictures/Settings.png" );
	_settingsButton->move( _startButton->x() - 40, _startButton->y() + _startButton->height() + 5 );
	connect( _settingsButton, &MenuItem::clicked, this, &MenuLabel::settingButtonPressed );

	_exitButton = new MenuItem( this );
	_exitButton->loadLabel( ":/pictures/Exit.png" );
	_exitButton->move( _startButton->x() + 23, _settingsButton->y() + _settingsButton->height() -2 );
	connect( _exitButton, &MenuItem::clicked, qApp, &QApplication::quit );
}

MenuLabel::~MenuLabel()
{

}

