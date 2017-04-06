// 战斗部准静态压力计算
#include "WarheadQuasiStaticPresurePower.h"

namespace BIT
{
	WarheadQuasiStaticPresurePower::WarheadQuasiStaticPresurePower(void)
	{
	}


	WarheadQuasiStaticPresurePower::~WarheadQuasiStaticPresurePower(void)
	{
	}

	//测试 准静态压力威力参数分析类 中的成员函数
	double WarheadQuasiStaticPresurePower::testWarheadQuasiStaticPresurePowerClass(double di, double dj)
	{
		return di+dj;//返回两个数的和
	}

	//Carlson和Moir公式，输出准静态压力,MPa
	//Coefficient_A：系数A（文献上为1.3），TNTChargesMass，TNT装药量，kg；ClosedSpaceVolume：密闭空间体积，m^3
	double WarheadQuasiStaticPresurePower::ComputeQuasiStaticPresureOnVolume_CarlsonAndMoir( 
		double Coefficient_A ,double TNTChargesMass , double ClosedSpaceVolume )
	{
		return Coefficient_A * TNTChargesMass / ClosedSpaceVolume;
	}

	//KiBongLee公式，输出准静态压力,MPa
	//ChargesAllBurnHeat：炸药总燃烧热，KJ
	double WarheadQuasiStaticPresurePower::ComputeQuasiStaticPresureOnBurnHeat_KiBongLee(
		double ChargesAllBurnHeat )
	{
		return 0.146 + 0.193 * ChargesAllBurnHeat;
	}

}
