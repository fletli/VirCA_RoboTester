#include "QtRoboTester.h"

QtRoboTester::QtRoboTester(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	mgr = RTC::Manager::init(NULL, NULL);
	mgr->init(NULL, NULL);
	mgr->setModuleInitProc(&QtRoboTester::MyModuleInit);
	mgr->activateManager();
	mgr->runManager(true);
	this->RTC = static_cast<RoboTesterRTC*> (mgr->getComponent("RoboTester0"));
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
	

	ConversionRate=1;

	//Init Sliders vecotor
	Sliders.resize(DoF);
	for (int i=0; i<DoF; i++)
	{
		Sliders[i].min=-180;
		Sliders[i].max=180;
	}

	for (int i=0; i<DoF; i++)
	{
		QSlider *slider = new QSlider(Qt::Vertical);
		slider->setMinimum(Sliders[i].min);
		slider->setMaximum(Sliders[i].max);
		ui.horizontalLayout->addWidget(slider,0,0);
		QObject::connect(slider, &QSlider::valueChanged, this, &QtRoboTester::sendJoints);
		Sliders[i].slider=slider;
	}
}

QtRoboTester::~QtRoboTester()
{

}


void QtRoboTester::MyModuleInit(RTC::Manager * manager)
{
	RoboTesterRTC::RoboTesterRTCInit(manager);
	RTC::RtcBase * comp;
	comp = manager->createComponent("RoboTesterRTC");
	if (comp==NULL)
	{
		std::cerr << "Component creation failed." << std::endl;

	}
}

void QtRoboTester::mousePressEvent(QMouseEvent *me) {
	m_nMouseClick_X_Coordinate = me->x();
    m_nMouseClick_Y_Coordinate = me->y();
}
 
void QtRoboTester::mouseMoveEvent(QMouseEvent *me) {
    move(me->globalX()-m_nMouseClick_X_Coordinate,me->globalY()-m_nMouseClick_Y_Coordinate);
}



void QtRoboTester::Activate()
{

}

void QtRoboTester::Deactivate()
{

}

void QtRoboTester::ToggleOutputType()
{
	if (ui.radioButton_Deg->isChecked()==true)
	{
		ConversionRate=1;

	} else
	{
		ConversionRate=3.14159265358979323846f/180;
	}
}


void QtRoboTester::sendJoints()
{
	RTC::TimedFloatSeq q;
	q.data.length(DoF);
	std::cout << "Joint vector:";
	for (int i=0; i<DoF; i++)
	{
		q.data[i]=Sliders[i].slider->value()*ConversionRate; std::cout << "[" << (float)q.data[i] <<"] ";
	}
	std::cout << " is sent!" << std::endl;
	RTC->mJointsOut.data.length(DoF);
	memcpy(&(RTC->mJointsOut.data[0]), &q.data[0],sizeof(float)*DoF);
	RTC->_mJointsOut.write();
}

