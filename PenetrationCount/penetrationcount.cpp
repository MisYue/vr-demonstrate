#include "penetrationcount.h"
#include <PowerAnalysisBase/WarheadPenetrationPower.h>
#include <MathCalculationSupport/UnitsTransform.h>
#include <MathCalculationSupport/AdvancedMath.h>

PenetrationCount::PenetrationCount()
{

}

PenetrationCount::~PenetrationCount()
{

}

bool PenetrationCount::CountOval(const PCPOval& pcp, double& vr, double& pd)
{
	vr = BIT::WarheadPenetrationPower::ComptOReminingVelocity(pcp.iv, pcp.wm, pcp.wd, pcp.oria, pcp.bt, pcp.ca);
	if(pcp.ca == 90)
		pd = pcp.bt;
	else
		pd = pcp.bt / cos(BIT::AdvancedMath::AngleToRadian(pcp.ca));
	if(vr < 0)
		pd /=2;
	return true;
}

bool PenetrationCount::CountSharp(const PCPSharp& pcp, double& vr, double& pd)
{
	vr = BIT::WarheadPenetrationPower::ComptCReminingVelocity(pcp.iv , pcp.wm , pcp.ctik , pcp.cfpd ,pcp.wd , 
		pcp.chc , pcp.md , pcp.bt , pcp.ca );
	if(pcp.ca == 90)
		pd = pcp.bt;
	else
		pd = pcp.bt / cos(BIT::AdvancedMath::AngleToRadian(pcp.ca));
	if(vr < 0)
		pd /=2;
	return true;
}