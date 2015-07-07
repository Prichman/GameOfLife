#pragma once

#include <QtCore/QSize>

#include <QtGui/QColor>

#define theStorage Storage::getInstance()

class Storage
{
public:
	static Storage & getInstance();

	inline const QSize &	getFieldSize()	{ return _fieldSize; }
	inline void				setFieldSize( const QSize & s ) { _fieldSize = s; }
	inline int				getCellSize()	{ return _cellSize; }
	inline void				setCellSize( int w ) { _cellSize = w; }


protected:
	Storage();
	static Storage * _storage;

private:
	QSize	_fieldSize;
	int		_cellSize;
	QColor	_cellColor;
	QColor	_backgroundColor;
	bool	_multiColored;
};
