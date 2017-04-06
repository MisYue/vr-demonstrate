#include "ShapedChargePower.h"

namespace BIT
{

	ShapedChargePower::ShapedChargePower(void)
	{
	}


	ShapedChargePower::~ShapedChargePower(void)
	{
	}

	//���� �Ƽ��������������� �еĳ�Ա����
	double ShapedChargePower::testShapedChargePowerClass(double di, double dj)
	{
		return di+dj;//�����������ĺ� 
	}
	// �������ۼ����ֳ��ٶȣ��յ�ЧӦѧP245ҳ��
	double ShapedChargePower::JetPenetrationDeepness( double JetLength , double JetDensity , double TargetDensity )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = JetLength * sqrt( JetDensity / TargetDensity );
		return PenetrationDeepness;
	}

	// �����ڶ����������ֳ���ȼ��㹫ʽ���յ�ЧӦ��P246
	// JetLength���������ȣ�JetDensity�������ܶȣ�TargetDensity�������ܶȣ�Lumbda����������ȡ1����������ȡ2
	double ShapedChargePower::JetPenetrationDeepnessByLumbda( double JetLength , double JetDensity , double TargetDensity , int Lumbda )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = JetLength * sqrt( Lumbda * JetDensity / TargetDensity );
		return PenetrationDeepness;
	}

	// ���ǰа�ǿ�ȵ��ֳ���ȹ�ʽ���յ�ЧӦ��P246
	// JetLength���������ȣ�JetDensity�������ܶȣ�TargetDensity�������ܶȣ�TargetYield���а�����ǿ�ȣ�TargetYield�������ٶȣ�alpha��������Ϊ�����Ͱа��ܶȵĺ���
	double ShapedChargePower::JetPenetrationDeepnessByTargetYield( double JetLength , double JetDensity , double TargetDensity , double TargetYield , double JetVelocity , double alpha )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = JetLength * sqrt( JetDensity / TargetDensity ) * 
			( 1 - alpha * TargetYield / ( JetDensity * JetVelocity * JetVelocity ));
		return PenetrationDeepness;
	}

	//����EFP�ֳ����(�������Ϊm,701������2010��P89)
	//EFPMass��EFP������kg��EFPVelocity��EFP�ٶȣ�m/s��EFPDiameter��EFPֱ����m
	//���Ϊmm
	double ShapedChargePower::EFPPenetrationDeepness( double EFPMass,
		double EFPVelocity , double EFPDiameter )
	{
		double PenetrationDeepness = 0;
		PenetrationDeepness = 2.0 * EFPMass 
			* pow( EFPVelocity / EFPDiameter , 2 ) * 1e-9/ 3.0 /pi;
		return PenetrationDeepness;
	}

}