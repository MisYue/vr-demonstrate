#include "WarExpProductPower.h"
#include <cmath>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{

	WarExpProductPower::WarExpProductPower(void)
	{
	}


	WarExpProductPower::~WarExpProductPower(void)
	{
	}

	//���� ��ը������������������ �еĳ�Ա����
	double WarExpProductPower::testWarExpProductPowerClass(double di, double dj)
	{
		return di+dj;//�����������ĺ�
	}

	// ���㱬ը����ѹ��,Pa
	//ChargeDensity��װҩװ���ܶȣ�kg/m^3��ChargeBlastVelocity��װҩ���٣�m/s
	//ChargeSphereEquivalentRadius��װҩ��Ч���ΰ뾶��m��
	//DistanceReachChargeCentre������ը���ľ��룬m
	//������Ժ���棬���˹滮���ڱ���P93
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
			// ���ڹ�ʽ���㷶Χ��
			ExpProductPressure = - 110000;
		}
		return ExpProductPressure;
	}

}
