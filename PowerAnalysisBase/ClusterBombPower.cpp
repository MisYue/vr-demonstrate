#include "ClusterBombPower.h"

namespace BIT
{
	ClusterBombPower::ClusterBombPower(
		CoordinatesPosition IniCoordPos_M ,
		CoordinatesPosition IniCoordPos_T ,
		CoordinatesPosition TerCoordPos_M ,
		CoordinatesPosition TerCoordPos_T ,
		bool EmbedTarget ,
		double Velocity )
	{
		// 弹体坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_M = IniCoordPos_M;
		// 单枚破片目标坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_T = IniCoordPos_T;
		// 弹体坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_M = TerCoordPos_M;
		// 单枚破片目标坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_T = TerCoordPos_T;
		// 是否嵌入目标
		SubAmmuniEmbedTarget = EmbedTarget;
		//子弹速度
		SubAmmuniVelocity = Velocity;
	}
	// 拷贝构造函数
	ClusterBombPower::ClusterBombPower( const ClusterBombPower& CBP )
	{
		//弹体坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_M = CBP.InitializeCoordinatesPosition_M;
		// 单枚破片目标坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_T = CBP.InitializeCoordinatesPosition_T;
		// 弹体坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_M = CBP.TerminalCoordinatesPosition_M;
		// 单枚破片目标坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_T = CBP.TerminalCoordinatesPosition_T;
		// 是否嵌入目标
		SubAmmuniEmbedTarget = CBP.SubAmmuniEmbedTarget;
		// 子弹速度
		SubAmmuniVelocity = CBP.SubAmmuniVelocity;
	}


	ClusterBombPower::~ClusterBombPower(void)
	{
	}

	//测试 子母弹威力参数分析类 中的成员函数
	double ClusterBombPower::testClusterBombPowerClass(double di, double dj)
	{
		AdvancedMath aMath;
		double res = aMath.testAdvancedMathClass(0.001, 1000.0);
		return di+dj;//返回两个数的和
	}
	//设置弹体坐标系内坐标(起点),mm
	const void ClusterBombPower::SetSubIniCoordinatesPositionPoint_M( 
		const CoordinatesPosition &ICPP_M )
	{
		InitializeCoordinatesPosition_M = ICPP_M;
	}
	//设置目标坐标系内坐标(终点)，mm
	const void ClusterBombPower::SetSubIniCoordinatesPositionPoint_T( 
		const CoordinatesPosition &ICPP_T )
	{
		InitializeCoordinatesPosition_T = ICPP_T;
	}
	//设置弹体坐标系内坐标(终点),mm
	const void ClusterBombPower::SetSubTerCoordinatesPositionPoint_M( 
		const CoordinatesPosition &TCPP_M )
	{
		TerminalCoordinatesPosition_M = TCPP_M;
	}
	//设置目标坐标系内坐标(终点)，mm
	const void ClusterBombPower::SetSubTerCoordinatesPositionPoint_T( 
		const CoordinatesPosition &TCPP_T )
	{
		// 单枚破片目标坐标系内坐标,mm
		TerminalCoordinatesPosition_T = TCPP_T;
	}
	//设置子弹是否嵌入目标
	const void ClusterBombPower::SetSubAmmuniEmbedTarget( const bool &AET )
	{
		SubAmmuniEmbedTarget = AET;
	}

	//设置子弹速度
	const void ClusterBombPower::SetSubAmmuniVelocity( const double &SAV )
	{
		if( SAV < 0)
		{
			SubAmmuniVelocity = 0;
		}
		else
			SubAmmuniVelocity = SAV;
	}

	//得到弹体坐标系内坐标(起点),mm
	const CoordinatesPosition ClusterBombPower::GetSubIniCoordinatesPositionPoint_M( void ) const
	{
		return InitializeCoordinatesPosition_M;
	}
	//得到目标坐标系内坐标(起点)，mm
	const CoordinatesPosition ClusterBombPower::GetSubIniCoordinatesPositionPoint_T( void ) const
	{
		return InitializeCoordinatesPosition_T;
	}
	//得到弹体坐标系内坐标(终点),mm
	const CoordinatesPosition ClusterBombPower::GetSubTerCoordinatesPositionPoint_M( void ) const
	{
		return TerminalCoordinatesPosition_M;
	}
	//得到目标坐标系内坐标(终点),mm
	const CoordinatesPosition ClusterBombPower::GetSubTerCoordinatesPositionPoint_T( void ) const
	{
		return TerminalCoordinatesPosition_T;
	}
	// 得到子弹嵌入目标
	const bool ClusterBombPower::GetSubAmmuniEmbedTarget( void ) const
	{
		return SubAmmuniEmbedTarget;
	}
	// 得到子弹速度
	const double ClusterBombPower::GetSubAmmuniVelocity( void ) const
	{
		return SubAmmuniVelocity;
	}
}