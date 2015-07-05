#pragma once
#ifndef ROBOTESTERRTC_H
#define ROBOTESTERRTC_H


#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

using namespace RTC;
class RoboTesterRTC : public RTC::DataFlowComponentBase
{
public:

	RoboTesterRTC(RTC::Manager* manager);
	~RoboTesterRTC();
	static void RoboTesterRTCInit(RTC::Manager* manager);

	virtual RTC::ReturnCode_t onInitialize();
	virtual RTC::ReturnCode_t onFinalize(RTC::UniqueId ec_id);

	virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);
	virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

	virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

	RTC::TimedFloatSeq mJointsOut;
	RTC::OutPort<RTC::TimedFloatSeq> _mJointsOut;

private:
	

};

#endif