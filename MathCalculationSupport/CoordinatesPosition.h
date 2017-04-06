/*
名称： 
功能： 
创建人：
创建时间：
版本：1.0
*/

#pragma once
#include "MathCalculationSupport_Global.h"

// 坐标点函数
#include <iostream>
#include "math.h"

#pragma once
using namespace std;

namespace BIT
{
	class MATHCALCULATIONSUPPORT_API CoordinatesPosition
	{
	public:
		CoordinatesPosition( double xx = 0, double yy = 0, double zz = 0 );
		CoordinatesPosition( const CoordinatesPosition& cPositon);

		~CoordinatesPosition( void );

		//*尹鹏增加 运算符重载定义赋值
		void operator= (const CoordinatesPosition& cPositon );
		bool operator == (const CoordinatesPosition& cPositon );


		// 角度转弧度
		const double AngleToRadian(const double& Angle);
		// 弧度转角度
		const double RadianToAngle(const double& Radian);

		//设置x值
		const double Set_x(const double& xx );
		//设置y值
		const double Set_y(const double& yy );
		//设置z值
		const double Set_z(const double& zz );

		// 得到点中的x值
		const double Get_x(void) const ;
		const double Get_y(void) const ;
		const double Get_z(void) const ;

		// 计算两点坐标间的距离
		const double Distance(const CoordinatesPosition& P2);
		// 计算到原点的距离
		const double DistanceOriginPosition(void);
		// 点距离XZ平面的夹角
		const double AngleWithXZPlane(void);
		// 点距离XY平面的夹角
		const double AngleWithXYPlane(void);
		// 点距离YZ平面的夹角
		const double AngleWithYZPlane(void);
		// 点-原点连线与X轴的夹角
		const double AngleWithXAxis(void);
		// 点-原点连线与Y轴的夹角
		const double AngleWithYAxis(void);
		// 点-原点连线与Z轴的夹角
		const double AngleWithZAxis(void);
		// 三维坐标轴平移
		const void CoordinatesAfterTranslation(const double& Dx, const double& Dy, const double& Dz);
		// 三维坐标绕X轴旋转
		const void RotateAngleByXAxis(const double& Angle );
		// 三维坐标绕Y轴旋转
		const void RotateAngleByYAxis(const  double& Angle );
		// 三维坐标绕Z轴旋转
		const void RotateAngleByZAxis(const  double& Angle );
		//求空间内一点P2与给定点P1连线与X轴夹角
		const double IncludedAngleOfXAxis(const CoordinatesPosition& );
		//求空间内一点P2与给定点P1连线与Y轴夹角
		const double IncludedAngleOfYAxis(const CoordinatesPosition& );
		//求空间内一点P2与给定点P1连线与Z轴夹角
		const double IncludedAngleOfZAxis(const CoordinatesPosition& );
		//求空间直线上另一点
		const CoordinatesPosition GetAnotherPoint(const CoordinatesPosition&  
		, const double& , const double& , const double&, const double&);

		////*******坐标相互转换函数*************
		//弹体坐标系向(静止)目标坐标系转换函数
		//A_PitchingAngle：导弹俯仰角（静止目标/大地坐标系），度
		//A_YawAngle：导弹偏航角（静止目标/大地坐标系），
		//CoordinateInAmmunition：在弹体坐标中的点
		//WarheadCenterPosition：战斗部中心在目标坐标系中的坐标值
		const CoordinatesPosition ComputeCoordinateInTargetFromAmmunition( 
			const double &A_PitchingAngle , const double &A_YawAngle, 
			const CoordinatesPosition &CoordinateInAmmunition ,
			const CoordinatesPosition &WarheadCenterPosition );
	
	private:
		double x;
		double y;
		double z;
	};
}