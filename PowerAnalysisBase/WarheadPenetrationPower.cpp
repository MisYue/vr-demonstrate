#include "WarheadPenetrationPower.h"
#include <cmath>
#include <MathCalculationSupport/AdvancedMath.h>
#include <MathCalculationSupport/UnitsTransform.h>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{
	WarheadPenetrationPower::WarheadPenetrationPower(void)
	{
	}


	WarheadPenetrationPower::~WarheadPenetrationPower(void)
	{
	}

	//测试 侵彻威力参数分析 中的成员函数
	double WarheadPenetrationPower::testWarheadPenetrationPowerClass(double di, double dj)
	{
		return di+dj;//返回两个数的和
	}


	//计算尖头弹侵彻后剩余速度 终点效应书P155
	double WarheadPenetrationPower::ComptCReminingVelocity( double CIV , double CWM , double CTIK , double CFPD , double CWD , 
		double CHC , double MD ,double BT , double ICA )
	{//CIV：尖头弹初速,m/s；CWM：尖头弹质量,kg；CTIK：尖头弹实验系数K；CFPD：截锥形弹平顶部分直径,m；
		//CWD：尖头弹圆柱部分直径,m；
		//CHC：尖头弹半锥角,度；MD：靶板材料密度,kg/m^3；BT：靶板厚度,m；
		//ICA：弹头着角,度；CReminingVelocity：尖头弹剩余速度
		double CReminingVelocity = CIV * ( 1 - ( pi * MD * BT 
			/ cos( AdvancedMath::AngleToRadian( ICA ))) / ( 4 * CWM ) * ( CTIK * CFPD
			* CFPD + ( CWD * CWD - CFPD * CFPD ) * sin( AdvancedMath::AngleToRadian( CHC ))));
		return CReminingVelocity;
	}

	//计算卵形弹侵彻后剩余速度 德玛尔公式
	double WarheadPenetrationPower::ComptOReminingVelocity( double OIV , double OWM , double OWD , double ORIA , double BT , double ICA )
	{//OIV：卵形弹初速,m/s；OWM：卵形弹质量,kg；OWD：卵形弹圆柱部分直径,m；ORIA：卵形弹修正系数A,一般为2400；BT：靶板厚度,m；
		//ICA：弹头着角,度；OReminingVelocity：卵形弹剩余速度
		AdvancedMath *TheAdvancedMath = new AdvancedMath();
		UnitsTransform *TheUnitsTransform = new UnitsTransform();

		double V50 = ORIA * pow( UnitsTransform::MiToDm(OWD) , 0.75 )
			* pow( UnitsTransform::MiToDm(BT) , 0.7 ) / 
			( pow( OWM , 0.5 ) * cos( AdvancedMath::AngleToRadian( ICA )));
		double OReminingVelocity = ComputeReVelOnV50AndVin( OWM , OWM , 0, OIV , V50 );

		return OReminingVelocity;
	}

	//计算弹体侵彻深度(mm) 德玛尔公式(终点效应P136)
	//1.弹体质量,kg；2.侵彻速度,m/s；3.着角;4.直径,mm；5.系数a(DeMarre);6.系数b(DeMarre)
	double WarheadPenetrationPower::ComputePenetrationThickness( const double &Mass ,
		const double &Velocity , const double &Angle , const double &Diameter , 
		const double &Coefficient_A , const double &Coefficient_B )
	{
		double Thickness = 0;
		double Temp = Mass * Velocity * Velocity * cos( AdvancedMath::AngleToRadian( Angle ) )
			* cos( AdvancedMath::AngleToRadian( Angle ) ); 
		Thickness = UnitsTransform::DmToMm(UnitsTransform::MmToDm(Diameter) *
			pow(Temp / Coefficient_A / pow( UnitsTransform::MmToDm(Diameter) , 3)
			, 1 / Coefficient_B ) ) ;
		return Thickness;
	}

	// 由入速和弹道极限计算剩余速度（基于能量守恒）
	// 1. 弹体质量(初始,kg),2.弹体质量(回收,kg),3.靶体塞块质量(,kg),4.初速(m/s)，5.V50(m/s)
	double WarheadPenetrationPower::ComputeReVelOnV50AndVin( const double &ProMass_Ini
		, const double & ProMass_over , const double &TargetStuffMass, const double &IniVelocity 
		, const double &V50 )
	{
		double ReVel = 0;
		if( ProMass_Ini == 0 && ProMass_Ini < 0 )
		{
			ReVel = 0;
		}
		else if( TargetStuffMass < 0)
		{
			ReVel = 0;
		}
		else if( ProMass_Ini < ProMass_over )
		{
			ReVel = 0;
		}
		else
		{
			if( IniVelocity < V50 )
			{
				ReVel = 0;
			}
			else
			{
				ReVel = ProMass_Ini * sqrt( IniVelocity * IniVelocity - V50 * V50 )
					/ ( ProMass_over + TargetStuffMass ) ;
			}
		}

		return ReVel;
	}

}
