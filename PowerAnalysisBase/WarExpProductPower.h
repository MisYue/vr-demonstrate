/************************************************
	名称：爆炸产物威力参数分析 WarExpProductPower
	功能：计算导弹战斗部爆炸初期产生爆炸产物的膨胀超压
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
	class POWERANALYSISBASE_EXPORT WarExpProductPower
	{
	public:
		WarExpProductPower(void);
		~WarExpProductPower(void);

		//测试 爆炸产物威力参数分析类 中的成员函数
		static double testWarExpProductPowerClass(double di, double dj);
		// 计算爆炸产物压力,Pa
		//ChargeDensity：装药装填密度，kg/m^3；ChargeBlastVelocity：装药爆速：m/s
		//ChargeSphereEquivalentRadius：装药等效球形半径，m；
		//DistanceReachChargeCentre：到爆炸中心距离，m
		//AdiabaticExponent 绝热指数，无量纲
		static double ComputeExpProductPressure( double ChargeDensity
			, double ChargeBlastVelocity , double ChargeSphereEquivalentRadius 
			, double DistanceReachChargeCentre , double AdiabaticExponent );
	};

}

