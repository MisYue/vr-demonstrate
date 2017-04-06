/************************************************
	���ƣ�׼��̬ѹ�������������� WarheadQuasiStaticPresurePower
	���ܣ����㵼��ս�������ڱ�ը׼��̬ѹ����ֵ������ʱ��ͱȳ���
	�����ˣ�
	����ʱ�䣺
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
	class POWERANALYSISBASE_EXPORT WarheadQuasiStaticPresurePower
	{
	public:
		WarheadQuasiStaticPresurePower(void);
		~WarheadQuasiStaticPresurePower(void);

		//���� ׼��̬ѹ���������������� �еĳ�Ա����
		static double testWarheadQuasiStaticPresurePowerClass(double di, double dj);

		//Carlson��Moir��ʽ�����׼��̬ѹ��,MPa
		//Coefficient_A��ϵ��A��������Ϊ1.3����TNTChargesMass��TNTװҩ����kg��ClosedSpaceVolume���ܱտռ������m^3
		static double ComputeQuasiStaticPresureOnVolume_CarlsonAndMoir(
			double Coefficient_A ,double TNTChargesMass , double ClosedSpaceVolume  );

		//KiBongLee��ʽ�����׼��̬ѹ��,MPa
		//ChargesAllBurnHeat��ըҩ��ȼ���ȣ�KJ
		static double ComputeQuasiStaticPresureOnBurnHeat_KiBongLee( 
			double ChargesAllBurnHeat );
	};

}

