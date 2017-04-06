#include "ShapedChargePower.h"

namespace BIT
{

	ShapedChargePower::ShapedChargePower(void)
	{
	}


	ShapedChargePower::~ShapedChargePower(void)
	{
	}

	//测试 破甲威力参数分析类 中的成员函数
	double ShapedChargePower::testShapedChargePowerClass(double di, double dj)
	{
		return di+dj;//返回两个数的和 
	}
	// 定常理论计算侵彻速度（终点效应学P245页）
	double ShapedChargePower::JetPenetrationDeepness( double JetLength , double JetDensity , double TargetDensity )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = JetLength * sqrt( JetDensity / TargetDensity );
		return PenetrationDeepness;
	}

	// 适用于断裂射流的侵彻深度计算公式，终点效应书P246
	// JetLength：射流长度，JetDensity：射流密度，TargetDensity：靶体密度，Lumbda：连续射流取1，断裂射流取2
	double ShapedChargePower::JetPenetrationDeepnessByLumbda( double JetLength , double JetDensity , double TargetDensity , int Lumbda )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = JetLength * sqrt( Lumbda * JetDensity / TargetDensity );
		return PenetrationDeepness;
	}

	// 考虑靶板强度的侵彻深度公式，终点效应书P246
	// JetLength：射流长度，JetDensity：射流密度，TargetDensity：靶体密度，TargetYield：靶板屈服强度，TargetYield：射流速度，alpha：常数，为射流和靶板密度的函数
	double ShapedChargePower::JetPenetrationDeepnessByTargetYield( double JetLength , double JetDensity , double TargetDensity , double TargetYield , double JetVelocity , double alpha )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = JetLength * sqrt( JetDensity / TargetDensity ) * 
			( 1 - alpha * TargetYield / ( JetDensity * JetVelocity * JetVelocity ));
		return PenetrationDeepness;
	}

	//计算EFP侵彻深度(输出量纲为m,701所报告2010年P89)
	//EFPMass：EFP质量，kg；EFPVelocity，EFP速度，m/s；EFPDiameter：EFP直径，m
	//输出为mm
	double ShapedChargePower::EFPPenetrationDeepness( double EFPMass,
		double EFPVelocity , double EFPDiameter )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = 2.0 * EFPMass 
			* pow( EFPVelocity / EFPDiameter , 2 ) * 1e-9/ 3.0 /pi;
		return PenetrationDeepness;
	}

}