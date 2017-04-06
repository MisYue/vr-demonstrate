/************************************************
	名称：气象状态 AtmosphereAttribute
	功能：计算威力计算中所涉及的气象状态，主要用于大气密度的计算
			同时可坚固用于外弹道计算
	创建人：徐豫新
	创建时间：2015年4月9日
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
	class POWERANALYSISBASE_EXPORT AtmosphereAttribute
	{
	public:
		~AtmosphereAttribute(void);

	public:
		//错误类型枚举，Normal：正常，ParameterError：参数错误
		enum ErrorType{ Normal ,ParameterError };
		// 计算的高空速度函数（马赫数和速度）
		double Velocity(int RV, int RM, double V, double M, double EH);
		// 求遭遇点的大气密度函数  EH:遭遇点高度,km
		double GetAtmosphereDensity(double EH);
		// 求遭遇点大气压力函数  EH:遭遇点高度
		double GetAtmospherePressure(double EH);
		// 计算高空中的当地音速函数  MMN:当地大气温度
		double GetSoundVelocity(double MMN);
		// 求遭遇点大气温度函数  EH:遭遇点高度 km
		double GetAtmosphereTemperature(double EH);

		static AtmosphereAttribute& instance()
		{
			static AtmosphereAttribute s_instance;
			return s_instance;
		}
	private:
		AtmosphereAttribute(void);
		// 得到插值的海拔高度H 函数
		ErrorType HeightFunction( double EH );
		// 计算插值时使用的高度的数值0~20
		double H[21];

		//温度
		double T[21];

		//压力
		double P[21];

		//密度
		double D[21];
	};
}

