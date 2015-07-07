#include "SettingsMenu.h"

#include "Storage.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>

SettingsMenu::SettingsMenu( QWidget * parent ):
	QWidget( parent )
{
	_settingsLabel = new QLabel( "Settings" );
	_settingsLabel->setAlignment( Qt::AlignCenter );
	_cellSizeLabel = new QLabel( "Cell size:" );
	_cellSizeBox = new QComboBox;
	int i;
	for ( i = 6; i < 15; ++i )
		_cellSizeBox->addItem( QString::number( i ) );

	_fieldWidthLabel = new QLabel( "Field width:");
	_fieldWidthBox = new QComboBox;
	for ( i = 40; i < 121; ++i )
		_fieldWidthBox->addItem( QString::number( i ) );

	_fieldHeightLabel = new QLabel( "Field height:" );
	_fieldHeightBox = new QComboBox;
	for ( i = 20; i < 81; ++i )
		_fieldHeightBox->addItem( QString::number( i ) );

	_cellColorLabel = new QLabel( "Cell color (HEX):");
	_cellColorLine = new QLineEdit;
	_backgroundColorLabel = new QLabel( "Background color (HEX):");
	_backgroundColorLine = new QLineEdit;

	_multiColoredLabel = new QLabel( "Multicolored:" );
	_multiColoredBox = new QCheckBox;

	_okButton = new QPushButton( "OK" );
	_cancelButton = new QPushButton( "Cancel" );


	QGridLayout * lyt = new QGridLayout;
	lyt->addWidget( _settingsLabel, 0, 0, 1, 3, Qt::AlignCenter );
	lyt->addWidget( _cellSizeLabel, 1, 0, 1, 1 );
	lyt->addWidget( _cellSizeBox, 1, 2, 1, 1 );
	lyt->addWidget( _fieldWidthLabel, 2, 0, 1, 1 );
	lyt->addWidget( _fieldWidthBox, 2, 2, 1, 1 );
	lyt->addWidget( _fieldHeightLabel, 3, 0, 1, 1 );
	lyt->addWidget( _fieldHeightBox, 3, 2, 1, 1 );
	lyt->addWidget( _cellColorLabel, 4, 0, 1, 1 );
	lyt->addWidget( _cellColorLine, 4, 2, 1, 1 );
	lyt->addWidget( _backgroundColorLabel, 5, 0, 1, 1 );
	lyt->addWidget( _backgroundColorLine, 5, 2, 1, 1 );
	lyt->addWidget( _multiColoredLabel, 6, 0, 1, 1 );
	lyt->addWidget( _multiColoredBox, 6, 2, 1, 1 );
	lyt->addWidget( _okButton, 8, 0, 1, 1 );
	lyt->addWidget( _cancelButton, 8, 2, 1, 1 );

	setLayout( lyt );

}

SettingsMenu::~SettingsMenu()
{

}

