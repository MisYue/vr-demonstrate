/************************************************
	名称：破甲威力参数分析 ShapedChargePower
	功能：计算聚能装药战斗部形成聚能侵彻体的速度等
	创建人：
	创建时间：
	版本：1.0
*************************************************/

#pragma once
#include "poweranalysisbase_global.h"
#include <math.h>
#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{
	class POWERANALYSISBASE_EXPORT ShapedChargePower
	{
	public:
		ShapedChargePower(void);
		~ShapedChargePower(void);

		//测试 破甲威力参数分析类 中的成员函数
		double testShapedChargePowerClass(double di, double dj);

		//射流的侵彻计算公式
		// 定常理论计算侵彻速度（终点效应学P245页）
		// JetLength：射流长度，JetDensity：射流密度，TargetDensity：靶体密度
		double JetPenetrationDeepness( double JetLength , double JetDensity 
			, double TargetDensity );

		// 适用于断裂射流的侵彻深度计算公式，终点效应书P246
		// JetLength：射流长度，JetDensity：射流密度，TargetDensity：靶体密度，Lumbda：连续射流取1，断裂射流取2
		double JetPenetrationDeepnessByLumbda( double JetLength , double JetDensity 
			, double TargetDensity , int Lumbda );

		// 考虑靶板强度的侵彻深度公式，终点效应书P246
		// JetLength：射流长度，JetDensity：射流密度，TargetDensity：靶体密度，TargetYield：靶板屈服强度，TargetYield：射流速度，alpha：常数，为射流和靶板密度的函数
		double JetPenetrationDeepnessByTargetYield( double JetLength , double JetDensity 
			, double TargetDensity , double TargetYield , double JetVelocity , double alpha );

		//计算EFP侵彻深度
		//EFPMass：EFP质量，kg；EFPVelocity，EFP速度，m/s；EFPDiameter：EFP直径，m
		//返回：mm
		double EFPPenetrationDeepness( double EFPMass, double EFPVelocity 
			, double EFPDiameter);
	};

}

