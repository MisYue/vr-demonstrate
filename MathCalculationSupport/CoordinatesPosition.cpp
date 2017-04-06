#include "CoordinatesPosition.h"


#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

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

		//*�������� ���������
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

	// ����Xֵ
	const double CoordinatesPosition::Set_x(const double& xx )
	{
		x = xx;
		return x;
	}
	// ����Yֵ
	const double CoordinatesPosition::Set_y(const double& yy )
	{
		y = yy;
		return y;
	}
	// ����Zֵ
	const double CoordinatesPosition::Set_z(const double& zz )
	{
		z = zz;
		return z;
	}

	// �õ����е�xֵ
	const double CoordinatesPosition::Get_x(void) const
	{
		return x;
	}

	// �õ����е�yֵ
	const double CoordinatesPosition::Get_y(void) const
	{
		return y;
	}

	// �õ����е�zֵ
	const double CoordinatesPosition::Get_z(void) const
	{
		return z;
	}

	// �Ƕ�ת���ȣ���д����ԥ�£����ԣ���ԥ�£�
	const double CoordinatesPosition::AngleToRadian(const double& Angle)
	{// Angle������Ƕ�

		double Radian = 0;
		Radian = ( Angle / 180 ) * pi;
		return Radian;

	}

	// ����ת�Ƕȣ���д����ԥ�£����ԣ���ԥ�£�
	const double CoordinatesPosition::RadianToAngle(const double& Radian)
	{// Radian������

		double Angle = 0;
		Angle = ( Radian / pi ) * 180;
		return Angle;

	}

	// �������������ľ��루��д����ԥ�£����ԣ���
	const double CoordinatesPosition::Distance(const CoordinatesPosition& P2)
	{// P2 ��2�������
		return sqrt( (P2.x-x) * (P2.x-x) + (P2.y-y) * (P2.y-y) + (P2.z-z) * (P2.z-z) );
	}

	// ���㵽ԭ��ľ��루��д����ԥ�£����ԣ���
	const double CoordinatesPosition::DistanceOriginPosition(void)
	{
		return sqrt( x * x + y * y + z * z );
	}

	// ��-ԭ��������XZƽ��ļнǣ���д����ԥ�£����ԣ���
	const double CoordinatesPosition::AngleWithXZPlane(void)
	{// ������Ƕ�
		return RadianToAngle( asin( y / sqrt( x * x + y * y + z * z ) ) );
	}

	//  ��-ԭ��������XYƽ��ļнǣ���д�����죬���ԣ���
	const double CoordinatesPosition::AngleWithXYPlane(void)
	{// ������Ƕ�
		return RadianToAngle( asin( z / sqrt( x * x + y * y + z * z ) ) );
	}

	//  ��-ԭ��������YZƽ��ļнǣ���д�����죬���ԣ���
	const double CoordinatesPosition::AngleWithYZPlane(void)
	{// ������Ƕ�
		return RadianToAngle( asin( x / sqrt( x * x + y * y + z * z ) ) );
	}

	// ��-ԭ��������X��ļнǣ���д�����죬���ԣ���
	const double CoordinatesPosition::AngleWithXAxis(void)
	{// ������Ƕ�
		return RadianToAngle( acos( x / sqrt( x * x + y * y + z * z ) ) );
	}

	// ��-ԭ��������Y��ļн�
	const double CoordinatesPosition::AngleWithYAxis(void)
	{// ������Ƕ�
		return RadianToAngle( acos( y / sqrt( x * x + y * y + z * z ) ) );
	}

	// ��-ԭ��������Z��ļн�
	const double CoordinatesPosition::AngleWithZAxis(void)
	{// ������Ƕ�
		return RadianToAngle( acos( z / sqrt( x * x + y * y + z * z ) ) );
	}

	// ��ά������ƽ�ƣ���д����ԥ�£�
	const void CoordinatesPosition::CoordinatesAfterTranslation(const double& Dx, const  double& Dy, const double& Dz)//������
	{// Dx����X��ƽ�ƾ��룻Dy����Y��ƽ�ƾ��룻Dz����Z��ƽ�ƾ���
		x = x + Dx;
		y = y + Dy;
		z = z + Dz;
	}
	// ��ά������X����ת(�������������������򣩣���д����ԥ�£�
	const void CoordinatesPosition::RotateAngleByXAxis(const double& Angle )//������
	{// Angle:����Ϊ�Ƕ�ֵ 
		double c ,b;
		x = x;
		b = y;
		c = z;
		y = b * cos( AngleToRadian( Angle )) - c * sin( AngleToRadian( Angle ) );
		z = b * sin( AngleToRadian( Angle )) + c * cos( AngleToRadian( Angle ) );
	}
	// ��ά������Y����ת(�������������������򣩣���д����ԥ�£�
	const void CoordinatesPosition::RotateAngleByYAxis(const double& Angle )//������
	{// Angle:����Ϊ�Ƕ�ֵ 
		double a ,c;
		a = x;
		c = z;
		x = a * cos( AngleToRadian( Angle )) + c * sin( AngleToRadian( Angle ) );
		y = y ;
		z = -a * sin( AngleToRadian( Angle )) + z * cos( AngleToRadian( Angle ) );
	}
	// ��ά������Z����ת(��������������������
	const void CoordinatesPosition::RotateAngleByZAxis(const double& Angle )//������
	{// Angle:����Ϊ�Ƕ�ֵ 
		double a , b;
		a = x;
		b = y;
		x = a * cos( AngleToRadian( Angle )) - b * sin( AngleToRadian( Angle ) );
		y = a * sin( AngleToRadian( Angle )) + b * cos( AngleToRadian( Angle ) );
		z = z;
	}
	//��ռ���һ��P2�������P1������X��н�
	const double CoordinatesPosition::IncludedAngleOfXAxis(const CoordinatesPosition& P2 )
	{
		double Angle;
		if ( x == P2.x && y == P2.y && z == P2.z )
		{
			Angle = -10001;//�غ��޼н�
		}
		else
		{
			Angle = RadianToAngle( acos( ( P2.x - x ) / sqrt( ( P2.x - x ) * ( P2.x - x ) + ( P2.y - y ) * ( P2.y - y ) + ( P2.z - z ) * ( P2.z - z ) ) ) ) ;
		}
		return Angle ;
	}
	//��ռ���һ��P2�������P1������Y��н�
	const double CoordinatesPosition::IncludedAngleOfYAxis(const CoordinatesPosition& P2 )
	{
		double Angle;
		if ( x == P2.x && y == P2.y && z == P2.z )
		{
			Angle = -10001;//�غ��޼н�
		}
		else
		{
			Angle = RadianToAngle( acos( ( P2.y - y ) / sqrt( ( P2.x - x ) * ( P2.x - x ) + ( P2.y - y ) * ( P2.y - y ) + ( P2.z - z ) * ( P2.z - z ) ) ) ) ;
		}
		return Angle ;
	}
	//��ռ���һ��P2�������P1������Z��н�
	const double CoordinatesPosition::IncludedAngleOfZAxis(const CoordinatesPosition& P2)
	{
		double Angle;
		if ( x == P2.x && y == P2.y && z == P2.z )
		{
			Angle = -10001;//�غ��޼н�
		}
		else
		{
			Angle = RadianToAngle( acos( ( P2.z - z ) / sqrt( ( P2.x - x ) * ( P2.x - x ) + ( P2.y - y ) * ( P2.y - y ) + ( P2.z - z ) * ( P2.z - z ) ) ) ) ;
		}
		return Angle ;

	}


	// �ɲ������̺ͽؾ������ά����ϵ�еĵ�
	const CoordinatesPosition CoordinatesPosition::GetAnotherPoint(const CoordinatesPosition& P1 
		, const double& aa , const double &bb , const double& cc , const double& LL )
	{
		CoordinatesPosition P2;
		P2.Set_x( P1.Get_x() + LL * aa );
		P2.Set_y( P1.Get_y() + LL * bb );
		P2.Set_z( P1.Get_z() + LL * cc );
		return P2;
	}

	//��������ϵ��(��ֹ)Ŀ������ϵת������������Ƕ�
	const CoordinatesPosition CoordinatesPosition::ComputeCoordinateInTargetFromAmmunition(
		const double &A_PitchingAngle , const double &A_YawAngle, 
		const CoordinatesPosition &CoordinateInAmmunition 
		, const CoordinatesPosition &WarheadCenterPosition )
	{
		CoordinatesPosition CoordinatesInTarget;
		CoordinatesPosition Temp_CoordinateInAmmunition = CoordinateInAmmunition;
		// ��������ϵ��Y����ת������,����Ƕ�
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