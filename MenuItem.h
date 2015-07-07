#pragma once

#include <QtWidgets/QLabel>

class MenuItem : public QLabel
{
	Q_OBJECT

public:
	MenuItem( QWidget * parent = 0 );
	~MenuItem();

	void loadLabel( const QString & path );

protected:
	virtual void mousePressEvent( QMouseEvent * event );

signals:
	void clicked();
};
