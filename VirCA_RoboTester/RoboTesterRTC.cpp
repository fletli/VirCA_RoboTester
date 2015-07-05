/** @file
*	The RTM component class source.*/
#include "RoboTesterRTC.h"
#include <iostream>

using namespace std;
using namespace RTC;

// Module specification
static const char* robotester_spec[] =
  {
	  "implementation_id", "RoboTesterRTC",
	  "type_name",         "RoboTester",
	  "description",       "",
	  "version",           "1.0",
	  "vendor",            "GP",
	  "category",          "RoboTester",
	  "activity_type",     "PERIODIC",
	  "kind",              "DataFlowComponent",
	  "max_instance",      "1",
	  "language",          "C++",
	  "lang_type",         "compile",
	  ""
  };

RoboTesterRTC::RoboTesterRTC(RTC::Manager* manager)
: RTC::DataFlowComponentBase(manager), _mJointsOut( "JointsOut", mJointsOut )
{
	
}

RoboTesterRTC::~RoboTesterRTC()
{
	
}

RTC::ReturnCode_t RoboTesterRTC::onInitialize()
{
	// Set InPort buffers
	addOutPort( "JointsOut", _mJointsOut );

	//other member inits
	
	//bind config params
	//bindParameter( "name", paramVar, "def" );

	std::cout << "[RTM] [initialized]" << std::endl;
	return RTC::RTC_OK;
}

RTC::ReturnCode_t RoboTesterRTC::onFinalize( RTC::UniqueId ec_id )
{
	std::cout << "[RTM] [finalized]" << std::endl;
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RoboTesterRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RoboTesterRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

RTC::ReturnCode_t RoboTesterRTC::onActivated(RTC::UniqueId ec_id)
{
	mJointsOut.data.length(6);
	mJointsOut.data[0]=0;
	mJointsOut.data[1]=0;
	mJointsOut.data[2]=0;
	mJointsOut.data[3]=0;
	mJointsOut.data[4]=0;

	std::cout << "[RTM] [activated]" << std::endl;
	return RTC::RTC_OK;
}

RTC::ReturnCode_t RoboTesterRTC::onDeactivated(RTC::UniqueId ec_id)
{
	std::cout << "[RTM] [deactivated]" << std::endl;
	return RTC::RTC_OK;
}

RTC::ReturnCode_t RoboTesterRTC::onExecute(RTC::UniqueId ec_id)
{
//	std::cout << ".";
//	std::cout << "data:";
//	std::cout << "[" << (int)mJointsOut.data[0] <<"] ";
//	std::cout << "[" << (int)mJointsOut.data[1] <<"] ";
//	std::cout << "[" << (int)mJointsOut.data[2] <<"] ";
//	std::cout << "[" << (int)mJointsOut.data[3] <<"] ";
//	std::cout << "[" << (int)mJointsOut.data[4] <<"] ";
//	std::cout << " is sent!" << std::endl;
//	_mJointsOut.write();
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RoboTesterRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RoboTesterRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RoboTesterRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RoboTesterRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RoboTesterRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

void RoboTesterRTC::RoboTesterRTCInit(RTC::Manager* manager)
{
	coil::Properties profile(robotester_spec);
	manager->registerFactory(profile,
		RTC::Create<RoboTesterRTC>,
		RTC::Delete<RoboTesterRTC>);
}