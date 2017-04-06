/************************************************
	名称：子母弹威力参数分析 ClusterBombPower
	功能：计算子弹散布半径、子弹散布密度等
	创建人：
	创建时间：
	版本：1.0
*************************************************/

#pragma once
#include "poweranalysisbase_global.h"
#include "MathCalculationSupport/AdvancedMath.h"
#include <math.h>
#include "MathCalculationSupport/CoordinatesPosition.h"

namespace BIT
{
	class POWERANALYSISBASE_EXPORT ClusterBombPower
	{
	public:
		ClusterBombPower(
			CoordinatesPosition IniCoordPos_M = ( 0 , 0 , 0) ,
			CoordinatesPosition IniCoordPos_T = ( 0 , 0 , 0) ,
			CoordinatesPosition TerCoordPos_M = ( 0 , 0 , 0) ,
			CoordinatesPosition TerCoordPos_T = ( 0 , 0 , 0) ,
			bool EmbedTarget = false ,
			double Velocity = 0
			);
		~ClusterBombPower(void);

		// 拷贝构造函数
		ClusterBombPower( const ClusterBombPower& CBP);

		//测试 子母弹威力参数分析类 中的成员函数
		double testClusterBombPowerClass(double di, double dj);

		//设置弹体坐标系内坐标(起点),mm
		const void SetSubIniCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//设置目标坐标系内坐标(起点)，mm
		const void SetSubIniCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//设置弹体坐标系内坐标(终点),mm
		const void SetSubTerCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//设置目标坐标系内坐标(终点)，mm
		const void SetSubTerCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//设置子弹是否嵌入目标
		const void SetSubAmmuniEmbedTarget( const bool & );
		//设置子弹速度,m/s
		const void SetSubAmmuniVelocity( const double &);

		//得到弹体坐标系内坐标(起点),mm
		const CoordinatesPosition GetSubIniCoordinatesPositionPoint_M( void ) const;
		//得到目标坐标系内坐标(起点)，mm
		const CoordinatesPosition GetSubIniCoordinatesPositionPoint_T( void ) const;
		//得到弹体坐标系内坐标(终点),mm
		const CoordinatesPosition GetSubTerCoordinatesPositionPoint_M( void ) const;
		//得到目标坐标系内坐标(终点),mm
		const CoordinatesPosition GetSubTerCoordinatesPositionPoint_T( void ) const;
		// 得到子弹是否入目标
		const bool GetSubAmmuniEmbedTarget( void ) const;
		// 得到子弹速度，m/s
		const double GetSubAmmuniVelocity( void ) const;

	private:

		//弹个子弹弹体坐标系内坐标（起点）,mm
		CoordinatesPosition InitializeCoordinatesPosition_M;
		//弹个子弹目标坐标系内坐标（起点）,mm
		CoordinatesPosition InitializeCoordinatesPosition_T;
		//弹个子弹坐标系内坐标（终点）,mm
		CoordinatesPosition TerminalCoordinatesPosition_M;
		//弹个子弹破片目标坐标系内坐标（终点）,mm
		CoordinatesPosition TerminalCoordinatesPosition_T;
		//子弹是否实现侵入或嵌入目标达到封锁目的
		bool SubAmmuniEmbedTarget;
		//子弹药的落速,m/s
		double SubAmmuniVelocity;
	};

}

