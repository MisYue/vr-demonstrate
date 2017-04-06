/************************************************
	名称：空间几何 SpaceGeometry
	功能：支撑进行空间坐标定义、转换等计算
	创建人：
	创建时间：
	版本：1.0
*************************************************/

#pragma once
#include "MathCalculationSupport_Global.h"
#include "CoordinatesPosition.h"


namespace BIT
{
	class MATHCALCULATIONSUPPORT_API SpaceGeometry
	{
	public:
		SpaceGeometry(void);
		~SpaceGeometry(void);

		static double testSpaceGeometryClass(double di, double dj);	//测试 空间几何类 中的成员函数

		// 计算空间内两条线的夹角，输入弧度
		static double AngleInTwoLine( double LineOne_i , double LineOne_j , 
			double LineOne_k , double LineTwo_i , double LineTwo_j , double LineTwo_k );
		
		//判断一条线上的三个点中一个点是否在两个点之间
		static bool JudgePointSiteBetweenTwoPoint( CoordinatesPosition JudgePoint ,
			CoordinatesPosition FristPoint, CoordinatesPosition SecondPoint);

		//******************几何结构体积计算*******************
		//计算圆台的体积（基于几何坐标量）
		//R：大圆半径、r：小圆半径，H：高
		static double ComputeFrustumOfAConeVolume( double R , double r , double H );
		//计算半圆台的体积（基于几何坐标量）
		//R：大圆半径、r：小圆半径，H：高
		static double ComputeHalfFrustumOfAConeVolume( double R , double r , double H );
		//计算圆柱体的体积（基于几何坐标量）
		//Diameter：圆直径、Height：高
		static double ComputeCylinderVolume( double Diameter , double Height );
		//计算半圆柱体的体积（基于几何坐标量）
		//Diameter：圆直径、Height：高
		static double ComputeHalfCylinderVolume( double Diameter , double Height );
		//计算圆锥体的体积（基于几何坐标量）
		//Radius：底圆半径、Height：高
		static double ComputeConeVolume( double Radius , double Height );
		//计算半圆锥体的体积（基于几何坐标量）
		//Radius：底圆半径、Height：高
		static double ComputeHalfConeVolume( double Radius , double Height );
		//计算球形体积（基于几何坐标量）
		static double ComputeSphereVolume( double Diameter );
		//计算长方体的体积（基于几何坐标量）
		static double ComputeCuboidVolume( double XLength , double YLength , double ZLength );

		///******************由物理量求计算*******************
		//计算体积(基于质量和密度)
		//Mass：质量，g；Density：密度，g/cm^3
		static double ComputeVolumeOnMassAndDensity( double Mass , double Density );
		
		//******************由体积计算几何物理量*******************
		//由球体积计算球半径
		static double ComputeSphereRadiusOnVolume( double Volume );
	};

}

