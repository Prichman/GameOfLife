#pragma once

#include <QMainWindow>

class LifeScene;
class QGraphicsView;
class QTimer;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow( QWidget * parent = 0 );
	~MainWindow();

	void startNewGame();
	void updateGame();

protected:
	virtual void keyPressEvent( QKeyEvent * event );

private:
	LifeScene *			_gameScene;
	QGraphicsView *		_gameView;
	QTimer *			_gameTimer;

signals:
	void needForMenu();
};
