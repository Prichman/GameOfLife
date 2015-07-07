#pragma once

#include <QtWidgets/QGraphicsScene>

class QGraphicsRectItem;

class LifeScene : public QGraphicsScene
{
	Q_OBJECT

public:
	LifeScene( QObject * parent = 0 );
	~LifeScene();

	void locateCell( int x, int y );
	void updateWorld();

	bool canBorn( int x, int y );
	bool canLive( int x, int y );

protected:
	virtual void mousePressEvent( QGraphicsSceneMouseEvent * event );

private:
	QVector<QVector<QGraphicsRectItem*> > _currentStep;
	QVector<QVector<bool> > _nextStep;

	QSize	_gameField;
	int		_cellSize;

signals:
	void stepDone();
};
