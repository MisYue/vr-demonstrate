/************************************************
	���ƣ�����״̬ AtmosphereAttribute
	���ܣ������������������漰������״̬����Ҫ���ڴ����ܶȵļ���
			ͬʱ�ɼ�������ⵯ������
	�����ˣ���ԥ��
	����ʱ�䣺2015��4��9��
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
	class POWERANALYSISBASE_EXPORT AtmosphereAttribute
	{
	public:
		~AtmosphereAttribute(void);

	public:
		//��������ö�٣�Normal��������ParameterError����������
		enum ErrorType{ Normal ,ParameterError };
		// ����ĸ߿��ٶȺ�������������ٶȣ�
		double Velocity(int RV, int RM, double V, double M, double EH);
		// ��������Ĵ����ܶȺ���  EH:������߶�,km
		double GetAtmosphereDensity(double EH);
		// �����������ѹ������  EH:������߶�
		double GetAtmospherePressure(double EH);
		// ����߿��еĵ������ٺ���  MMN:���ش����¶�
		double GetSoundVelocity(double MMN);
		// ������������¶Ⱥ���  EH:������߶� km
		double GetAtmosphereTemperature(double EH);

		static AtmosphereAttribute& instance()
		{
			static AtmosphereAttribute s_instance;
			return s_instance;
		}
	private:
		AtmosphereAttribute(void);
		// �õ���ֵ�ĺ��θ߶�H ����
		ErrorType HeightFunction( double EH );
		// �����ֵʱʹ�õĸ߶ȵ���ֵ0~20
		double H[21];

		//�¶�
		double T[21];

		//ѹ��
		double P[21];

		//�ܶ�
		double D[21];
	};
}

