#include "LifeScene.h"

#include "Storage.h"

#include <QtMath>

#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QGraphicsSceneMouseEvent>

LifeScene::LifeScene( QObject * parent ):
	QGraphicsScene( parent )
{
	_gameField = theStorage.getFieldSize();
	_cellSize = theStorage.getCellSize();
	setSceneRect( 0, 0, _gameField.width() * _cellSize, _gameField.height() * _cellSize );

	_currentStep = QVector<QVector<QGraphicsRectItem*> > ( _gameField.height(), QVector<QGraphicsRectItem*> ( _gameField.width(), nullptr ) );
	_nextStep = QVector<QVector<bool> > ( _gameField.height(), QVector<bool> ( _gameField.width(), false ) );
}

LifeScene::~LifeScene()
{

}

void LifeScene::locateCell( int x, int y )
{
	if ( _currentStep[y][x] != nullptr )
		return;

	QGraphicsRectItem * cell = new QGraphicsRectItem( x * _cellSize, y * _cellSize, _cellSize, _cellSize );
	cell->setBrush( QBrush( Qt::green ) );
	cell->setPen( QPen( Qt::green ) );

	addItem( cell );

	_currentStep[y][x] = cell;
}

void LifeScene::updateWorld()
{
	_nextStep = QVector<QVector<bool> > ( _gameField.height(), QVector<bool> ( _gameField.width(), false ) );
	int i, j;
	for ( i = 0; i < _gameField.height(); ++i )
		for ( j = 0; j < _gameField.width(); ++j ) {
			if ( _currentStep[i][j] != nullptr )
				_nextStep[i][j] = canLive( j, i );
			else
				_nextStep[i][j] = canBorn( j, i );
		}

	for ( i = 0; i < _gameField.height(); ++i )
		for ( j = 0; j < _gameField.width(); ++j ) {
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
	int left = x != 0 ?	( x - 1 ) % _gameField.width() : _gameField.width() - 1;
	int top = y != 0 ? ( y - 1 ) % _gameField.height() : _gameField.height() - 1;

	int count = 0;
	for ( int i = 0; i < 3; ++i )
		for ( int j = 0; j < 3; ++j ) {
			if ( _currentStep[(top + i) % _gameField.height()][(left + j) % _gameField.width()] != nullptr )
				count++;
		}
	return count == 3;
}

bool LifeScene::canLive( int x, int y )
{
	int left = x != 0 ?	( x - 1 ) % _gameField.width() : _gameField.width() - 1;
	int top = y != 0 ? ( y - 1 ) % _gameField.height() : _gameField.height() - 1;

	int count = 0;
	for ( int i = 0; i < 3; ++i )
		for ( int j = 0; j < 3; ++j ) {
			if ( _currentStep[(top + i) % _gameField.height()][(left + j) % _gameField.width()] != nullptr )
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
	if ( pos.x() < 0 || pos.x() >= _gameField.width() || pos.y() < 0 || pos.y() >= _gameField.height() )
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
