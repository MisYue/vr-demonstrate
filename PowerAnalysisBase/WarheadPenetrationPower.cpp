#include "WarheadPenetrationPower.h"
#include <cmath>
#include <MathCalculationSupport/AdvancedMath.h>
#include <MathCalculationSupport/UnitsTransform.h>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{
	WarheadPenetrationPower::WarheadPenetrationPower(void)
	{
	}


	WarheadPenetrationPower::~WarheadPenetrationPower(void)
	{
	}

	//���� �ֳ������������� �еĳ�Ա����
	double WarheadPenetrationPower::testWarheadPenetrationPowerClass(double di, double dj)
	{
		return di+dj;//�����������ĺ�
	}


	//�����ͷ���ֳ���ʣ���ٶ� �յ�ЧӦ��P155
	double WarheadPenetrationPower::ComptCReminingVelocity( double CIV , double CWM , double CTIK , double CFPD , double CWD , 
		double CHC , double MD ,double BT , double ICA )
	{//CIV����ͷ������,m/s��CWM����ͷ������,kg��CTIK����ͷ��ʵ��ϵ��K��CFPD����׶�ε�ƽ������ֱ��,m��
		//CWD����ͷ��Բ������ֱ��,m��
		//CHC����ͷ����׶��,�ȣ�MD���а�����ܶ�,kg/m^3��BT���а���,m��
		//ICA����ͷ�Ž�,�ȣ�CReminingVelocity����ͷ��ʣ���ٶ�
		double CReminingVelocity = CIV * ( 1 - ( pi * MD * BT 
			/ cos( AdvancedMath::AngleToRadian( ICA ))) / ( 4 * CWM ) * ( CTIK * CFPD
			* CFPD + ( CWD * CWD - CFPD * CFPD ) * sin( AdvancedMath::AngleToRadian( CHC ))));
		return CReminingVelocity;
	}

	//�������ε��ֳ���ʣ���ٶ� �������ʽ
	double WarheadPenetrationPower::ComptOReminingVelocity( double OIV , double OWM , double OWD , double ORIA , double BT , double ICA )
	{//OIV�����ε�����,m/s��OWM�����ε�����,kg��OWD�����ε�Բ������ֱ��,m��ORIA�����ε�����ϵ��A,һ��Ϊ2400��BT���а���,m��
		//ICA����ͷ�Ž�,�ȣ�OReminingVelocity�����ε�ʣ���ٶ�
		AdvancedMath *TheAdvancedMath = new AdvancedMath();
		UnitsTransform *TheUnitsTransform = new UnitsTransform();

		double V50 = ORIA * pow( UnitsTransform::MiToDm(OWD) , 0.75 )
			* pow( UnitsTransform::MiToDm(BT) , 0.7 ) / 
			( pow( OWM , 0.5 ) * cos( AdvancedMath::AngleToRadian( ICA )));
		double OReminingVelocity = ComputeReVelOnV50AndVin( OWM , OWM , 0, OIV , V50 );

		return OReminingVelocity;
	}

	//���㵯���ֳ����(mm) �������ʽ(�յ�ЧӦP136)
	//1.��������,kg��2.�ֳ��ٶ�,m/s��3.�Ž�;4.ֱ��,mm��5.ϵ��a(DeMarre);6.ϵ��b(DeMarre)
	double WarheadPenetrationPower::ComputePenetrationThickness( const double &Mass ,
		const double &Velocity , const double &Angle , const double &Diameter , 
		const double &Coefficient_A , const double &Coefficient_B )
	{
		double Thickness = 0;
		double Temp = Mass * Velocity * Velocity * cos( AdvancedMath::AngleToRadian( Angle ) )
			* cos( AdvancedMath::AngleToRadian( Angle ) ); 
		Thickness = UnitsTransform::DmToMm(UnitsTransform::MmToDm(Diameter) *
			pow(Temp / Coefficient_A / pow( UnitsTransform::MmToDm(Diameter) , 3)
			, 1 / Coefficient_B ) ) ;
		return Thickness;
	}

	// �����ٺ͵������޼���ʣ���ٶȣ����������غ㣩
	// 1. ��������(��ʼ,kg),2.��������(����,kg),3.������������(,kg),4.����(m/s)��5.V50(m/s)
	double WarheadPenetrationPower::ComputeReVelOnV50AndVin( const double &ProMass_Ini
		, const double & ProMass_over , const double &TargetStuffMass, const double &IniVelocity 
		, const double &V50 )
	{
		double ReVel = 0;
		if( ProMass_Ini == 0 && ProMass_Ini < 0 )
		{
			ReVel = 0;
		}
		else if( TargetStuffMass < 0)
		{
			ReVel = 0;
		}
		else if( ProMass_Ini < ProMass_over )
		{
			ReVel = 0;
		}
		else
		{
			if( IniVelocity < V50 )
			{
				ReVel = 0;
			}
			else
			{
				ReVel = ProMass_Ini * sqrt( IniVelocity * IniVelocity - V50 * V50 )
					/ ( ProMass_over + TargetStuffMass ) ;
			}
		}

		return ReVel;
	}

}
