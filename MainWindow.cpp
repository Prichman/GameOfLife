#include "MainWindow.h"

#include "LifeScene.h"

#include <QtCore/QTimer>

#include <QtGui/QKeyEvent>

#include <QtWidgets/QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	resize( 400, 300 );
}

MainWindow::~MainWindow()
{

}

void MainWindow::startNewGame()
{
	_gameTimer = new QTimer( this );

	_gameScene = new LifeScene( this );

	_gameView = new QGraphicsView( _gameScene, this );
	_gameView->setViewportUpdateMode( QGraphicsView::NoViewportUpdate );
	setCentralWidget( _gameView );

	_gameTimer->setInterval( 500 );
	connect( _gameTimer, &QTimer::timeout, _gameScene, &LifeScene::updateWorld );
	connect( _gameScene, &LifeScene::stepDone, this, &MainWindow::updateGame );
}

void MainWindow::updateGame()
{
	_gameView->update();
}

void MainWindow::keyPressEvent( QKeyEvent * event )
{
	switch ( event->key() ) {
		case Qt::Key_Space:
		{
			if ( _gameTimer->isActive() )
				_gameTimer->stop();
			else
				_gameTimer->start();
			break;
		}
		case Qt::Key_Plus:
		{
			if ( _gameTimer->interval() > 10 )
				_gameTimer->setInterval( _gameTimer->interval() - 20 );
			break;
		}
		case Qt::Key_Minus:
		{
			if ( _gameTimer->interval() < 800 )
				_gameTimer->setInterval( _gameTimer->interval() + 20 );
			break;
		}
		case Qt::Key_Escape:
		{
			_gameTimer->stop();
			emit needForMenu();
			break;
		}
	}

	QMainWindow::keyPressEvent( event );
}
