/************************************************
	名称：冲击波威力参数分析 WarheadShockPower
	功能：计算导弹战斗部爆炸后的冲击波威力参数，即：
		冲击波超压峰值、正压区作用时间、比冲量
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
	class POWERANALYSISBASE_EXPORT WarheadShockWavePower
	{
	public:
		WarheadShockWavePower(void);
		~WarheadShockWavePower(void);

		//测试 战斗部威力参数分析类 中的成员函数
		static double testWarheadShockPowerClass(double di, double dj);

		// 计算对比距离
		static double ComputeContrastDistance(double ChargeMass, double Distance);
		// 计算冲击波超压峰值
		static double ComputeShockWavePressure(double aa, double bb, double cc, double dd, double ContrastDistance);
		// 计算正压区作用时间
		static double ComputePostivePressurTime(double bb, double Distance,double ChargeR, double ChargeMass, double ContrastDistance);
		// 正压区作用压力随时间的变化
		static double ComputePressureChargeWithTime(double aa, double bb, double PressureTime, double Time, double ShockWavePressure);
		// 比冲量计算-经验公式
		static double ComputeSpecificImpulse(double cc, double ContrastDistance, double ChargeMass);
		// 计算正反射超压
		// IncomingOverPressure:入射超压；AirPressure:标准大气压
		static double ComputeVerticalReflectionPressure( double IncomingOverPressure , 
			double AirPressure );
		// 计算马赫反射超压
		//
		static double ComputeMachReflectionPressure(double IncomingOverPressure, 
			double IncomingAngle);
		// 计算正规斜反射
		static double ComputeRegularObliqueReflectionPressure(double AirPressure
			, double IncomingAngle, double IncomingPressure, double kk_AirIsentropicIndex);
	};

}

