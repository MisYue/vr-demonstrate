#include "WarBaParaForPowerAnalysis.h"
#include <cmath>

// 战斗部威力计算基础参数分析

namespace BIT
{

	WarBaParaForPowerAnalysis::WarBaParaForPowerAnalysis(void)
	{
	}


	WarBaParaForPowerAnalysis::~WarBaParaForPowerAnalysis(void)
	{
	}

	//测试 战斗部威力计算基础参数分析类 中的成员函数
	double WarBaParaForPowerAnalysis::testWarBaParaForPowerAnalysisClass(double di, double dj)
	{
		return di+dj;//返回两个数的和

	}

	//***************************************************************************************//
	//***本类战斗部威力计算的共用基本函数：装填系数、带壳装药相当于裸露装药的当量、TNT当量***//
	//


// 计算装填系数
	double WarBaParaForPowerAnalysis::ComputeWLC( double WholeMass, double ChargesMass, double ShellMass )
	{
		double WLC = 0;

		if ( WholeMass == 0 )
		{
			WLC  = ChargesMass / ( ShellMass );
		}
		else if ( ChargesMass == 0 )
		{
			WLC  = ( WholeMass - ShellMass ) / ShellMass;
		}
		else if ( ShellMass == 0 )
		{
			WLC = ChargesMass / ( WholeMass - ChargesMass );
		}
		return WLC;
	}
	//计算带壳装药相当于裸露装药的当量
	//Charge_shell：带壳装药，R_0：战斗部半径，R_p0：破裂半径/原半径，aa：形状系数A，bb：形状系数B，PolytropicExponent：多方指数
	double WarBaParaForPowerAnalysis::ComputeNakedChargeEquivalentMass( double Charge_shell, double R_0 , double R_p0, 
		double aa , double bb , double PolytropicExponent , double WLC)
	{
		double NakedCharge = 0;
		NakedCharge = Charge_shell * ( WLC / ( aa + 1 - WLC * aa ) + 
			( aa + 1 ) * ( 1- WLC ) * pow( ( R_0 / R_p0 ) , bb * 
			( PolytropicExponent - 1) ) / ( aa + 1 - aa * WLC ));;

		return NakedCharge;
	}

	//运动装药向静止装药转换《终点效应学》—王树山 p293
	double WarBaParaForPowerAnalysis::ComputeMotionChargeEquivalentMass( double Charge_M, double ChargeVelocity
		, double ChargeQv )
	{
		double EquivalentMass_Q = 0;

		EquivalentMass_Q = Charge_M * ( ChargeQv + 0.5 * ChargeVelocity * ChargeVelocity ) / ( ChargeQv );

		return EquivalentMass_Q;

	}
	//TNT当量计算
	double WarBaParaForPowerAnalysis::ComputeChargeTNTNL( double Charge_M , double Charge_Qv )
	{
		return Charge_M * Charge_Qv / 4479876;						// 4479876:TNT的爆热
	}

}
