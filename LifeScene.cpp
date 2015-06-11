#include "LifeScene.h"

#include <QtMath>

#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QGraphicsSceneMouseEvent>

const int CELL_SIZE = 10;

LifeScene::LifeScene( QObject * parent ):
	QGraphicsScene( parent )
{
	setSceneRect( 0, 0, GAME_FIELD.width() * CELL_SIZE, GAME_FIELD.height() * CELL_SIZE );

	_currentStep = QVector<QVector<QGraphicsRectItem*> > ( GAME_FIELD.height(), QVector<QGraphicsRectItem*> ( GAME_FIELD.width(), nullptr ) );
	_nextStep = QVector<QVector<bool> > ( GAME_FIELD.height(), QVector<bool> ( GAME_FIELD.width(), false ) );
}

LifeScene::~LifeScene()
{

}

void LifeScene::locateCell( int x, int y )
{
	if ( _currentStep[y][x] != nullptr )
		return;

	QGraphicsRectItem * cell = new QGraphicsRectItem( x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE );
	cell->setBrush( QBrush( Qt::green ) );
	cell->setPen( QPen( Qt::green ) );

	addItem( cell );

	_currentStep[y][x] = cell;
}

void LifeScene::updateWorld()
{
	_nextStep = QVector<QVector<bool> > ( GAME_FIELD.height(), QVector<bool> ( GAME_FIELD.width(), false ) );
	int i, j;
	for ( i = 0; i < GAME_FIELD.height(); ++i )
		for ( j = 0; j < GAME_FIELD.width(); ++j ) {
			if ( _currentStep[i][j] != nullptr )
				_nextStep[i][j] = canLive( j, i );
			else
				_nextStep[i][j] = canBorn( j, i );
		}

	for ( i = 0; i < GAME_FIELD.height(); ++i )
		for ( j = 0; j < GAME_FIELD.width(); ++j ) {
			if ( _currentStep[i][j] != nullptr && !_nextStep[i][j] ) {
				removeItem( _currentStep[i][j] );
				delete _currentStep[i][j];
				_currentStep[i][j] = nullptr;
			}
			else if ( _currentStep[i][j] == nullptr && _nextStep[i][j] )
				locateCell( j, i );
		}

	update();
	emit stepDone();
}

bool LifeScene::canBorn( int x, int y )
{
	int left = x != 0 ?	( x - 1 ) % GAME_FIELD.width() : GAME_FIELD.width() - 1;
	int top = y != 0 ? ( y - 1 ) % GAME_FIELD.height() : GAME_FIELD.height() - 1;

	int count = 0;
	for ( int i = 0; i < 3; ++i )
		for ( int j = 0; j < 3; ++j ) {
			if ( _currentStep[(top + i) % GAME_FIELD.height()][(left + j) % GAME_FIELD.width()] != nullptr )
				count++;
		}
	return count == 3;
}

bool LifeScene::canLive( int x, int y )
{
	int left = x != 0 ?	( x - 1 ) % GAME_FIELD.width() : GAME_FIELD.width() - 1;
	int top = y != 0 ? ( y - 1 ) % GAME_FIELD.height() : GAME_FIELD.height() - 1;

	int count = 0;
	for ( int i = 0; i < 3; ++i )
		for ( int j = 0; j < 3; ++j ) {
			if ( _currentStep[(top + i) % GAME_FIELD.height()][(left + j) % GAME_FIELD.width()] != nullptr )
				count++;
		}
	count--;
	return ( count == 2 || count == 3 );
}

void LifeScene::mousePressEvent( QGraphicsSceneMouseEvent * event )
{
	QPointF p = event->scenePos();
	QPoint pos;
	pos.setX( qFloor( p.x() ) );
	pos.setY( qFloor( p.y() ) );
	pos.setX( pos.x() / 10 );
	pos.setY( pos.y() / 10 );
	if ( pos.x() < 0 || pos.x() >= GAME_FIELD.width() || pos.y() < 0 || pos.y() >= GAME_FIELD.height() )
		return;

	if ( _currentStep[pos.y()][pos.x()] == nullptr )
		locateCell( pos.x(), pos.y() );
	else {
		removeItem( _currentStep[pos.y()][pos.x()] );
		delete _currentStep[pos.y()][pos.x()];
		_currentStep[pos.y()][pos.x()] = nullptr;
	}

	update();
	emit stepDone();
}
