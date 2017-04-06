/************************************************
	���ƣ��ռ伸�� SpaceGeometry
	���ܣ�֧�Ž��пռ����궨�塢ת���ȼ���
	�����ˣ�
	����ʱ�䣺
	�汾��1.0
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

		static double testSpaceGeometryClass(double di, double dj);	//���� �ռ伸���� �еĳ�Ա����

		// ����ռ��������ߵļнǣ����뻡��
		static double AngleInTwoLine( double LineOne_i , double LineOne_j , 
			double LineOne_k , double LineTwo_i , double LineTwo_j , double LineTwo_k );
		
		//�ж�һ�����ϵ���������һ�����Ƿ���������֮��
		static bool JudgePointSiteBetweenTwoPoint( CoordinatesPosition JudgePoint ,
			CoordinatesPosition FristPoint, CoordinatesPosition SecondPoint);

		//******************���νṹ�������*******************
		//����Բ̨����������ڼ�����������
		//R����Բ�뾶��r��СԲ�뾶��H����
		static double ComputeFrustumOfAConeVolume( double R , double r , double H );
		//�����Բ̨����������ڼ�����������
		//R����Բ�뾶��r��СԲ�뾶��H����
		static double ComputeHalfFrustumOfAConeVolume( double R , double r , double H );
		//����Բ�������������ڼ�����������
		//Diameter��Բֱ����Height����
		static double ComputeCylinderVolume( double Diameter , double Height );
		//�����Բ�������������ڼ�����������
		//Diameter��Բֱ����Height����
		static double ComputeHalfCylinderVolume( double Diameter , double Height );
		//����Բ׶�����������ڼ�����������
		//Radius����Բ�뾶��Height����
		static double ComputeConeVolume( double Radius , double Height );
		//�����Բ׶�����������ڼ�����������
		//Radius����Բ�뾶��Height����
		static double ComputeHalfConeVolume( double Radius , double Height );
		//����������������ڼ�����������
		static double ComputeSphereVolume( double Diameter );
		//���㳤�������������ڼ�����������
		static double ComputeCuboidVolume( double XLength , double YLength , double ZLength );

		///******************�������������*******************
		//�������(�����������ܶ�)
		//Mass��������g��Density���ܶȣ�g/cm^3
		static double ComputeVolumeOnMassAndDensity( double Mass , double Density );
		
		//******************��������㼸��������*******************
		//�������������뾶
		static double ComputeSphereRadiusOnVolume( double Volume );
	};

}

