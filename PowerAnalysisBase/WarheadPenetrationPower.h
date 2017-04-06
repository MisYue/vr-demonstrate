/************************************************
	���ƣ��ֳ������������� WarheadPenetrationPower
	���ܣ����㵼��ս�����Բ�����ֳ������������ֹ��ձ�����ʣ���ٶ�
	�����ˣ�
	����ʱ�䣺
	�汾��1.0
*************************************************/

#pragma once
#include "poweranalysisbase_global.h"

namespace BIT
{
	enum PenThickFormulaType{ DeMarre };

	class POWERANALYSISBASE_EXPORT WarheadPenetrationPower
	{
	public:
		WarheadPenetrationPower(void);
		~WarheadPenetrationPower(void);

		//���� �ֳ������������� �еĳ�Ա����
		static double testWarheadPenetrationPowerClass(double di, double dj);

		// �����ٺ͵������޼���ʣ���ٶȣ����������غ㣩
		// 1. ��������(��ʼ,kg),2.��������(����,kg),3.������������(,kg),4.����(m/s)��5.V50(m/s)
		static double ComputeReVelOnV50AndVin( const double & , const double & , const double &
			, const double & , const double &);

		//�����ͷ���ֳ����ʣ���ٶ� �յ�ЧӦ��P155
		//CIV����ͷ������,m/s��CWM����ͷ������,kg��CTIK����ͷ��ʵ��ϵ��K,һ��ȡ1~1.5��CFPD����׶�ε�ƽ������ֱ��,m��CWD����ͷ��Բ������ֱ��,m��
		//CHC����ͷ����׶��,�ȣ�MD���а�����ܶ�,kg/m^3��BT���а���,m��ICA����ͷ�Ž�,��
		static double ComptCReminingVelocity( double CIV , double CWM , double CTIK , double CFPD , double CWD , double CHC , 
			double MD ,double BT , double ICA );
		//�������ε��ֳ����ʣ���ٶ� �������ʽ
		//OIV�����ε�����,m/s��OWM�����ε�����,kg��OWD�����ε�Բ������ֱ��,m��ORIA�����ε�����ϵ��A,һ��Ϊ2400��BT���а���,m��ICA����ͷ�Ž�,��
		static double ComptOReminingVelocity( double OIV , double OWM , double OWD , double ORIA , double BT , double ICA );
		
		//���㵯���ֳ����(mm) �������ʽ(�յ�ЧӦP136)
		//1.��������,kg��2.�ֳ��ٶ�,m/s��3.�Ž�;4.ֱ��,mm��5.ϵ��a(DeMarre);6.ϵ��b(DeMarre)
		static double ComputePenetrationThickness( const double & , const double & 
			, const double & , const double & , const double & , const double & );

	};

}

