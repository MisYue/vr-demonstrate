/************************************************
	���ƣ���ը���������������� WarExpProductPower
	���ܣ����㵼��ս������ը���ڲ�����ը��������ͳ�ѹ
	�����ˣ�
	����ʱ�䣺
	�汾��1.0


	�޸��ˣ���Ⱥ��
	�޸����ڣ�2016��5��30��
	�޸��������޸Ŀ��ʹ�ýӿ�
	�汾��1.1
*************************************************/

#pragma once

#include "poweranalysisbase_global.h"


namespace BIT
{
	class POWERANALYSISBASE_EXPORT WarExpProductPower
	{
	public:
		WarExpProductPower(void);
		~WarExpProductPower(void);

		//���� ��ը������������������ �еĳ�Ա����
		static double testWarExpProductPowerClass(double di, double dj);
		// ���㱬ը����ѹ��,Pa
		//ChargeDensity��װҩװ���ܶȣ�kg/m^3��ChargeBlastVelocity��װҩ���٣�m/s
		//ChargeSphereEquivalentRadius��װҩ��Ч���ΰ뾶��m��
		//DistanceReachChargeCentre������ը���ľ��룬m
		//AdiabaticExponent ����ָ����������
		static double ComputeExpProductPressure( double ChargeDensity
			, double ChargeBlastVelocity , double ChargeSphereEquivalentRadius 
			, double DistanceReachChargeCentre , double AdiabaticExponent );
	};

}

