#pragma once

#include <QtWidgets/QLabel>

class MenuItem;

class MenuLabel : public QLabel
{
	Q_OBJECT

public:
	MenuLabel( QWidget * parent = 0 );
	~MenuLabel();

	MenuItem * _startButton;
	MenuItem * _settingsButton;
	MenuItem * _exitButton;

signals:
	void startButtonPressed();
	void settingButtonPressed();
};
