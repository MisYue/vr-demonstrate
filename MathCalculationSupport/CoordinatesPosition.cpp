#include "CoordinatesPosition.h"


#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{

	CoordinatesPosition::CoordinatesPosition( double xx, double yy, double zz ):x(xx), y(yy), z(zz)
	{
	}

	CoordinatesPosition::CoordinatesPosition( const CoordinatesPosition& cPositon)
	{
		x = cPositon.Get_x();
		y = cPositon.Get_y();
		z = cPositon.Get_z();
	}

	CoordinatesPosition::~CoordinatesPosition(void)
	{

	}

		//*尹鹏增加 运算符重载
	void CoordinatesPosition::operator= (const CoordinatesPosition& cPositon)
	{
		this->x = cPositon.Get_x();
		this->y = cPositon.Get_y();
		this->z = cPositon.Get_z();
	}

	bool CoordinatesPosition::operator == (const CoordinatesPosition& cPositon )
	{
		if ( (this->x == cPositon.Get_x()) && (this->y == cPositon.Get_y()) && (this->z == cPositon.Get_z()) )
		{
			return true;
		}else{
			return false;
		}
		
	}

	// 设置X值
	const double CoordinatesPosition::Set_x(const double& xx )
	{
		x = xx;
		return x;
	}
	// 设置Y值
	const double CoordinatesPosition::Set_y(const double& yy )
	{
		y = yy;
		return y;
	}
	// 设置Z值
	const double CoordinatesPosition::Set_z(const double& zz )
	{
		z = zz;
		return z;
	}

	// 得到点中的x值
	const double CoordinatesPosition::Get_x(void) const
	{
		return x;
	}

	// 得到点中的y值
	const double CoordinatesPosition::Get_y(void) const
	{
		return y;
	}

	// 得到点中的z值
	const double CoordinatesPosition::Get_z(void) const
	{
		return z;
	}

	// 角度转弧度（编写：徐豫新，测试：徐豫新）
	const double CoordinatesPosition::AngleToRadian(const double& Angle)
	{// Angle：输入角度

		double Radian = 0;
		Radian = ( Angle / 180 ) * pi;
		return Radian;

	}

	// 弧度转角度（编写：徐豫新，测试：徐豫新）
	const double CoordinatesPosition::RadianToAngle(const double& Radian)
	{// Radian：弧度

		double Angle = 0;
		Angle = ( Radian / pi ) * 180;
		return Angle;

	}

	// 计算两点坐标间的距离（编写：徐豫新，测试：）
	const double CoordinatesPosition::Distance(const CoordinatesPosition& P2)
	{// P2 第2个坐标点
		return sqrt( (P2.x-x) * (P2.x-x) + (P2.y-y) * (P2.y-y) + (P2.z-z) * (P2.z-z) );
	}

	// 计算到原点的距离（编写：徐豫新，测试：）
	const double CoordinatesPosition::DistanceOriginPosition(void)
	{
		return sqrt( x * x + y * y + z * z );
	}

	// 点-原点连线与XZ平面的夹角（编写：徐豫新，测试：）
	const double CoordinatesPosition::AngleWithXZPlane(void)
	{// 输出：角度
		return RadianToAngle( asin( y / sqrt( x * x + y * y + z * z ) ) );
	}

	//  点-原点连线与XY平面的夹角（编写：王潇，测试：）
	const double CoordinatesPosition::AngleWithXYPlane(void)
	{// 输出：角度
		return RadianToAngle( asin( z / sqrt( x * x + y * y + z * z ) ) );
	}

	//  点-原点连线与YZ平面的夹角（编写：王潇，测试：）
	const double CoordinatesPosition::AngleWithYZPlane(void)
	{// 输出：角度
		return RadianToAngle( asin( x / sqrt( x * x + y * y + z * z ) ) );
	}

	// 点-原点连线与X轴的夹角（编写：王潇，测试：）
	const double CoordinatesPosition::AngleWithXAxis(void)
	{// 输出：角度
		return RadianToAngle( acos( x / sqrt( x * x + y * y + z * z ) ) );
	}

	// 点-原点连线与Y轴的夹角
	const double CoordinatesPosition::AngleWithYAxis(void)
	{// 输出：角度
		return RadianToAngle( acos( y / sqrt( x * x + y * y + z * z ) ) );
	}

	// 点-原点连线与Z轴的夹角
	const double CoordinatesPosition::AngleWithZAxis(void)
	{// 输出：角度
		return RadianToAngle( acos( z / sqrt( x * x + y * y + z * z ) ) );
	}

	// 三维坐标轴平移（编写：徐豫新）
	const void CoordinatesPosition::CoordinatesAfterTranslation(const double& Dx, const  double& Dy, const double& Dz)//有修正
	{// Dx：沿X轴平移距离；Dy：沿Y轴平移距离；Dz：沿Z轴平移距离
		x = x + Dx;
		y = y + Dy;
		z = z + Dz;
	}
	// 三维坐标绕X轴旋转(正方向按照右手螺旋定则）（编写：徐豫新）
	const void CoordinatesPosition::RotateAngleByXAxis(const double& Angle )//有修正
	{// Angle:输入为角度值 
		double c ,b;
		x = x;
		b = y;
		c = z;
		y = b * cos( AngleToRadian( Angle )) - c * sin( AngleToRadian( Angle ) );
		z = b * sin( AngleToRadian( Angle )) + c * cos( AngleToRadian( Angle ) );
	}
	// 三维坐标绕Y轴旋转(正方向按照右手螺旋定则）（编写：徐豫新）
	const void CoordinatesPosition::RotateAngleByYAxis(const double& Angle )//有修正
	{// Angle:输入为角度值 
		double a ,c;
		a = x;
		c = z;
		x = a * cos( AngleToRadian( Angle )) + c * sin( AngleToRadian( Angle ) );
		y = y ;
		z = -a * sin( AngleToRadian( Angle )) + z * cos( AngleToRadian( Angle ) );
	}
	// 三维坐标绕Z轴旋转(正方向按照右手螺旋定则）
	const void CoordinatesPosition::RotateAngleByZAxis(const double& Angle )//有修正
	{// Angle:输入为角度值 
		double a , b;
		a = x;
		b = y;
		x = a * cos( AngleToRadian( Angle )) - b * sin( AngleToRadian( Angle ) );
		y = a * sin( AngleToRadian( Angle )) + b * cos( AngleToRadian( Angle ) );
		z = z;
	}
	//求空间内一点P2与给定点P1连线与X轴夹角
	const double CoordinatesPosition::IncludedAngleOfXAxis(const CoordinatesPosition& P2 )
	{
		double Angle;
		if ( x == P2.x && y == P2.y && z == P2.z )
		{
			Angle = -10001;//重合无夹角
		}
		else
		{
			Angle = RadianToAngle( acos( ( P2.x - x ) / sqrt( ( P2.x - x ) * ( P2.x - x ) + ( P2.y - y ) * ( P2.y - y ) + ( P2.z - z ) * ( P2.z - z ) ) ) ) ;
		}
		return Angle ;
	}
	//求空间内一点P2与给定点P1连线与Y轴夹角
	const double CoordinatesPosition::IncludedAngleOfYAxis(const CoordinatesPosition& P2 )
	{
		double Angle;
		if ( x == P2.x && y == P2.y && z == P2.z )
		{
			Angle = -10001;//重合无夹角
		}
		else
		{
			Angle = RadianToAngle( acos( ( P2.y - y ) / sqrt( ( P2.x - x ) * ( P2.x - x ) + ( P2.y - y ) * ( P2.y - y ) + ( P2.z - z ) * ( P2.z - z ) ) ) ) ;
		}
		return Angle ;
	}
	//求空间内一点P2与给定点P1连线与Z轴夹角
	const double CoordinatesPosition::IncludedAngleOfZAxis(const CoordinatesPosition& P2)
	{
		double Angle;
		if ( x == P2.x && y == P2.y && z == P2.z )
		{
			Angle = -10001;//重合无夹角
		}
		else
		{
			Angle = RadianToAngle( acos( ( P2.z - z ) / sqrt( ( P2.x - x ) * ( P2.x - x ) + ( P2.y - y ) * ( P2.y - y ) + ( P2.z - z ) * ( P2.z - z ) ) ) ) ;
		}
		return Angle ;

	}


	// 由参数方程和截距计算三维坐标系中的点
	const CoordinatesPosition CoordinatesPosition::GetAnotherPoint(const CoordinatesPosition& P1 
		, const double& aa , const double &bb , const double& cc , const double& LL )
	{
		CoordinatesPosition P2;
		P2.Set_x( P1.Get_x() + LL * aa );
		P2.Set_y( P1.Get_y() + LL * bb );
		P2.Set_z( P1.Get_z() + LL * cc );
		return P2;
	}

	//弹体坐标系向(静止)目标坐标系转换函数，输入角度
	const CoordinatesPosition CoordinatesPosition::ComputeCoordinateInTargetFromAmmunition(
		const double &A_PitchingAngle , const double &A_YawAngle, 
		const CoordinatesPosition &CoordinateInAmmunition 
		, const CoordinatesPosition &WarheadCenterPosition )
	{
		CoordinatesPosition CoordinatesInTarget;
		CoordinatesPosition Temp_CoordinateInAmmunition = CoordinateInAmmunition;
		// 弹体坐标系绕Y轴旋转俯仰角,输入角度
		Temp_CoordinateInAmmunition.RotateAngleByYAxis( A_PitchingAngle );

		double Temp = sqrt( WarheadCenterPosition.Get_x() * WarheadCenterPosition.Get_x() 
			+ WarheadCenterPosition.Get_y() * WarheadCenterPosition.Get_y() );

		CoordinatesInTarget.Set_x( Temp - Temp_CoordinateInAmmunition.Get_x());
		CoordinatesInTarget.Set_y( - Temp_CoordinateInAmmunition.Get_y());
		CoordinatesInTarget.Set_z( WarheadCenterPosition.Get_z() 
			+ Temp_CoordinateInAmmunition.Get_z() );

		CoordinatesInTarget.RotateAngleByZAxis( A_YawAngle );

		return CoordinatesInTarget;
	}


}