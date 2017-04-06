/************************************************
	���ƣ������������������ WarheadShockPower
	���ܣ����㵼��ս������ը��ĳ������������������
		�������ѹ��ֵ����ѹ������ʱ�䡢�ȳ���
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
	class POWERANALYSISBASE_EXPORT WarheadShockWavePower
	{
	public:
		WarheadShockWavePower(void);
		~WarheadShockWavePower(void);

		//���� ս������������������ �еĳ�Ա����
		static double testWarheadShockPowerClass(double di, double dj);

		// ����ԱȾ���
		static double ComputeContrastDistance(double ChargeMass, double Distance);
		// ����������ѹ��ֵ
		static double ComputeShockWavePressure(double aa, double bb, double cc, double dd, double ContrastDistance);
		// ������ѹ������ʱ��
		static double ComputePostivePressurTime(double bb, double Distance,double ChargeR, double ChargeMass, double ContrastDistance);
		// ��ѹ������ѹ����ʱ��ı仯
		static double ComputePressureChargeWithTime(double aa, double bb, double PressureTime, double Time, double ShockWavePressure);
		// �ȳ�������-���鹫ʽ
		static double ComputeSpecificImpulse(double cc, double ContrastDistance, double ChargeMass);
		// ���������䳬ѹ
		// IncomingOverPressure:���䳬ѹ��AirPressure:��׼����ѹ
		static double ComputeVerticalReflectionPressure( double IncomingOverPressure , 
			double AirPressure );
		// ������շ��䳬ѹ
		//
		static double ComputeMachReflectionPressure(double IncomingOverPressure, 
			double IncomingAngle);
		// ��������б����
		static double ComputeRegularObliqueReflectionPressure(double AirPressure
			, double IncomingAngle, double IncomingPressure, double kk_AirIsentropicIndex);
	};

}

