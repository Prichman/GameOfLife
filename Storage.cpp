#include "Storage.h"

Storage * Storage::_storage = nullptr;

Storage & Storage::getInstance()
{
	if ( _storage == nullptr )
		_storage = new Storage;
	return *_storage;
}

Storage::Storage()
{
	_cellSize = 10;
	_fieldSize = QSize( 120, 80 );
	_cellColor = Qt::green;
	_backgroundColor = Qt::white;
	_multiColored = false;
}
