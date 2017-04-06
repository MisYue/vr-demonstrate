/************************************************
	���ƣ�ս����������������������� WarBaParaForPowerAnalysis
	���ܣ�����ս����װ��ϵ��������װҩTNT�����������������������
	�����ˣ�
	����ʱ�䣺
	�汾��1.0


	�޸��ˣ���Ⱥ��
	�޸����ڣ�2016��5��30��
	�޸��������޸Ŀ��ʹ�ýӿ�
	�汾��1.1

*************************************************/

#pragma once
#include "poweranalysisbase_global.h"


namespace BIT
{
	class POWERANALYSISBASE_EXPORT WarBaParaForPowerAnalysis
	{
	public:
		WarBaParaForPowerAnalysis(void);
		~WarBaParaForPowerAnalysis(void);

		//���� ս������������������������� �еĳ�Ա����
		static double testWarBaParaForPowerAnalysisClass(double di, double dj);

		//***************************************************************************************//
		//***����ս������������Ĺ��û���������
		// װ��ϵ��
		// ����װҩ�൱����¶װҩ�ĵ���
		// TNT����***//
		//

		//����װ��ϵ��
		//WholeMass��ս��������������ChargesMass��ըҩװҩ������ShellMass����������
		//���أ�ս����װ��ϵ����
		static double ComputeWLC(double WholeMass, double ChargesMass, double ShellMass);

		//�������װҩ�൱����¶װҩ������
		//Charge_shell������װҩ����kg����R_0��ԭ�뾶(mm)��R_p0�����Ѱ뾶(mm)��aa����״ϵ��A��bb����״ϵ��B��
		//PolytropicExponent���෽ָ����WLC��װ��ϵ��
		//���أ�����װҩ�൱����¶װҩ������
		static double ComputeNakedChargeEquivalentMass( double Charge_shell, double R_0 , double R_p0, 
			double aa , double bb , double PolytropicExponent , double WLC);

		//�˶�װҩ��ֹװҩת�����յ�ЧӦѧ��������ɽ p293
		//Charge_M��װҩ������ChargeVelocity��װҩ�ٶȣ�ChargeQv��װҩ����
		//���أ��˶�װҩ��Ч�ɾ�ֹװҩ��
		static double ComputeMotionChargeEquivalentMass( double Charge_M, double ChargeVelocity, double ChargeQv );

		//TNT��������
		//Charge_M��װҩ����,kg��Charge_Qv��װҩ���ȣ�J
		//����TNT������kg
		static double ComputeChargeTNTNL( double Charge_M , double Charge_Qv );
	};

}

