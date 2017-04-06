#include "SpaceGeometry.h"
#include <math.h>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{
	SpaceGeometry::SpaceGeometry(void)
	{
	}

	SpaceGeometry::~SpaceGeometry(void)
	{
	}

	//测试 空间几何类 中的成员函数
	double SpaceGeometry::testSpaceGeometryClass(double di, double dj)
	{
		return sqrt(di*di+dj*dj);//返回两个数的几何平均值
	}

	// 计算空间内两条线的夹角
	double SpaceGeometry::AngleInTwoLine( double LineOne_i , double LineOne_j , double LineOne_k , double LineTwo_i , double LineTwo_j , double LineTwo_k )
	{
		return 1;
	}

	//******************几何结构体积计算*******************
	//计算圆台的体积
	double SpaceGeometry::ComputeFrustumOfAConeVolume( double R , double r , double H )
	{
		double Volume = ( 1.0 / 3.0 ) * pi * ( R * R + R * r + r * r );
		return Volume;
	}
	//计算半圆台的体积（基于几何坐标量）
	//R：大圆半径、r：小圆半径，H：高
	double SpaceGeometry::ComputeHalfFrustumOfAConeVolume( double R , double r , double H )
	{
		double Volume = ( 1.0 / 3.0 ) * pi * ( R * R + R * r + r * r ) / 2.0;
		return Volume;
	}
	//计算圆柱体的体积
	double SpaceGeometry::ComputeCylinderVolume( double Diameter , double Height )
	{
		double Volume = Height * pi * ( Diameter * Diameter / 4 );
		return Volume;
	}
	//计算球形体积
	double SpaceGeometry::ComputeSphereVolume( double Diameter )
	{
		double Volume = 4.0 * pi * pow( Diameter / 2 , 3 ) / 3.0;
		return Volume;
	}
	//由球体积计算球半径
	double SpaceGeometry::ComputeSphereRadiusOnVolume( double Volume )
	{
		double Radius = pow( Volume * 3.0 / 4.0 / pi , 1.0 / 3.0 );
		return Radius;
	}
	//就算球形体积(基于球的质量和密度),输出体积，单位：cm^3
	//Mass：质量，g；Density：密度，g/cm^3
	double SpaceGeometry::ComputeVolumeOnMassAndDensity( 
		double Mass , double Density )
	{
		double Volume = 0;
		Volume = Mass / Density;
		return Volume;
	}
	//计算半圆柱体的体积（基于几何坐标量）
	//Diameter：圆直径、Height：高;Thickness：空心圆柱体厚度
	double SpaceGeometry::ComputeHalfCylinderVolume( double Diameter , double Height )
	{
		double Volume = Height * pi * ( Diameter * Diameter / 4 ) / 2.0;
		return Volume;
	}
	//计算圆锥体的体积（基于几何坐标量）
	//Radius：底圆半径、Height：高;Thickness：空心圆锥体厚度，体现在底圆面上
	double SpaceGeometry::ComputeConeVolume( double Radius , double Height )
	{
		double Volume = 1.0 / 3.0 * Height * pi * Radius * Radius;
		return Volume;
	}
	//计算半圆锥体的体积（基于几何坐标量）
	//Radius：底圆半径、Height：高;Thickness：空心圆锥体厚度，体现在底圆面上
	double SpaceGeometry::ComputeHalfConeVolume( double Radius , double Height )
	{
		double Volume = 1.0 / 3.0 * Height * pi * Radius * Radius / 2.0;
		return Volume;
	}

	//计算长方体的体积（基于几何坐标量）
	double SpaceGeometry::ComputeCuboidVolume( double XLength , double YLength 
		, double ZLength )
	{
		return XLength * YLength * ZLength;
	}

	//判断一条线上的三个点中一个点是否在两个点之间
	bool SpaceGeometry::JudgePointSiteBetweenTwoPoint( CoordinatesPosition JudgePoint ,
		CoordinatesPosition FristPoint, CoordinatesPosition SecondPoint )
	{
		bool Judge = NULL;

		CoordinatesPosition TheCoordinatesPosition;
		// 计算判断点和第一个点的距离
		double Distance_JF = JudgePoint.Distance(FristPoint);
		// 计算判断点和第二个点的距离
		double Distance_JS = JudgePoint.Distance(SecondPoint);
		// 计算第一个点和第二个点之间的距离
		double Distance_FS = FristPoint.Distance(SecondPoint);

		if( abs(Distance_JF + Distance_JS - Distance_FS ) < 0.00000001 )
		{
			Judge = true;
		}
		else Judge = false;
		return Judge;
	}

}
