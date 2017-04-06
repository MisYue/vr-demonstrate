/************************************************
	���ƣ��Ƽ������������� ShapedChargePower
	���ܣ��������װҩս�����γɾ����ֳ�����ٶȵ�
	�����ˣ�
	����ʱ�䣺
	�汾��1.0
*************************************************/

#pragma once
#include "poweranalysisbase_global.h"
#include <math.h>
#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{
	class POWERANALYSISBASE_EXPORT ShapedChargePower
	{
	public:
		ShapedChargePower(void);
		~ShapedChargePower(void);

		//���� �Ƽ��������������� �еĳ�Ա����
		double testShapedChargePowerClass(double di, double dj);

		//�������ֳ����㹫ʽ
		// �������ۼ����ֳ��ٶȣ��յ�ЧӦѧP245ҳ��
		// JetLength���������ȣ�JetDensity�������ܶȣ�TargetDensity�������ܶ�
		double JetPenetrationDeepness( double JetLength , double JetDensity 
			, double TargetDensity );

		// �����ڶ����������ֳ���ȼ��㹫ʽ���յ�ЧӦ��P246
		// JetLength���������ȣ�JetDensity�������ܶȣ�TargetDensity�������ܶȣ�Lumbda����������ȡ1����������ȡ2
		double JetPenetrationDeepnessByLumbda( double JetLength , double JetDensity 
			, double TargetDensity , int Lumbda );

		// ���ǰа�ǿ�ȵ��ֳ���ȹ�ʽ���յ�ЧӦ��P246
		// JetLength���������ȣ�JetDensity�������ܶȣ�TargetDensity�������ܶȣ�TargetYield���а�����ǿ�ȣ�TargetYield�������ٶȣ�alpha��������Ϊ�����Ͱа��ܶȵĺ���
		double JetPenetrationDeepnessByTargetYield( double JetLength , double JetDensity 
			, double TargetDensity , double TargetYield , double JetVelocity , double alpha );

		//����EFP�ֳ����
		//EFPMass��EFP������kg��EFPVelocity��EFP�ٶȣ�m/s��EFPDiameter��EFPֱ����m
		//���أ�mm
		double EFPPenetrationDeepness( double EFPMass, double EFPVelocity 
			, double EFPDiameter);
	};

}

