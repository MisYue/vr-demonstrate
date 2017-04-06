#include "WarheadFragmentGroupPower.h"
#include <MathCalculationSupport/AdvancedMath.h>
#include <AtmosphereAttribute.h>
#include <cmath>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{
	WarheadFragmentGroupPower::WarheadFragmentGroupPower(void)
	{
	}


	WarheadFragmentGroupPower::~WarheadFragmentGroupPower(void)
	{
	}

	//测试 破片群威力参数分析类 中的成员函数
	double WarheadFragmentGroupPower::testWarheadFragmentGroupPowerClass(double di, double dj)
	{
		return di+dj;//返回两个数的和
	}

	//计算格尼能计算式一（编写：徐豫新，测试：）
	double WarheadFragmentGroupPower::ComputeGurneyEnergy(double BlaseVelocity, 
		double aa, double bb)
	{// BlaseVelocity:爆速,(m/s)；A：系数：0.52，B系数：0.28.
		return ( aa + bb * ( BlaseVelocity / 1000 ) ) * 1000;
	}

	//*********************************几种计算破片平均速度的方法**************************************
	//计算破片平均速度（编写：徐豫新，测试：）
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_OnGurneyformula(
		double WLC, double GE)
	{// WLC：装填系数，GE：格尼能,(m/s)
		return GE * sqrt ( WLC / ( 1 + 0.5 * WLC) );
	}


	// 适用于薄壁半预制战斗部
	//WLC：装填系数，装药质量/壳体质量；BlaseVelocity：炸药爆速
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_ThinWall( double WLC , double BlaseVelocity )
	{
		return 0.353 * BlaseVelocity * sqrt( 3 * WLC / ( 3 + WLC ));
	}

	// 适用于厚壁战斗部
	//WLC：装填系数,装药质量/壳体质量
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_ThickWall( double WLC )
	{
		if ( WLC > 0 && WLC < 2 )
		{
			return 1830 * sqrt( WLC );
		}
		else if ( WLC > 2 && WLC < 6 )
		{
			return 2540 + 335 * ( WLC - 2 );
		}
		else return -100001;// 数据错误
	}

	// 适用于大型薄壁半预制破片战斗部
	// WLC_All：装填系数，装药质量/(装药质量+壳体质量)；BlaseVelocity：炸药爆速
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_LargeThinWallSemiPreformed( double WLC_All , double BlaseVelocity )
	{
		return BlaseVelocity / 2 * sqrt( WLC_All / ( 2 - 4.0 / 3.0 * WLC_All ));
	}

	// 适用于火箭弹公式1
	// ShellMass：壳体质量；ChargeMass：装药质量；BlaseVelocity：炸药爆速
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_Rocket1( double ShellMass , double ChargeMass , double BlaseVelocity )
	{
		return 0.6 * BlaseVelocity * sqrt( 4 * ChargeMass / ( 5 * ( ChargeMass + 3 * ShellMass )));
	}

	// 适用于火箭弹公式2
	// WLC_All：装填系数，装药质量/(装药质量+壳体质量)；BlaseVelocity：炸药爆速
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_Rocket2( double WLC_All , double BlaseVelocity )
	{
		return BlaseVelocity / 2.03 * sqrt( 1 / WLC_All - 0.5 );
	}

	//***************************************************************
	// 得到破片平均质量方法（基于Gurney和Sarmousakis方法）(编写：徐豫新，测试：)
	double WarheadFragmentGroupPower::ComputeFragmentAverageMass_OnGurAndSar(double KK, double tt, double dd, double Me, double Mf)
	{// KK：取决于炸药的系数，(kg1/2/m3/2)；tt：弹壳平均壁厚，(m)；弹壳平均内径，(m)；装药质量，(kg)；壳体质量，(kg)。
		double FragmentM = 0;
		FragmentM = pow( KK * tt * pow( tt + dd , 3.0 / 2.0) * pow( 1 + 0.5 * Me / Mf , 0.5 ) / dd , 2 );

		return FragmentM;
	}
	// 得到破片平均质量方法（基于壳体质量和破片数量）(编写：徐豫新，测试：)
	double WarheadFragmentGroupPower::ComputeFragmentAverageMass_OnFragAllNum(double kk, double ShellMass, double FragmentNumber)
	{//kk：弹体质量损失系数(大于0,小于等于1)；ShellMass：壳体质量,(kg)；FragmentNumber：破片总数,(N)
		double FragmentAverageMass = 0;
		if ( ( kk > 1 ) && ( kk < 0 ) )
		{
			FragmentAverageMass = -10002;
		} 
		else
		{
			FragmentAverageMass = kk * ShellMass / FragmentNumber;
		}
		return FragmentAverageMass;
	}

	// 得到破片平均质量方法（基于Mott方法）
	// Det：壳体壁厚，cm；d0：壳体内径，mm；K：炸药常数，g^(1/2)/cm^(7/6)
	double WarheadFragmentGroupPower::ComputeFragmentAverageMass_OnMott( double ShellThickness , 
		double d0 , double K )
	{
		double FragmentAverageMass = 0;
		FragmentAverageMass = pow( K * pow( ShellThickness , 5.0 / 6.0 )
			* pow( d0 , 1.0 / 3.0) * ( 1 + ShellThickness / d0 ), 2 );
		return FragmentAverageMass;
	}

	// 得到破片总数计算方法(基于平均质量)（终点效应书P66）
	int WarheadFragmentGroupPower::ComputeFragmentNumber_OnAvMass(double ShellMass, 
		double FragmentAverageMass)
	{// ShellMass：壳体质量,(kg)；FragmentAverageMass：破片平均质量,(kg)
		return int ( ShellMass / FragmentAverageMass );
	}

	// 得到破片数量总数2（适合榴弹）
	int WarheadFragmentGroupPower::ComputeFragmentNumber_2(double aa, 
		double WholeMass, double WLC)
	{//aa：系数，WholeMass：弹体总质量，WLC：装填系数
		return int( );
	}

	// 大于某一质量破片累计数量（Mott）（编写：徐豫新，测试：）
	int WarheadFragmentGroupPower::ComputeOneMassFragmentN_Mott(int FragmentN0, 
		double OneMassFragment, double FragmentAverageMass)
	{// FragmentN0：破片总数,(枚)；OneMassFragment，某一破片质量，(g)；
		//FragmentAverageMass，破片平均质量，(g)
		return int ( FragmentN0 * exp( - sqrt( OneMassFragment / FragmentAverageMass ) ) );
	}

	// 大于某一质量破片累计数量方法2（自己）（编写：徐豫新，测试：）
	int WarheadFragmentGroupPower::ComputeOneMassFragmentN_2(int FragmentN0, 
		double OneMassFragment, double aa, double bb)
	{
		return int( FragmentN0 * exp( -aa * pow( OneMassFragment , bb ) ) );
	}

	// 质量小于或等于某一质量的破片总质量（held）（编写：徐豫新，测试：）
	double WarheadFragmentGroupPower::ComputeOneMassFragmentMass_Held(double kk, 
		double ShellMass, double OneMassFragment, double aa, double bb)
	{// kk：弹体质量损失系数(大于0,小于等于1)；ShellMass：壳体质量，(g)
		double FragmentMassLessthanOneValue = 0;
		
		if ( ( kk > 1 ) && ( kk < 0 ) )
		{
			FragmentMassLessthanOneValue = -10002;
		} 
		else
		{
			FragmentMassLessthanOneValue = kk * ShellMass * ( 1 - exp( - bb * pow(  OneMassFragment , aa ) ) );
		}
		return FragmentMassLessthanOneValue;
	}
	//计算破片动态飞散速度
	double WarheadFragmentGroupPower::ComputeFragmentDynamicFlyVelocity( 
		double AmmunitionVelocity , double FragmentVelocity , double FlyDirectionAngle )
	{
		double FragmentDynamicFlyVelocity = 0;
			FragmentDynamicFlyVelocity = sqrt ( FragmentVelocity * FragmentVelocity 
				+ AmmunitionVelocity * AmmunitionVelocity 
				+ 2 * FragmentVelocity * AmmunitionVelocity * cos( pi - FlyDirectionAngle ) );
		return FragmentDynamicFlyVelocity;
	}

	//计算破片迎风面积
	//ShapeCoefficient：形状系数，m^2/kg^(2/3)
	//FragmentMass：破片质量，kg
	double WarheadFragmentGroupPower::ComputeFragmentWindwardArea( 
		double ShapeCoefficient , double FragmentMass )
	{
		double WindwardArea = 0;
		WindwardArea = ShapeCoefficient * pow( FragmentMass , 2.0 / 3.0 );
		return WindwardArea;
	}

	//计算速度衰减系数
	//ResistanceCoefficient：大气阻力系数；EncounterHeight：遭遇点高度，km；
	//WindwardArea：迎风面积，m^2；FragmentMass：破片质量，kg
	double WarheadFragmentGroupPower::ComputeFragmentVelocityReductionCoefficient( 
		double ResistanceCoefficient , double EncounterHeight , double WindwardArea ,
		double FragmentMass )
	{
		//定义速度衰减系数
		double VelocityReductionCoefficient = 0;
		//计算相对空气密度
		double RelativeAirDensity = AtmosphereAttribute::instance().GetAtmosphereDensity( 
			EncounterHeight ) / AirDensityInSeaPlane;
		//计算速度衰减系数
		VelocityReductionCoefficient = ResistanceCoefficient * AirDensityInSeaPlane 
			* RelativeAirDensity * WindwardArea / 2.0 / FragmentMass;
		return VelocityReductionCoefficient;
	}

	//由初速、距离计算破片的末端速度（输出：m/s）
	//FragmentInitialVelocity：破片初始速度，m/s；
	//FragmentVelocityReductionCoefficient：破片速度衰减系数；
	//FragmentFlyDistance：破片飞行距离，m
	double WarheadFragmentGroupPower::ComputeFragmentTerminalVelocityOnIni( 
		double FragmentInitialVelocity , double FragmentVelocityReductionCoefficient , 
		double FragmentFlyDistance )
	{
		double FragmentTerminalVelocity = 0;
		FragmentTerminalVelocity = FragmentInitialVelocity * exp( - FragmentVelocityReductionCoefficient 
			* FragmentFlyDistance );
		return FragmentTerminalVelocity;
	}

		//****************计算破片的弹道极限速度******************************************************
	//公式一（德玛尔公式），计算结果单位为m/s
	//ReviseIndexA：修正系数，2000-2600；FragmentDiameter：破片直径，dm；
	//FragmentMass：破片质量，kg；BoardThickness：靶板厚度，dm；
	//HitAngle：着靶角度，度
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_Demar(
		double ReviseIndexA , double FragmentDiameter ,
		double FragmentMass , double BoardThickness , double HitAngle )
	{
		AdvancedMath TheAdvancedMath;
		double BallisticLimitVelocity;
		BallisticLimitVelocity = ReviseIndexA * pow( FragmentDiameter , 0.75 ) 
			/ pow( FragmentMass , 0.5 ) * pow( BoardThickness , 0.7 ) 
			/ cos( TheAdvancedMath.AngleToRadian( HitAngle ));
		return BallisticLimitVelocity;
	}

	//公式二（Johns Hopkins大学）
	//IndexK,IndexAlpha,IndexBeta,IndexGamma：与材料特性相关的系数；
	//BoardThickness：靶板厚度，cm；
	//FragmentAverageContactArea：破片平均着靶面积，cm^2；
	//FragmentMass：破片质量，g；HitAngle：着靶角度，度
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_Hopkins(
		double IndexK , double IndexAlpha , double IndexBeta , double IndexGamma , 
		double BoardThickness , double FragmentAverageContactArea , 
		double FragmentMass , double HitAngle )
	{
		double BallisticLimitVelocity;
		BallisticLimitVelocity = IndexK * pow( BoardThickness * 
			FragmentAverageContactArea , IndexAlpha ) * 
			pow( FragmentMass , IndexBeta ) * pow( 1.0 /
			cos( AdvancedMath::AngleToRadian( HitAngle )) , IndexGamma );
		return BallisticLimitVelocity;
	}

	//公式三（黄长强）
	//IndexA，IndexB：取决于弹靶条件的系数；BoardThickness：靶板厚度，m；
	//FragmentDiameter：破片直径，m；
	//BoardDensity：靶板材料密度，kg/m^3；FragmentDensity：破片材料密度，kg/m^3；
	//BoardBreakingPoint：靶板强度极限，MPa
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_HuangCQ( 
		double IndexA , double IndexB , double BoardThickness ,
		double FragmentDiameter , double BoardDensity , double FragmentDensity ,
		double BoardBreakingPoint )
	{
		double BallisticLimitVelocity;
		BallisticLimitVelocity = IndexA * pow( BoardThickness / FragmentDiameter ,
			IndexB ) * pow( BoardDensity , 0.3 ) 
			/ pow( FragmentDensity , 0.8 ) * pow( BoardBreakingPoint , 0.5 );
		return BallisticLimitVelocity;
	}

	//公式四（陈志斌-钨合金实验，靶材需确认），计算结果单位为m/s
	//BoardThickness：靶板厚度，mm；BoardYieldLimit：靶板屈服极限，Pa；BoardDensity：靶板密度，kg/m^3；
	//FragmentDensity：破片密度，kg/m^3；FragmentDiameter：破片直径，mm
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_ChenZB(
		double BoardThickness , double BoardYieldLimit ,
		double BoardDensity , double FragmentDensity , double FragmentDiameter )
	{
		double BallisticLimitVelocity;
		if ( BoardThickness / FragmentDiameter < 1 )
		{
			BallisticLimitVelocity = 0.0728 * pow( BoardThickness , 0.81 ) *
				pow( BoardYieldLimit , 0.5 ) * pow( BoardDensity , 0.7 ) / 
				pow( FragmentDiameter , 0.87 ) / pow( FragmentDensity , 0.7 );
		}
		else
		{
			BallisticLimitVelocity = 0.0153 * pow( BoardThickness , 1.5 ) *
				pow( BoardYieldLimit , 0.5 ) * pow( BoardDensity , 0.7 ) / 
				pow( FragmentDiameter , 0.87 ) / pow( FragmentDensity , 0.7 );
		}
		return BallisticLimitVelocity;
	}

	//公式五（午新民），计算结果单位为m/s
	//BoardThickness：靶板厚度，m；FragmentDiameter：破片直径，m；BoardDensity：靶板材料密度，kg/m^3；
	//FragmentDensity：破片材料密度，kg/m^3；BoardBreakingPoint：靶板强度极限，MPa；FragmentBreakingPoint：破片强度极限，Mpa
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_WuXM( 
		double BoardThickness , double FragmentDiameter ,
		double BoardDensity , double FragmentDensity , double BoardBreakingPoint , 
		double FragmentBreakingPoint , double HitAngle )
	{
		double BallisticLimitVelocity;
		if ( HitAngle == 0 )
		{
			BallisticLimitVelocity = 1202 * pow( BoardThickness / 
				FragmentDiameter , 1.23 ) * pow( BoardDensity / FragmentDensity ,
				0.7 ) * pow( BoardBreakingPoint / FragmentBreakingPoint , 0.15 );
		}
		else
		{
			BallisticLimitVelocity = 1022 * pow( BoardThickness / FragmentDiameter ,
				1.23 ) * pow( BoardDensity / FragmentDensity , 0.7 ) * pow( 
				BoardBreakingPoint / FragmentBreakingPoint , 0.15 ) 
				* pow( 1.0 / cos(AdvancedMath::AngleToRadian( HitAngle )) , 0.85 );
		}
		return BallisticLimitVelocity;
	}


	//对于93W钨合金破片的实验仿真拟合公式(Q235A钢)，计算结果单位为m/s
	//FragmentDiameter：破片直径，m；BoardThickness：靶板厚度，m
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_93W( 
		double FragmentDiameter , double BoardThickness )
	{
		double BallisticLimitVelocity;
		if ( FragmentDiameter / BoardThickness > 0.3 && FragmentDiameter / BoardThickness < 1.2 )
		{
			BallisticLimitVelocity = 575.7 * pow( FragmentDiameter / BoardThickness , -1.213 );
		} 
		else
		{
			BallisticLimitVelocity = -10000001;//参数不在公式适用范围
		}
		return BallisticLimitVelocity;
	}

	//对于95W钨合金破片的实验仿真拟合公式(Q235A钢)，计算结果单位为m/s
	//FragmentDiameter：破片直径，m；BoardThickness：靶板厚度，m
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_95W(
		double FragmentDiameter , double BoardThickness )
	{
		double BallisticLimitVelocity;
		if ( FragmentDiameter / BoardThickness > 0.4 && FragmentDiameter / 
			BoardThickness < 1.3 )
		{
			BallisticLimitVelocity = 566.35 * pow( FragmentDiameter / 
				BoardThickness , -1.203 );
		} 
		else
		{
			BallisticLimitVelocity = -10000001;//参数不在公式适用范围
		}
		return BallisticLimitVelocity;
	}
}

