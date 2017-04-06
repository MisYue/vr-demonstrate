#include "WarheadShockWavePower.h"
#include <MathCalculationSupport/AdvancedMath.h>

namespace BIT
{

	WarheadShockWavePower::WarheadShockWavePower(void)
	{
	}


	WarheadShockWavePower::~WarheadShockWavePower(void)
	{
	}

	//���� �����ѹ���������������� �еĳ�Ա����
	double WarheadShockWavePower::testWarheadShockPowerClass(double di, double dj)
	{
		return di+dj;//�����������ĺ�
	}
	// ����ԱȾ��루��д����ԥ�£����ԣ���
	double WarheadShockWavePower::ComputeContrastDistance(double ChargeMass, double Distance)
	{
		return Distance / pow( ChargeMass ,1.0 / 3.0 );
	}

	// ����������ѹ��ֵ����д����ԥ�£����ԣ���
	double WarheadShockWavePower::ComputeShockWavePressure(double aa, double bb, double cc, double dd, double ContrastDistance)
	{
		return aa / ContrastDistance + bb / pow( ContrastDistance, 2 ) + cc / pow( ContrastDistance, 3 ) + dd;
	}
	// ������ѹ������ʱ��
	double WarheadShockWavePower::ComputePostivePressurTime(double bb, double Distance, double ChargeR, double ChargeMass, double ContrastDistance)
	{// ContrastDistance���ԱȾ���
		double PostivePressurTime = 0;

		if ( Distance > 12 * ChargeR )
		{
			PostivePressurTime = bb * pow(  ContrastDistance , -1.0 / 2.0 ) * pow( ChargeMass, 1.0 / 3.0);
		}
		else
		{
			PostivePressurTime = -10002;   // ���ڷ�Χ
		}

		return PostivePressurTime;
	}

	// ��ѹ������ѹ����ʱ��ı仯����д����ԥ�£����ԣ���
	double WarheadShockWavePower::ComputePressureChargeWithTime(double aa, double bb, double PressureTime, double Time, double ShockWavePressure)
	{// aa����ʽ���÷�Χ��Сֵ��bb����ʽ���÷�Χ���ֵ��PressureTime����ѹ������ʱ�䣬Time������ʱ�䣬ShockWavePressure����������ѹ��
		double PressureChargeWithTime = 0;
		double A_Coefficient = 0;
		if ( ShockWavePressure < aa || ShockWavePressure == aa )
		{
			A_Coefficient = 0.5 + 10 * ShockWavePressure;  // �յ�ЧӦP287ҳ
		} 
		else if( ShockWavePressure > aa && ShockWavePressure < bb )
		{
			A_Coefficient = 0.5 + 10 * ShockWavePressure * ( 1.1 - ( 0.13 + 2.0 * ShockWavePressure ) * Time / PressureTime );
		}
		else
		{
			PressureChargeWithTime = -10002; // ���벻�ڷ�Χ�ڣ�

		}

		PressureChargeWithTime = ShockWavePressure * ( 1 - Time / PressureTime ) * exp( -A_Coefficient * Time / PressureTime ); // �յ�ЧӦ��287ҳ

		return PressureChargeWithTime;
	}

	// �ȳ�������-���鹫ʽ����д����ԥ�£����ԣ���
	double WarheadShockWavePower::ComputeSpecificImpulse(double cc, double ContrastDistance, double ChargeMass)
	{// cc:ϵ����ContrastDistance���ԱȾ��룻ChargeMass��װҩ����
		return cc * pow( ChargeMass , 1.0 / 3.0) / ContrastDistance;
	}

	// ���������䳬ѹ

	// ��������б����
	double WarheadShockWavePower::ComputeRegularObliqueReflectionPressure(double AirPressure
		, double IncomingAngle, double IncomingPressure, double kk_AirIsentropicIndex)
	{
		double ReflectionPressure = 0;
		double ReflectionAngle = 0;
		double tt_2 = 0;
		double Pi_2 = 0;
		double Pi_1 = IncomingPressure / AirPressure;
		double tt_1 = tan( AdvancedMath::AngleToRadian( IncomingAngle ));
		double uu = kk_AirIsentropicIndex - 1 / kk_AirIsentropicIndex + 1;
		double M = ( ( Pi_1 - 1 ) * tt_1 ) / ( Pi_1 + uu + ( 1 + uu * Pi_1 ) * tt_1 );
		//�����м����
		double aa = - M * ( 1 + tt_1 * tt_1 );
		double bb = M * ( 2 * tt_1 - 2 * uu * tt_1 ) - M * M * ( 1 - uu ) * ( 1 - uu ) + 1;
		double cc = M * M *( 1 - uu ) * ( 1 - uu ) * tt_1 + M * ( ( 1 - uu ) * ( 1 - uu ) ) * tt_1 + M * ( ( 1 - uu ) * ( 1 - uu ) - tt_1 * tt_1 - uu * uu ) -tt_1;
		tt_2 = AdvancedMath::function_1yuan2ci_Min( aa , bb , cc );
		ReflectionAngle = AdvancedMath::RadianToAngle( atan( tt_2 ));
		Pi_2 = AdvancedMath::CompareForMin( tt_2 , AdvancedMath::function_1yuan2ci_Max( aa , bb , cc ));
		ReflectionPressure = IncomingPressure * Pi_2;
		return ReflectionPressure;
	}

	// ���������䳬ѹ
	//�յ�ЧӦP265ҳ
	// IncomingOverPressure:���䳬ѹ;AirPressure:��׼����ѹ
	double WarheadShockWavePower::ComputeVerticalReflectionPressure( double IncomingOverPressure 
		, double AirPressure )
	{
		double ReflectionOverPressure;
		ReflectionOverPressure = 2 * IncomingOverPressure + 6 * IncomingOverPressure 
			* IncomingOverPressure / ( IncomingOverPressure + 7 * AirPressure );
		return ReflectionOverPressure;
	}

	// ������շ��䳬ѹ����д����ԥ�£����ԣ���
	// IncomingOverPressure�����䳬ѹ��IncomingAngle������ǣ���
	double WarheadShockWavePower::ComputeMachReflectionPressure(double IncomingOverPressure, 
		double IncomingAngle)
	{
		double MachReflectionOverPressure;
		MachReflectionOverPressure = IncomingOverPressure * 
			( 1 + cos( AdvancedMath::AngleToRadian( IncomingAngle )));
		return MachReflectionOverPressure;
	}
}