#pragma once
#ifndef QtRoboTester_H
#define QtRoboTester_H


#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <rtm/Manager.h>
#include "RoboTesterRTC.h"
#include "ui_QtRoboTester.h"


typedef struct Slider
{
	QSlider *slider;
	float min;
	float max;
}SLIDER;


class QtRoboTester : public QMainWindow
{
	Q_OBJECT

public:
	QtRoboTester(QWidget *parent = 0,  Qt::WindowFlags flags = 0);
	~QtRoboTester();
	static void MyModuleInit(RTC::Manager * manager);

	protected slots:
		void sendJoints();
		void Activate();
		void Deactivate();
		void ToggleOutputType();

private:
	Ui::QtRoboTesterClass ui;
	RTC::Manager * mgr;
	RoboTesterRTC * RTC;

	static const char DoF = 8;
	std::vector<SLIDER> Sliders;

   
	void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
	float ConversionRate;  //For runtime rad/deg change
};

#endif // QtRoboTester_H
