#pragma once

#include <QtWidgets/QWidget>

class QLabel;
class QPushButton;
class QComboBox;
class QLineEdit;
class QCheckBox;

class SettingsMenu : public QWidget
{
	Q_OBJECT

public:
	SettingsMenu( QWidget * parent = 0 );
	~SettingsMenu();

private:
	QLabel *	_settingsLabel;
	QLabel *	_cellSizeLabel;
	QComboBox * _cellSizeBox;

	QLabel *	_fieldWidthLabel;
	QComboBox * _fieldWidthBox;
	QLabel *	_fieldHeightLabel;
	QComboBox * _fieldHeightBox;

	QLabel  *	_cellColorLabel;
	QLineEdit * _cellColorLine;
	QLabel *	_backgroundColorLabel;
	QLineEdit * _backgroundColorLine;

	QLabel *	_multiColoredLabel;
	QCheckBox *	_multiColoredBox;

	QPushButton * _okButton;
	QPushButton * _cancelButton;
};
