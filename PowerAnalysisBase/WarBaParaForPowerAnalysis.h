/************************************************
	名称：战斗部威力计算基础参数分析 WarBaParaForPowerAnalysis
	功能：计算战斗部装填系数、带壳装药TNT当量等威力计算基础参数。
	创建人：
	创建时间：
	版本：1.0


	修改人：岳群磊
	修改日期：2016年5月30日
	修改描述：修改库的使用接口
	版本：1.1

*************************************************/

#pragma once
#include "poweranalysisbase_global.h"


namespace BIT
{
	class POWERANALYSISBASE_EXPORT WarBaParaForPowerAnalysis
	{
	public:
		WarBaParaForPowerAnalysis(void);
		~WarBaParaForPowerAnalysis(void);

		//测试 战斗部威力计算基础参数分析类 中的成员函数
		static double testWarBaParaForPowerAnalysisClass(double di, double dj);

		//***************************************************************************************//
		//***本类战斗部威力计算的共用基本函数：
		// 装填系数
		// 带壳装药相当于裸露装药的当量
		// TNT当量***//
		//

		//计算装填系数
		//WholeMass：战斗部整体质量，ChargesMass：炸药装药质量，ShellMass：壳体质量
		//返回：战斗部装填系数，
		static double ComputeWLC(double WholeMass, double ChargesMass, double ShellMass);

		//计算带壳装药相当于裸露装药的质量
		//Charge_shell：带壳装药量（kg），R_0：原半径(mm)，R_p0：破裂半径(mm)，aa：形状系数A，bb：形状系数B，
		//PolytropicExponent：多方指数，WLC：装填系数
		//返回：带壳装药相当于裸露装药的质量
		static double ComputeNakedChargeEquivalentMass( double Charge_shell, double R_0 , double R_p0, 
			double aa , double bb , double PolytropicExponent , double WLC);

		//运动装药向静止装药转换《终点效应学》—王树山 p293
		//Charge_M：装药质量，ChargeVelocity：装药速度，ChargeQv：装药爆热
		//返回：运动装药等效成静止装药量
		static double ComputeMotionChargeEquivalentMass( double Charge_M, double ChargeVelocity, double ChargeQv );

		//TNT当量计算
		//Charge_M：装药质量,kg；Charge_Qv：装药爆热，J
		//返回TNT当量，kg
		static double ComputeChargeTNTNL( double Charge_M , double Charge_Qv );
	};

}

