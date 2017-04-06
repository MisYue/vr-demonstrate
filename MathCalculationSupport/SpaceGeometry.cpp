#include "SpaceGeometry.h"
#include <math.h>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{
	SpaceGeometry::SpaceGeometry(void)
	{
	}

	SpaceGeometry::~SpaceGeometry(void)
	{
	}

	//���� �ռ伸���� �еĳ�Ա����
	double SpaceGeometry::testSpaceGeometryClass(double di, double dj)
	{
		return sqrt(di*di+dj*dj);//�����������ļ���ƽ��ֵ
	}

	// ����ռ��������ߵļн�
	double SpaceGeometry::AngleInTwoLine( double LineOne_i , double LineOne_j , double LineOne_k , double LineTwo_i , double LineTwo_j , double LineTwo_k )
	{
		return 1;
	}

	//******************���νṹ�������*******************
	//����Բ̨�����
	double SpaceGeometry::ComputeFrustumOfAConeVolume( double R , double r , double H )
	{
		double Volume = ( 1.0 / 3.0 ) * pi * ( R * R + R * r + r * r );
		return Volume;
	}
	//�����Բ̨����������ڼ�����������
	//R����Բ�뾶��r��СԲ�뾶��H����
	double SpaceGeometry::ComputeHalfFrustumOfAConeVolume( double R , double r , double H )
	{
		double Volume = ( 1.0 / 3.0 ) * pi * ( R * R + R * r + r * r ) / 2.0;
		return Volume;
	}
	//����Բ��������
	double SpaceGeometry::ComputeCylinderVolume( double Diameter , double Height )
	{
		double Volume = Height * pi * ( Diameter * Diameter / 4 );
		return Volume;
	}
	//�����������
	double SpaceGeometry::ComputeSphereVolume( double Diameter )
	{
		double Volume = 4.0 * pi * pow( Diameter / 2 , 3 ) / 3.0;
		return Volume;
	}
	//�������������뾶
	double SpaceGeometry::ComputeSphereRadiusOnVolume( double Volume )
	{
		double Radius = pow( Volume * 3.0 / 4.0 / pi , 1.0 / 3.0 );
		return Radius;
	}
	//�����������(��������������ܶ�),����������λ��cm^3
	//Mass��������g��Density���ܶȣ�g/cm^3
	double SpaceGeometry::ComputeVolumeOnMassAndDensity( 
		double Mass , double Density )
	{
		double Volume = 0;
		Volume = Mass / Density;
		return Volume;
	}
	//�����Բ�������������ڼ�����������
	//Diameter��Բֱ����Height����;Thickness������Բ������
	double SpaceGeometry::ComputeHalfCylinderVolume( double Diameter , double Height )
	{
		double Volume = Height * pi * ( Diameter * Diameter / 4 ) / 2.0;
		return Volume;
	}
	//����Բ׶�����������ڼ�����������
	//Radius����Բ�뾶��Height����;Thickness������Բ׶���ȣ������ڵ�Բ����
	double SpaceGeometry::ComputeConeVolume( double Radius , double Height )
	{
		double Volume = 1.0 / 3.0 * Height * pi * Radius * Radius;
		return Volume;
	}
	//�����Բ׶�����������ڼ�����������
	//Radius����Բ�뾶��Height����;Thickness������Բ׶���ȣ������ڵ�Բ����
	double SpaceGeometry::ComputeHalfConeVolume( double Radius , double Height )
	{
		double Volume = 1.0 / 3.0 * Height * pi * Radius * Radius / 2.0;
		return Volume;
	}

	//���㳤�������������ڼ�����������
	double SpaceGeometry::ComputeCuboidVolume( double XLength , double YLength 
		, double ZLength )
	{
		return XLength * YLength * ZLength;
	}

	//�ж�һ�����ϵ���������һ�����Ƿ���������֮��
	bool SpaceGeometry::JudgePointSiteBetweenTwoPoint( CoordinatesPosition JudgePoint ,
		CoordinatesPosition FristPoint, CoordinatesPosition SecondPoint )
	{
		bool Judge = NULL;

		CoordinatesPosition TheCoordinatesPosition;
		// �����жϵ�͵�һ����ľ���
		double Distance_JF = JudgePoint.Distance(FristPoint);
		// �����жϵ�͵ڶ�����ľ���
		double Distance_JS = JudgePoint.Distance(SecondPoint);
		// �����һ����͵ڶ�����֮��ľ���
		double Distance_FS = FristPoint.Distance(SecondPoint);

		if( abs(Distance_JF + Distance_JS - Distance_FS ) < 0.00000001 )
		{
			Judge = true;
		}
		else Judge = false;
		return Judge;
	}

}
