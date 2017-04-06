/*
���ƣ� 
���ܣ� 
�����ˣ�
����ʱ�䣺
�汾��1.0
*/

#pragma once
#include "MathCalculationSupport_Global.h"

// ����㺯��
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

		//*�������� ��������ض��帳ֵ
		void operator= (const CoordinatesPosition& cPositon );
		bool operator == (const CoordinatesPosition& cPositon );


		// �Ƕ�ת����
		const double AngleToRadian(const double& Angle);
		// ����ת�Ƕ�
		const double RadianToAngle(const double& Radian);

		//����xֵ
		const double Set_x(const double& xx );
		//����yֵ
		const double Set_y(const double& yy );
		//����zֵ
		const double Set_z(const double& zz );

		// �õ����е�xֵ
		const double Get_x(void) const ;
		const double Get_y(void) const ;
		const double Get_z(void) const ;

		// �������������ľ���
		const double Distance(const CoordinatesPosition& P2);
		// ���㵽ԭ��ľ���
		const double DistanceOriginPosition(void);
		// �����XZƽ��ļн�
		const double AngleWithXZPlane(void);
		// �����XYƽ��ļн�
		const double AngleWithXYPlane(void);
		// �����YZƽ��ļн�
		const double AngleWithYZPlane(void);
		// ��-ԭ��������X��ļн�
		const double AngleWithXAxis(void);
		// ��-ԭ��������Y��ļн�
		const double AngleWithYAxis(void);
		// ��-ԭ��������Z��ļн�
		const double AngleWithZAxis(void);
		// ��ά������ƽ��
		const void CoordinatesAfterTranslation(const double& Dx, const double& Dy, const double& Dz);
		// ��ά������X����ת
		const void RotateAngleByXAxis(const double& Angle );
		// ��ά������Y����ת
		const void RotateAngleByYAxis(const  double& Angle );
		// ��ά������Z����ת
		const void RotateAngleByZAxis(const  double& Angle );
		//��ռ���һ��P2�������P1������X��н�
		const double IncludedAngleOfXAxis(const CoordinatesPosition& );
		//��ռ���һ��P2�������P1������Y��н�
		const double IncludedAngleOfYAxis(const CoordinatesPosition& );
		//��ռ���һ��P2�������P1������Z��н�
		const double IncludedAngleOfZAxis(const CoordinatesPosition& );
		//��ռ�ֱ������һ��
		const CoordinatesPosition GetAnotherPoint(const CoordinatesPosition&  
		, const double& , const double& , const double&, const double&);

		////*******�����໥ת������*************
		//��������ϵ��(��ֹ)Ŀ������ϵת������
		//A_PitchingAngle�����������ǣ���ֹĿ��/�������ϵ������
		//A_YawAngle������ƫ���ǣ���ֹĿ��/�������ϵ����
		//CoordinateInAmmunition���ڵ��������еĵ�
		//WarheadCenterPosition��ս����������Ŀ������ϵ�е�����ֵ
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