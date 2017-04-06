#include "AtmosphereAttribute.h"
#include <MathCalculationSupport/AdvancedMath.h>
#include <cstring>

namespace BIT
{

	AtmosphereAttribute::AtmosphereAttribute(void)
	{
		for(int i = 0; i < 21; i++)
		{
			H[i]=i;
		}
		double TT[21] = {288.15,281.65,275.15,268.65,262.15,255.65, 249.15,242.65,236.15,229.65,223.15,  //0~10
			216.65,216.65,216.65,216.65,216.65, 216.65,216.65,216.65,216.65,216.65};    //10~20
		/////* 上数据《弹丸空气动力学》P417 *////

		double DD[21] = {1.2250,1.1117,1.0065,0.9091,0.8191,0.7361,0.6597,0.5895,0.5258,0.4671,0.4135,
			0.3648,0.3119,0.2666,0.2279,0.1948,0.1665,0.1423,0.1217,0.1040,0.0889};

		double PP[21] = {10.1325,8.9876,7.9500,7.0121,6.1660,5.4048,4.7218,4.1105,3.5652,3.0801,2.6500,
			2.2700,1.9399,1.6580,1.4170,1.2112,1.0353,0.8850,0.7565,0.6468,0.5529};  

		memcpy(T, TT, sizeof(TT));
		memcpy(D, DD, sizeof(DD));
		memcpy(P, PP, sizeof(PP));
	}


	AtmosphereAttribute::~AtmosphereAttribute(void)
	{
	}

	//得到插值的海拔高度H 函数
	AtmosphereAttribute::ErrorType AtmosphereAttribute::HeightFunction(double EH)
	{
		if( EH < 0 && EH > 20)
		{
			return ParameterError;
		}
		return Normal;
	}

	// 求遭遇点大气温度函数  EH:遭遇点高度
	double AtmosphereAttribute::GetAtmosphereTemperature(double EH)
	{
		HeightFunction( EH );
		double Temperature = 0;
		int nn = 21;
		Temperature = AdvancedMath::LinearInterpolation( EH,H,T,nn);
		return Temperature;

	}

	// 计算高空中的当地音速函数  MMN:当地大气温度
	double AtmosphereAttribute::GetSoundVelocity(double MMN)
	{
		double SV = 0;
		SV = 20.05 * sqrt ( MMN ); // 单位(m/s)
		/////* 上式《爆轰物理学》P28 *////
		return SV;

	}

	// 求遭遇点大气压力函数  EH:遭遇点高度
	double AtmosphereAttribute::GetAtmospherePressure(double EH)
	{
		AdvancedMath TheAdvancedMath;
		HeightFunction( EH );
		double Pressure = 0;
		int nn = 21;
		Pressure = TheAdvancedMath.LinearInterpolation( EH,H,P,nn);
		return Pressure;

	}

	// 求遭遇点的大气密度函数  EH:遭遇点高度，km
	double AtmosphereAttribute::GetAtmosphereDensity(double EH)
	{
		AdvancedMath TheAdvancedMath;
		HeightFunction( EH );
		double Density = 0;
		int nn = 21;
		Density = TheAdvancedMath.LinearInterpolation( EH , H , D , nn );
		return Density;

	}

	// 计算的高空速度函数（马赫数和速度）
	double AtmosphereAttribute::Velocity(int RV, int RM, double V, double M, double EH)
	{// RV:由速度得到速度 RM:由马赫数得到速度 V:速度  M:马赫数 EH:遭遇高度
		double TV = 0;

		if( RV == 1 && RM == 0 )          
		{
			TV = V;
		}
		else if( RM == 1 && RV == 0 )
		{
			// 计算遭遇点温度
			double EHTemperature = GetAtmosphereTemperature( EH ); 
			// 计算当地音速
			double SoundVelocity = GetSoundVelocity( EHTemperature );  
			// 计算空中战斗机速度
			TV = SoundVelocity * M;              
		}
		else
		{
			TV = -10001;//未选择使用速度或目标马赫数进行计算
		}
		return TV;
	}

}
