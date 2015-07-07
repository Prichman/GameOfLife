#include "MenuItem.h"

#include <QtGui/QMouseEvent>

MenuItem::MenuItem( QWidget * parent ):
	QLabel( parent )
{

}

MenuItem::~MenuItem()
{

}

void MenuItem::loadLabel( const QString & path )
{
	setPixmap( QPixmap( path ) );
	resize( pixmap()->size() );
}

void MenuItem::mousePressEvent( QMouseEvent * event )
{
	emit clicked();

	QLabel::mousePressEvent( event );
}

