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

	//测试 冲击波压力威力参数分析类 中的成员函数
	double WarheadShockWavePower::testWarheadShockPowerClass(double di, double dj)
	{
		return di+dj;//返回两个数的和
	}
	// 计算对比距离（编写：徐豫新，测试：）
	double WarheadShockWavePower::ComputeContrastDistance(double ChargeMass, double Distance)
	{
		return Distance / pow( ChargeMass ,1.0 / 3.0 );
	}

	// 计算冲击波超压峰值（编写：徐豫新，测试：）
	double WarheadShockWavePower::ComputeShockWavePressure(double aa, double bb, double cc, double dd, double ContrastDistance)
	{
		return aa / ContrastDistance + bb / pow( ContrastDistance, 2 ) + cc / pow( ContrastDistance, 3 ) + dd;
	}
	// 计算正压区作用时间
	double WarheadShockWavePower::ComputePostivePressurTime(double bb, double Distance, double ChargeR, double ChargeMass, double ContrastDistance)
	{// ContrastDistance：对比距离
		double PostivePressurTime = 0;

		if ( Distance > 12 * ChargeR )
		{
			PostivePressurTime = bb * pow(  ContrastDistance , -1.0 / 2.0 ) * pow( ChargeMass, 1.0 / 3.0);
		}
		else
		{
			PostivePressurTime = -10002;   // 不在范围
		}

		return PostivePressurTime;
	}

	// 正压区作用压力随时间的变化（编写：徐豫新，测试：）
	double WarheadShockWavePower::ComputePressureChargeWithTime(double aa, double bb, double PressureTime, double Time, double ShockWavePressure)
	{// aa：公式适用范围最小值，bb：公式适用范围最大值；PressureTime：正压区作用时间，Time：任意时间，ShockWavePressure：冲击波最大压力
		double PressureChargeWithTime = 0;
		double A_Coefficient = 0;
		if ( ShockWavePressure < aa || ShockWavePressure == aa )
		{
			A_Coefficient = 0.5 + 10 * ShockWavePressure;  // 终点效应P287页
		} 
		else if( ShockWavePressure > aa && ShockWavePressure < bb )
		{
			A_Coefficient = 0.5 + 10 * ShockWavePressure * ( 1.1 - ( 0.13 + 2.0 * ShockWavePressure ) * Time / PressureTime );
		}
		else
		{
			PressureChargeWithTime = -10002; // 输入不在范围内；

		}

		PressureChargeWithTime = ShockWavePressure * ( 1 - Time / PressureTime ) * exp( -A_Coefficient * Time / PressureTime ); // 终点效应第287页

		return PressureChargeWithTime;
	}

	// 比冲量计算-经验公式（编写：徐豫新，测试：）
	double WarheadShockWavePower::ComputeSpecificImpulse(double cc, double ContrastDistance, double ChargeMass)
	{// cc:系数，ContrastDistance：对比距离；ChargeMass：装药质量
		return cc * pow( ChargeMass , 1.0 / 3.0) / ContrastDistance;
	}

	// 计算正反射超压

	// 计算正规斜反射
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
		//计算中间变量
		double aa = - M * ( 1 + tt_1 * tt_1 );
		double bb = M * ( 2 * tt_1 - 2 * uu * tt_1 ) - M * M * ( 1 - uu ) * ( 1 - uu ) + 1;
		double cc = M * M *( 1 - uu ) * ( 1 - uu ) * tt_1 + M * ( ( 1 - uu ) * ( 1 - uu ) ) * tt_1 + M * ( ( 1 - uu ) * ( 1 - uu ) - tt_1 * tt_1 - uu * uu ) -tt_1;
		tt_2 = AdvancedMath::function_1yuan2ci_Min( aa , bb , cc );
		ReflectionAngle = AdvancedMath::RadianToAngle( atan( tt_2 ));
		Pi_2 = AdvancedMath::CompareForMin( tt_2 , AdvancedMath::function_1yuan2ci_Max( aa , bb , cc ));
		ReflectionPressure = IncomingPressure * Pi_2;
		return ReflectionPressure;
	}

	// 计算正反射超压
	//终点效应P265页
	// IncomingOverPressure:入射超压;AirPressure:标准大气压
	double WarheadShockWavePower::ComputeVerticalReflectionPressure( double IncomingOverPressure 
		, double AirPressure )
	{
		double ReflectionOverPressure;
		ReflectionOverPressure = 2 * IncomingOverPressure + 6 * IncomingOverPressure 
			* IncomingOverPressure / ( IncomingOverPressure + 7 * AirPressure );
		return ReflectionOverPressure;
	}

	// 计算马赫反射超压（编写：徐豫新，测试：）
	// IncomingOverPressure：入射超压，IncomingAngle：入射角，度
	double WarheadShockWavePower::ComputeMachReflectionPressure(double IncomingOverPressure, 
		double IncomingAngle)
	{
		double MachReflectionOverPressure;
		MachReflectionOverPressure = IncomingOverPressure * 
			( 1 + cos( AdvancedMath::AngleToRadian( IncomingAngle )));
		return MachReflectionOverPressure;
	}
}