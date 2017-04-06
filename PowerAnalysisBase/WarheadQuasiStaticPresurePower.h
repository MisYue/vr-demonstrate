/************************************************
	名称：准静态压力威力参数分析 WarheadQuasiStaticPresurePower
	功能：计算导弹战斗部舱内爆炸准静态压力峰值、作用时间和比冲量
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
	class POWERANALYSISBASE_EXPORT WarheadQuasiStaticPresurePower
	{
	public:
		WarheadQuasiStaticPresurePower(void);
		~WarheadQuasiStaticPresurePower(void);

		//测试 准静态压力威力参数分析类 中的成员函数
		static double testWarheadQuasiStaticPresurePowerClass(double di, double dj);

		//Carlson和Moir公式，输出准静态压力,MPa
		//Coefficient_A：系数A（文献上为1.3），TNTChargesMass，TNT装药量，kg；ClosedSpaceVolume：密闭空间体积，m^3
		static double ComputeQuasiStaticPresureOnVolume_CarlsonAndMoir(
			double Coefficient_A ,double TNTChargesMass , double ClosedSpaceVolume  );

		//KiBongLee公式，输出准静态压力,MPa
		//ChargesAllBurnHeat：炸药总燃烧热，KJ
		static double ComputeQuasiStaticPresureOnBurnHeat_KiBongLee( 
			double ChargesAllBurnHeat );
	};

}

