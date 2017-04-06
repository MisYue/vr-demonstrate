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
		/////* �����ݡ������������ѧ��P417 *////

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

	//�õ���ֵ�ĺ��θ߶�H ����
	AtmosphereAttribute::ErrorType AtmosphereAttribute::HeightFunction(double EH)
	{
		if( EH < 0 && EH > 20)
		{
			return ParameterError;
		}
		return Normal;
	}

	// ������������¶Ⱥ���  EH:������߶�
	double AtmosphereAttribute::GetAtmosphereTemperature(double EH)
	{
		HeightFunction( EH );
		double Temperature = 0;
		int nn = 21;
		Temperature = AdvancedMath::LinearInterpolation( EH,H,T,nn);
		return Temperature;

	}

	// ����߿��еĵ������ٺ���  MMN:���ش����¶�
	double AtmosphereAttribute::GetSoundVelocity(double MMN)
	{
		double SV = 0;
		SV = 20.05 * sqrt ( MMN ); // ��λ(m/s)
		/////* ��ʽ����������ѧ��P28 *////
		return SV;

	}

	// �����������ѹ������  EH:������߶�
	double AtmosphereAttribute::GetAtmospherePressure(double EH)
	{
		AdvancedMath TheAdvancedMath;
		HeightFunction( EH );
		double Pressure = 0;
		int nn = 21;
		Pressure = TheAdvancedMath.LinearInterpolation( EH,H,P,nn);
		return Pressure;

	}

	// ��������Ĵ����ܶȺ���  EH:������߶ȣ�km
	double AtmosphereAttribute::GetAtmosphereDensity(double EH)
	{
		AdvancedMath TheAdvancedMath;
		HeightFunction( EH );
		double Density = 0;
		int nn = 21;
		Density = TheAdvancedMath.LinearInterpolation( EH , H , D , nn );
		return Density;

	}

	// ����ĸ߿��ٶȺ�������������ٶȣ�
	double AtmosphereAttribute::Velocity(int RV, int RM, double V, double M, double EH)
	{// RV:���ٶȵõ��ٶ� RM:��������õ��ٶ� V:�ٶ�  M:����� EH:�����߶�
		double TV = 0;

		if( RV == 1 && RM == 0 )          
		{
			TV = V;
		}
		else if( RM == 1 && RV == 0 )
		{
			// �����������¶�
			double EHTemperature = GetAtmosphereTemperature( EH ); 
			// ���㵱������
			double SoundVelocity = GetSoundVelocity( EHTemperature );  
			// �������ս�����ٶ�
			TV = SoundVelocity * M;              
		}
		else
		{
			TV = -10001;//δѡ��ʹ���ٶȻ�Ŀ����������м���
		}
		return TV;
	}

}
