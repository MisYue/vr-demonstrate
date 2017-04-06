// ս����׼��̬ѹ������
#include "WarheadQuasiStaticPresurePower.h"

namespace BIT
{
	WarheadQuasiStaticPresurePower::WarheadQuasiStaticPresurePower(void)
	{
	}


	WarheadQuasiStaticPresurePower::~WarheadQuasiStaticPresurePower(void)
	{
	}

	//���� ׼��̬ѹ���������������� �еĳ�Ա����
	double WarheadQuasiStaticPresurePower::testWarheadQuasiStaticPresurePowerClass(double di, double dj)
	{
		return di+dj;//�����������ĺ�
	}

	//Carlson��Moir��ʽ�����׼��̬ѹ��,MPa
	//Coefficient_A��ϵ��A��������Ϊ1.3����TNTChargesMass��TNTװҩ����kg��ClosedSpaceVolume���ܱտռ������m^3
	double WarheadQuasiStaticPresurePower::ComputeQuasiStaticPresureOnVolume_CarlsonAndMoir( 
		double Coefficient_A ,double TNTChargesMass , double ClosedSpaceVolume )
	{
		return Coefficient_A * TNTChargesMass / ClosedSpaceVolume;
	}

	//KiBongLee��ʽ�����׼��̬ѹ��,MPa
	//ChargesAllBurnHeat��ըҩ��ȼ���ȣ�KJ
	double WarheadQuasiStaticPresurePower::ComputeQuasiStaticPresureOnBurnHeat_KiBongLee(
		double ChargesAllBurnHeat )
	{
		return 0.146 + 0.193 * ChargesAllBurnHeat;
	}

}
