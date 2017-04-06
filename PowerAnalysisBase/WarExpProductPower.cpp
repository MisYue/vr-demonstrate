#include "WarExpProductPower.h"
#include <cmath>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{

	WarExpProductPower::WarExpProductPower(void)
	{
	}


	WarExpProductPower::~WarExpProductPower(void)
	{
	}

	//测试 爆炸产物威力参数分析类 中的成员函数
	double WarExpProductPower::testWarExpProductPowerClass(double di, double dj)
	{
		return di+dj;//返回两个数的和
	}

	// 计算爆炸产物压力,Pa
	//ChargeDensity：装药装填密度，kg/m^3；ChargeBlastVelocity：装药爆速：m/s
	//ChargeSphereEquivalentRadius：装药等效球形半径，m；
	//DistanceReachChargeCentre：到爆炸中心距离，m
	//航天三院报告，毁伤规划中期报告P93
	double WarExpProductPower::ComputeExpProductPressure( double ChargeDensity 
		, double ChargeBlastVelocity , double ChargeSphereEquivalentRadius 
		, double DistanceReachChargeCentre , double AdiabaticExponent)
	{

		double ExpProductPressure = 0;

		if( DistanceReachChargeCentre > ChargeSphereEquivalentRadius 
			&& DistanceReachChargeCentre < 2 * ChargeSphereEquivalentRadius )
		{
			ExpProductPressure = ChargeDensity * ChargeBlastVelocity * ChargeBlastVelocity 
				* pow( ChargeSphereEquivalentRadius / DistanceReachChargeCentre , 8 )/ 8.0;
		}
		else if( ( DistanceReachChargeCentre > 2 * ChargeSphereEquivalentRadius 
			|| DistanceReachChargeCentre == 2 * ChargeSphereEquivalentRadius )
			&& ( DistanceReachChargeCentre < 10 * ChargeSphereEquivalentRadius )
			|| DistanceReachChargeCentre == 10 * ChargeSphereEquivalentRadius )
		{
			ExpProductPressure = ChargeDensity * ChargeBlastVelocity * ChargeBlastVelocity 
				* pow( 0.5 , 8 ) * pow( 2 * ChargeSphereEquivalentRadius 
				/ DistanceReachChargeCentre , 3 * AdiabaticExponent );
		}
		else
		{
			// 不在公式计算范围内
			ExpProductPressure = - 110000;
		}
		return ExpProductPressure;
	}

}
