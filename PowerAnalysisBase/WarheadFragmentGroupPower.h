/************************************************
	名称：破片群威力参数分析 WarheadFragmentGroupPower
	功能：计算导弹战斗部爆炸后破片群的威力参数，即：破片初速、质量分布、
			离爆心一定距离外的破片速度和分布密度
	创建人：
	创建时间：
	版本：1.0



	修改人：岳群磊
	修改日期：2016年5月30日
	修改描述：修改库的使用接口
	版本：1.1


*************************************************/

#pragma once
// 定义海平面空气密度(单位：kg/m^3)
#define AirDensityInSeaPlane 1.225
#include "poweranalysisbase_global.h"

namespace BIT
{
	class POWERANALYSISBASE_EXPORT WarheadFragmentGroupPower
	{
	public:
		WarheadFragmentGroupPower(void);
		~WarheadFragmentGroupPower(void);

		//测试 破片群威力参数分析类 中的成员函数
		static double testWarheadFragmentGroupPowerClass(double di, double dj);

		// 计算格尼能
		//BlaseVelocity：爆速，公式系数：a，公式系数：b
		static double ComputeGurneyEnergy(double BlaseVelocity, double aa, double bb);
		
		// 计算破片初始速度
		//WLC：装填系数，GE：格尼能,(m/s)
		static double ComputeFragmengtVelocity_OnGurneyformula(double WLC, double GE);

		// 适用于薄壁半预制战斗部
		//WLC：装填系数，装药质量/壳体质量；BlaseVelocity：炸药爆速
		static double ComputeFragmengtVelocity_ThinWall( double WLC , double BlaseVelocity );

		// 适用于厚壁战斗部
		//WLC：装填系数,装药质量/壳体质量
		static double ComputeFragmengtVelocity_ThickWall( double WLC );

		// 适用于大型薄壁半预制破片战斗部
		// WLC_All：装填系数，装药质量/(装药质量+壳体质量)；BlaseVelocity：炸药爆速
		static double ComputeFragmengtVelocity_LargeThinWallSemiPreformed( double WLC_All , double BlaseVelocity );

		// 适用于火箭弹公式1
		// ShellMass：壳体质量；ChargeMass：装药质量；BlaseVelocity：炸药爆速
		static double ComputeFragmengtVelocity_Rocket1( double ShellMass , double ChargeMass , double BlaseVelocity );

		// 适用于火箭弹公式2
		// WLC_All：装填系数，装药质量/(装药质量+壳体质量)；BlaseVelocity：炸药爆速
		static double ComputeFragmengtVelocity_Rocket2( double WLC_All , double BlaseVelocity );

		// 得到破片平均质量方法（基于Gurney和Sarmousakis方法）
		// KK：取决于炸药的系数，(kg1/2/m3/2)；tt：弹壳平均壁厚，(m)；
		// 弹壳平均内径，(m)；装药质量，(kg)；壳体质量，(kg)。
		// 输出量，kg
		static double ComputeFragmentAverageMass_OnGurAndSar(double KK, double tt, double dd, 
			double Me, double Mf);
		
		// 得到破片平均质量方法（基于Mott方法）
		// ShellThickness：壳体壁厚，cm；d0：壳体内径，mm；K：炸药常数，g^(1/2)/cm^(7/6)
		// 输出量，g
		static double ComputeFragmentAverageMass_OnMott( double ShellThickness , double d0 , double K );

		// 得到破片平均质量方法(基于破片总数量)
		//kk：弹体质量损失系数(大于0,小于等于1)；
		//ShellMass：壳体质量,(kg)；FragmentNumber：破片总数,(N)
		static double ComputeFragmentAverageMass_OnFragAllNum(double kk, double ShellMass, 
			double FragmentNumber);
		
		// 得到破片数量总数计算方法一（终点效应书P66）
		// ShellMass：壳体质量,(kg)；FragmentAverageMass：破片平均质量,(kg)
		static int ComputeFragmentNumber_OnAvMass(double ShellMass, double FragmentAverageMass);
		
		// 得到破片数量总数方法二（适合榴弹）
		// //aa：系数，WholeMass：弹体总质量，WLC：装填系数
		static int ComputeFragmentNumber_2(double aa, double WholeMass, double WLC);
		
		// 大于某一质量破片累计数量（Mott）
		// FragmentN0：破片总数,(枚)；OneMassFragment，某一破片质量，(g)；
		//FragmentAverageMass，破片平均质量，(g)
		static int ComputeOneMassFragmentN_Mott(int FragmentN0, double OneMassFragment, 
			double FragmentAverageMass);
		
		// 大于某一质量破片累计数量方法2
		static int ComputeOneMassFragmentN_2(int FragmentN0, double OneMassFragment,
			double aa, double bb);
		
