/************************************************
	名称：侵彻威力参数分析 WarheadPenetrationPower
	功能：计算导弹战斗部对舱体的侵彻威力，即：侵过舱壁面后的剩余速度
	创建人：
	创建时间：
	版本：1.0
*************************************************/

#pragma once
#include "poweranalysisbase_global.h"

namespace BIT
{
	enum PenThickFormulaType{ DeMarre };

	class POWERANALYSISBASE_EXPORT WarheadPenetrationPower
	{
	public:
		WarheadPenetrationPower(void);
		~WarheadPenetrationPower(void);

		//测试 侵彻威力参数分析 中的成员函数
		static double testWarheadPenetrationPowerClass(double di, double dj);

		// 由入速和弹道极限计算剩余速度（基于能量守恒）
		// 1. 弹体质量(初始,kg),2.弹体质量(回收,kg),3.靶体塞块质量(,kg),4.初速(m/s)，5.V50(m/s)
		static double ComputeReVelOnV50AndVin( const double & , const double & , const double &
			, const double & , const double &);

		//计算尖头弹侵彻后的剩余速度 终点效应书P155
		//CIV：尖头弹初速,m/s；CWM：尖头弹质量,kg；CTIK：尖头弹实验系数K,一般取1~1.5；CFPD：截锥形弹平顶部分直径,m；CWD：尖头弹圆柱部分直径,m；
		//CHC：尖头弹半锥角,度；MD：靶板材料密度,kg/m^3；BT：靶板厚度,m；ICA：弹头着角,度
		static double ComptCReminingVelocity( double CIV , double CWM , double CTIK , double CFPD , double CWD , double CHC , 
			double MD ,double BT , double ICA );
		//计算卵形弹侵彻后的剩余速度 德玛尔公式
		//OIV：卵形弹初速,m/s；OWM：卵形弹质量,kg；OWD：卵形弹圆柱部分直径,m；ORIA：卵形弹修正系数A,一般为2400；BT：靶板厚度,m；ICA：弹头着角,度
		static double ComptOReminingVelocity( double OIV , double OWM , double OWD , double ORIA , double BT , double ICA );
		
		//计算弹体侵彻深度(mm) 德玛尔公式(终点效应P136)
		//1.弹体质量,kg；2.侵彻速度,m/s；3.着角;4.直径,mm；5.系数a(DeMarre);6.系数b(DeMarre)
		static double ComputePenetrationThickness( const double & , const double & 
			, const double & , const double & , const double & , const double & );

	};

}

