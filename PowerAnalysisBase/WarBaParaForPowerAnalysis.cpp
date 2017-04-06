#include "WarBaParaForPowerAnalysis.h"
#include <cmath>

// ս�����������������������

namespace BIT
{

	WarBaParaForPowerAnalysis::WarBaParaForPowerAnalysis(void)
	{
	}


	WarBaParaForPowerAnalysis::~WarBaParaForPowerAnalysis(void)
	{
	}

	//���� ս������������������������� �еĳ�Ա����
	double WarBaParaForPowerAnalysis::testWarBaParaForPowerAnalysisClass(double di, double dj)
	{
		return di+dj;//�����������ĺ�

	}

	//***************************************************************************************//
	//***����ս������������Ĺ��û���������װ��ϵ��������װҩ�൱����¶װҩ�ĵ�����TNT����***//
	//


// ����װ��ϵ��
	double WarBaParaForPowerAnalysis::ComputeWLC( double WholeMass, double ChargesMass, double ShellMass )
	{
		double WLC = 0;

		if ( WholeMass == 0 )
		{
			WLC  = ChargesMass / ( ShellMass );
		}
		else if ( ChargesMass == 0 )
		{
			WLC  = ( WholeMass - ShellMass ) / ShellMass;
		}
		else if ( ShellMass == 0 )
		{
			WLC = ChargesMass / ( WholeMass - ChargesMass );
		}
		return WLC;
	}
	//�������װҩ�൱����¶װҩ�ĵ���
	//Charge_shell������װҩ��R_0��ս�����뾶��R_p0�����Ѱ뾶/ԭ�뾶��aa����״ϵ��A��bb����״ϵ��B��PolytropicExponent���෽ָ��
	double WarBaParaForPowerAnalysis::ComputeNakedChargeEquivalentMass( double Charge_shell, double R_0 , double R_p0, 
		double aa , double bb , double PolytropicExponent , double WLC)
	{
		double NakedCharge = 0;
		NakedCharge = Charge_shell * ( WLC / ( aa + 1 - WLC * aa ) + 
			( aa + 1 ) * ( 1- WLC ) * pow( ( R_0 / R_p0 ) , bb * 
			( PolytropicExponent - 1) ) / ( aa + 1 - aa * WLC ));;

		return NakedCharge;
	}

	//�˶�װҩ��ֹװҩת�����յ�ЧӦѧ��������ɽ p293
	double WarBaParaForPowerAnalysis::ComputeMotionChargeEquivalentMass( double Charge_M, double ChargeVelocity
		, double ChargeQv )
	{
		double EquivalentMass_Q = 0;

		EquivalentMass_Q = Charge_M * ( ChargeQv + 0.5 * ChargeVelocity * ChargeVelocity ) / ( ChargeQv );

		return EquivalentMass_Q;

	}
	//TNT��������
	double WarBaParaForPowerAnalysis::ComputeChargeTNTNL( double Charge_M , double Charge_Qv )
	{
		return Charge_M * Charge_Qv / 4479876;						// 4479876:TNT�ı���
	}

}