		// 质量小于或等于某一质量的破片总质量
		static double ComputeOneMassFragmentMass_Held(double kk, double ShellMass, 
			double OneMassFragment, double aa, double bb);

		//计算破片动态飞散速度
		static double ComputeFragmentDynamicFlyVelocity( double AmmunitionVelocity , 
			double FragmentVelocity , double FlyDirectionAngle );

		//计算破片迎风面积
		//ShapeCoefficient：形状系数，m^2/kg^(2/3)
		//FragmentMass：破片质量，kg
		static double ComputeFragmentWindwardArea( double ShapeCoefficient , double FragmentMass );

		//计算速度衰减系数(输出无量纲)
		//ResistanceCoefficient：大气阻力系数；EncounterHeight：遭遇点高度，km；
		//WindwardArea：迎风面积，m^2；FragmentMass：破片质量，kg
		static double ComputeFragmentVelocityReductionCoefficient( double ResistanceCoefficient , 
			double EncounterHeight , double WindwardArea , double FragmentMass );

		//由初速、距离计算破片的末端速度（输出：m/s）
		//FragmentInitialVelocity：破片初始速度，m/s；
		//FragmentVelocityReductionCoefficient：破片速度衰减系数；
		//FragmentFlyDistance：破片飞行距离，m
		static double ComputeFragmentTerminalVelocityOnIni( double FragmentInitialVelocity 
			, double FragmentVelocityReductionCoefficient , double FragmentFlyDistance );

		//*******************破片弹道极限计算公式**************************
		//公式一（德玛尔公式），计算结果单位为m/s
		//ReviseIndexA：修正系数，2000-2600；FragmentDiameter：破片直径，dm；
		//FragmentMass：破片质量，kg；BoardThickness：靶板厚度，dm；
		//HitAngle：着靶角度，度
		static double ComputeBallisticLimitVelocity_Demar( double ReviseIndexA , 
			double FragmentDiameter , double FragmentMass ,
			double BoardThickness , double HitAngle );

		//公式二（Johns Hopkins大学）
		//IndexK,IndexAlpha,IndexBeta,IndexGamma：与材料特性相关的系数；BoardThickness：靶板厚度，cm；
		//FragmentAverageContactArea：破片平均着靶面积，cm^2；FragmentMass：破片质量，g；HitAngle：着靶角度，度
		static double ComputeBallisticLimitVelocity_Hopkins( double IndexK , double IndexAlpha , double IndexBeta ,
			double IndexGamma , double BoardThickness , double FragmentAverageContactArea ,
			double FragmentMass , double HitAngle );

		//公式三（黄长强）
		//IndexA，IndexB：取决于弹靶条件的系数；BoardThickness：靶板厚度，m；FragmentDiameter：破片直径，m；
		//BoardDensity：靶板材料密度，kg/m^3；FragmentDensity：破片材料密度，kg/m^3；BoardBreakingPoint：靶板强度极限，MPa
		static double ComputeBallisticLimitVelocity_HuangCQ( double IndexA , double IndexB , double BoardThickness ,
			double FragmentDiameter , double BoardDensity , double FragmentDensity , double BoardBreakingPoint );

		//公式四（陈志斌），计算结果单位为m/s
		//BoardThickness：靶板厚度，mm；BoardYieldLimit：靶板屈服极限，Pa；BoardDensity：靶板密度，kg/m^3；
		//FragmentDensity：破片密度，kg/m^3；FragmentDiameter：破片直径，mm
		static double ComputeBallisticLimitVelocity_ChenZB( double BoardThickness , double BoardYieldLimit , double BoardDensity ,
			double FragmentDensity , double FragmentDiameter );

		//公式五（午新民）（钨合金打装甲钢），计算结果单位为m/s
		//BoardThickness：靶板厚度，m；FragmentDiameter：破片直径，m；BoardDensity：靶板材料密度，kg/m^3；
		//FragmentDensity：破片材料密度，kg/m^3；BoardBreakingPoint：靶板强度极限，MPa；FragmentBreakingPoint：破片强度极限，Mpa
		static double ComputeBallisticLimitVelocity_WuXM( double BoardThickness , double FragmentDiameter , double BoardDensity ,
			double FragmentDensity , double BoardBreakingPoint , double FragmentBreakingPoint , double HitAngle );

		//对于93W钨合金破片的实验仿真拟合公式，（钨合金打Q235钢），计算结果单位为m/s
		//FragmentDiameter：破片直径，m；BoardThickness：靶板厚度，m
		static double ComputeBallisticLimitVelocity_93W( double FragmentDiameter , double BoardThickness );

		//对于95W钨合金破片的实验仿真拟合公式，（钨合金打Q235钢）计算结果单位为m/s
		//FragmentDiameter：破片直径，m；BoardThickness：靶板厚度，m
		static double ComputeBallisticLimitVelocity_95W( double FragmentDiameter , double BoardThickness );
	};

}

