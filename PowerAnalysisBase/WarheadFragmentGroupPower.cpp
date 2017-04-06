#include "WarheadFragmentGroupPower.h"
#include <MathCalculationSupport/AdvancedMath.h>
#include <AtmosphereAttribute.h>
#include <cmath>

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{
	WarheadFragmentGroupPower::WarheadFragmentGroupPower(void)
	{
	}


	WarheadFragmentGroupPower::~WarheadFragmentGroupPower(void)
	{
	}

	//���� ��ƬȺ�������������� �еĳ�Ա����
	double WarheadFragmentGroupPower::testWarheadFragmentGroupPowerClass(double di, double dj)
	{
		return di+dj;//�����������ĺ�
	}

	//��������ܼ���ʽһ����д����ԥ�£����ԣ���
	double WarheadFragmentGroupPower::ComputeGurneyEnergy(double BlaseVelocity, 
		double aa, double bb)
	{// BlaseVelocity:����,(m/s)��A��ϵ����0.52��Bϵ����0.28.
		return ( aa + bb * ( BlaseVelocity / 1000 ) ) * 1000;
	}

	//*********************************���ּ�����Ƭƽ���ٶȵķ���**************************************
	//������Ƭƽ���ٶȣ���д����ԥ�£����ԣ���
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_OnGurneyformula(
		double WLC, double GE)
	{// WLC��װ��ϵ����GE��������,(m/s)
		return GE * sqrt ( WLC / ( 1 + 0.5 * WLC) );
	}


	// �����ڱ��ڰ�Ԥ��ս����
	//WLC��װ��ϵ����װҩ����/����������BlaseVelocity��ըҩ����
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_ThinWall( double WLC , double BlaseVelocity )
	{
		return 0.353 * BlaseVelocity * sqrt( 3 * WLC / ( 3 + WLC ));
	}

	// �����ں��ս����
	//WLC��װ��ϵ��,װҩ����/��������
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_ThickWall( double WLC )
	{
		if ( WLC > 0 && WLC < 2 )
		{
			return 1830 * sqrt( WLC );
		}
		else if ( WLC > 2 && WLC < 6 )
		{
			return 2540 + 335 * ( WLC - 2 );
		}
		else return -100001;// ���ݴ���
	}

	// �����ڴ��ͱ��ڰ�Ԥ����Ƭս����
	// WLC_All��װ��ϵ����װҩ����/(װҩ����+��������)��BlaseVelocity��ըҩ����
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_LargeThinWallSemiPreformed( double WLC_All , double BlaseVelocity )
	{
		return BlaseVelocity / 2 * sqrt( WLC_All / ( 2 - 4.0 / 3.0 * WLC_All ));
	}

	// �����ڻ������ʽ1
	// ShellMass������������ChargeMass��װҩ������BlaseVelocity��ըҩ����
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_Rocket1( double ShellMass , double ChargeMass , double BlaseVelocity )
	{
		return 0.6 * BlaseVelocity * sqrt( 4 * ChargeMass / ( 5 * ( ChargeMass + 3 * ShellMass )));
	}

	// �����ڻ������ʽ2
	// WLC_All��װ��ϵ����װҩ����/(װҩ����+��������)��BlaseVelocity��ըҩ����
	double WarheadFragmentGroupPower::ComputeFragmengtVelocity_Rocket2( double WLC_All , double BlaseVelocity )
	{
		return BlaseVelocity / 2.03 * sqrt( 1 / WLC_All - 0.5 );
	}

	//***************************************************************
	// �õ���Ƭƽ����������������Gurney��Sarmousakis������(��д����ԥ�£����ԣ�)
	double WarheadFragmentGroupPower::ComputeFragmentAverageMass_OnGurAndSar(double KK, double tt, double dd, double Me, double Mf)
	{// KK��ȡ����ըҩ��ϵ����(kg1/2/m3/2)��tt������ƽ���ں�(m)������ƽ���ھ���(m)��װҩ������(kg)������������(kg)��
		double FragmentM = 0;
		FragmentM = pow( KK * tt * pow( tt + dd , 3.0 / 2.0) * pow( 1 + 0.5 * Me / Mf , 0.5 ) / dd , 2 );

		return FragmentM;
	}
	// �õ���Ƭƽ���������������ڿ�����������Ƭ������(��д����ԥ�£����ԣ�)
	double WarheadFragmentGroupPower::ComputeFragmentAverageMass_OnFragAllNum(double kk, double ShellMass, double FragmentNumber)
	{//kk������������ʧϵ��(����0,С�ڵ���1)��ShellMass����������,(kg)��FragmentNumber����Ƭ����,(N)
		double FragmentAverageMass = 0;
		if ( ( kk > 1 ) && ( kk < 0 ) )
		{
			FragmentAverageMass = -10002;
		} 
		else
		{
			FragmentAverageMass = kk * ShellMass / FragmentNumber;
		}
		return FragmentAverageMass;
	}

	// �õ���Ƭƽ����������������Mott������
	// Det������ں�cm��d0�������ھ���mm��K��ըҩ������g^(1/2)/cm^(7/6)
	double WarheadFragmentGroupPower::ComputeFragmentAverageMass_OnMott( double ShellThickness , 
		double d0 , double K )
	{
		double FragmentAverageMass = 0;
		FragmentAverageMass = pow( K * pow( ShellThickness , 5.0 / 6.0 )
			* pow( d0 , 1.0 / 3.0) * ( 1 + ShellThickness / d0 ), 2 );
		return FragmentAverageMass;
	}

	// �õ���Ƭ�������㷽��(����ƽ������)���յ�ЧӦ��P66��
	int WarheadFragmentGroupPower::ComputeFragmentNumber_OnAvMass(double ShellMass, 
		double FragmentAverageMass)
	{// ShellMass����������,(kg)��FragmentAverageMass����Ƭƽ������,(kg)
		return int ( ShellMass / FragmentAverageMass );
	}

	// �õ���Ƭ��������2���ʺ��񵯣�
	int WarheadFragmentGroupPower::ComputeFragmentNumber_2(double aa, 
		double WholeMass, double WLC)
	{//aa��ϵ����WholeMass��������������WLC��װ��ϵ��
		return int( );
	}

	// ����ĳһ������Ƭ�ۼ�������Mott������д����ԥ�£����ԣ���
	int WarheadFragmentGroupPower::ComputeOneMassFragmentN_Mott(int FragmentN0, 
		double OneMassFragment, double FragmentAverageMass)
	{// FragmentN0����Ƭ����,(ö)��OneMassFragment��ĳһ��Ƭ������(g)��
		//FragmentAverageMass����Ƭƽ��������(g)
		return int ( FragmentN0 * exp( - sqrt( OneMassFragment / FragmentAverageMass ) ) );
	}

	// ����ĳһ������Ƭ�ۼ���������2���Լ�������д����ԥ�£����ԣ���
	int WarheadFragmentGroupPower::ComputeOneMassFragmentN_2(int FragmentN0, 
		double OneMassFragment, double aa, double bb)
	{
		return int( FragmentN0 * exp( -aa * pow( OneMassFragment , bb ) ) );
	}

	// ����С�ڻ����ĳһ��������Ƭ��������held������д����ԥ�£����ԣ���
	double WarheadFragmentGroupPower::ComputeOneMassFragmentMass_Held(double kk, 
		double ShellMass, double OneMassFragment, double aa, double bb)
	{// kk������������ʧϵ��(����0,С�ڵ���1)��ShellMass������������(g)
		double FragmentMassLessthanOneValue = 0;
		
		if ( ( kk > 1 ) && ( kk < 0 ) )
		{
			FragmentMassLessthanOneValue = -10002;
		} 
		else
		{
			FragmentMassLessthanOneValue = kk * ShellMass * ( 1 - exp( - bb * pow(  OneMassFragment , aa ) ) );
		}
		return FragmentMassLessthanOneValue;
	}
	//������Ƭ��̬��ɢ�ٶ�
	double WarheadFragmentGroupPower::ComputeFragmentDynamicFlyVelocity( 
		double AmmunitionVelocity , double FragmentVelocity , double FlyDirectionAngle )
	{
		double FragmentDynamicFlyVelocity = 0;
			FragmentDynamicFlyVelocity = sqrt ( FragmentVelocity * FragmentVelocity 
				+ AmmunitionVelocity * AmmunitionVelocity 
				+ 2 * FragmentVelocity * AmmunitionVelocity * cos( pi - FlyDirectionAngle ) );
		return FragmentDynamicFlyVelocity;
	}

	//������Ƭӭ�����
	//ShapeCoefficient����״ϵ����m^2/kg^(2/3)
	//FragmentMass����Ƭ������kg
	double WarheadFragmentGroupPower::ComputeFragmentWindwardArea( 
		double ShapeCoefficient , double FragmentMass )
	{
		double WindwardArea = 0;
		WindwardArea = ShapeCoefficient * pow( FragmentMass , 2.0 / 3.0 );
		return WindwardArea;
	}

	//�����ٶ�˥��ϵ��
	//ResistanceCoefficient����������ϵ����EncounterHeight��������߶ȣ�km��
	//WindwardArea��ӭ�������m^2��FragmentMass����Ƭ������kg
	double WarheadFragmentGroupPower::ComputeFragmentVelocityReductionCoefficient( 
		double ResistanceCoefficient , double EncounterHeight , double WindwardArea ,
		double FragmentMass )
	{
		//�����ٶ�˥��ϵ��
		double VelocityReductionCoefficient = 0;
		//������Կ����ܶ�
		double RelativeAirDensity = AtmosphereAttribute::instance().GetAtmosphereDensity( 
			EncounterHeight ) / AirDensityInSeaPlane;
		//�����ٶ�˥��ϵ��
		VelocityReductionCoefficient = ResistanceCoefficient * AirDensityInSeaPlane 
			* RelativeAirDensity * WindwardArea / 2.0 / FragmentMass;
		return VelocityReductionCoefficient;
	}

	//�ɳ��١����������Ƭ��ĩ���ٶȣ������m/s��
	//FragmentInitialVelocity����Ƭ��ʼ�ٶȣ�m/s��
	//FragmentVelocityReductionCoefficient����Ƭ�ٶ�˥��ϵ����
	//FragmentFlyDistance����Ƭ���о��룬m
	double WarheadFragmentGroupPower::ComputeFragmentTerminalVelocityOnIni( 
		double FragmentInitialVelocity , double FragmentVelocityReductionCoefficient , 
		double FragmentFlyDistance )
	{
		double FragmentTerminalVelocity = 0;
		FragmentTerminalVelocity = FragmentInitialVelocity * exp( - FragmentVelocityReductionCoefficient 
			* FragmentFlyDistance );
		return FragmentTerminalVelocity;
	}

		//****************������Ƭ�ĵ��������ٶ�******************************************************
	//��ʽһ���������ʽ������������λΪm/s
	//ReviseIndexA������ϵ����2000-2600��FragmentDiameter����Ƭֱ����dm��
	//FragmentMass����Ƭ������kg��BoardThickness���а��ȣ�dm��
	//HitAngle���ŰнǶȣ���
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_Demar(
		double ReviseIndexA , double FragmentDiameter ,
		double FragmentMass , double BoardThickness , double HitAngle )
	{
		AdvancedMath TheAdvancedMath;
		double BallisticLimitVelocity;
		BallisticLimitVelocity = ReviseIndexA * pow( FragmentDiameter , 0.75 ) 
			/ pow( FragmentMass , 0.5 ) * pow( BoardThickness , 0.7 ) 
			/ cos( TheAdvancedMath.AngleToRadian( HitAngle ));
		return BallisticLimitVelocity;
	}

	//��ʽ����Johns Hopkins��ѧ��
	//IndexK,IndexAlpha,IndexBeta,IndexGamma�������������ص�ϵ����
	//BoardThickness���а��ȣ�cm��
	//FragmentAverageContactArea����Ƭƽ���Ű������cm^2��
	//FragmentMass����Ƭ������g��HitAngle���ŰнǶȣ���
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_Hopkins(
		double IndexK , double IndexAlpha , double IndexBeta , double IndexGamma , 
		double BoardThickness , double FragmentAverageContactArea , 
		double FragmentMass , double HitAngle )
	{
		double BallisticLimitVelocity;
		BallisticLimitVelocity = IndexK * pow( BoardThickness * 
			FragmentAverageContactArea , IndexAlpha ) * 
			pow( FragmentMass , IndexBeta ) * pow( 1.0 /
			cos( AdvancedMath::AngleToRadian( HitAngle )) , IndexGamma );
		return BallisticLimitVelocity;
	}

	//��ʽ�����Ƴ�ǿ��
	//IndexA��IndexB��ȡ���ڵ���������ϵ����BoardThickness���а��ȣ�m��
	//FragmentDiameter����Ƭֱ����m��
	//BoardDensity���а�����ܶȣ�kg/m^3��FragmentDensity����Ƭ�����ܶȣ�kg/m^3��
	//BoardBreakingPoint���а�ǿ�ȼ��ޣ�MPa
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_HuangCQ( 
		double IndexA , double IndexB , double BoardThickness ,
		double FragmentDiameter , double BoardDensity , double FragmentDensity ,
		double BoardBreakingPoint )
	{
		double BallisticLimitVelocity;
		BallisticLimitVelocity = IndexA * pow( BoardThickness / FragmentDiameter ,
			IndexB ) * pow( BoardDensity , 0.3 ) 
			/ pow( FragmentDensity , 0.8 ) * pow( BoardBreakingPoint , 0.5 );
		return BallisticLimitVelocity;
	}

	//��ʽ�ģ���־��-�ٺϽ�ʵ�飬�в���ȷ�ϣ�����������λΪm/s
	//BoardThickness���а��ȣ�mm��BoardYieldLimit���а��������ޣ�Pa��BoardDensity���а��ܶȣ�kg/m^3��
	//FragmentDensity����Ƭ�ܶȣ�kg/m^3��FragmentDiameter����Ƭֱ����mm
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_ChenZB(
		double BoardThickness , double BoardYieldLimit ,
		double BoardDensity , double FragmentDensity , double FragmentDiameter )
	{
		double BallisticLimitVelocity;
		if ( BoardThickness / FragmentDiameter < 1 )
		{
			BallisticLimitVelocity = 0.0728 * pow( BoardThickness , 0.81 ) *
				pow( BoardYieldLimit , 0.5 ) * pow( BoardDensity , 0.7 ) / 
				pow( FragmentDiameter , 0.87 ) / pow( FragmentDensity , 0.7 );
		}
		else
		{
			BallisticLimitVelocity = 0.0153 * pow( BoardThickness , 1.5 ) *
				pow( BoardYieldLimit , 0.5 ) * pow( BoardDensity , 0.7 ) / 
				pow( FragmentDiameter , 0.87 ) / pow( FragmentDensity , 0.7 );
		}
		return BallisticLimitVelocity;
	}

	//��ʽ�壨�����񣩣���������λΪm/s
	//BoardThickness���а��ȣ�m��FragmentDiameter����Ƭֱ����m��BoardDensity���а�����ܶȣ�kg/m^3��
	//FragmentDensity����Ƭ�����ܶȣ�kg/m^3��BoardBreakingPoint���а�ǿ�ȼ��ޣ�MPa��FragmentBreakingPoint����Ƭǿ�ȼ��ޣ�Mpa
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_WuXM( 
		double BoardThickness , double FragmentDiameter ,
		double BoardDensity , double FragmentDensity , double BoardBreakingPoint , 
		double FragmentBreakingPoint , double HitAngle )
	{
		double BallisticLimitVelocity;
		if ( HitAngle == 0 )
		{
			BallisticLimitVelocity = 1202 * pow( BoardThickness / 
				FragmentDiameter , 1.23 ) * pow( BoardDensity / FragmentDensity ,
				0.7 ) * pow( BoardBreakingPoint / FragmentBreakingPoint , 0.15 );
		}
		else
		{
			BallisticLimitVelocity = 1022 * pow( BoardThickness / FragmentDiameter ,
				1.23 ) * pow( BoardDensity / FragmentDensity , 0.7 ) * pow( 
				BoardBreakingPoint / FragmentBreakingPoint , 0.15 ) 
				* pow( 1.0 / cos(AdvancedMath::AngleToRadian( HitAngle )) , 0.85 );
		}
		return BallisticLimitVelocity;
	}


	//����93W�ٺϽ���Ƭ��ʵ�������Ϲ�ʽ(Q235A��)����������λΪm/s
	//FragmentDiameter����Ƭֱ����m��BoardThickness���а��ȣ�m
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_93W( 
		double FragmentDiameter , double BoardThickness )
	{
		double BallisticLimitVelocity;
		if ( FragmentDiameter / BoardThickness > 0.3 && FragmentDiameter / BoardThickness < 1.2 )
		{
			BallisticLimitVelocity = 575.7 * pow( FragmentDiameter / BoardThickness , -1.213 );
		} 
		else
		{
			BallisticLimitVelocity = -10000001;//�������ڹ�ʽ���÷�Χ
		}
		return BallisticLimitVelocity;
	}

	//����95W�ٺϽ���Ƭ��ʵ�������Ϲ�ʽ(Q235A��)����������λΪm/s
	//FragmentDiameter����Ƭֱ����m��BoardThickness���а��ȣ�m
	double WarheadFragmentGroupPower::ComputeBallisticLimitVelocity_95W(
		double FragmentDiameter , double BoardThickness )
	{
		double BallisticLimitVelocity;
		if ( FragmentDiameter / BoardThickness > 0.4 && FragmentDiameter / 
			BoardThickness < 1.3 )
		{
			BallisticLimitVelocity = 566.35 * pow( FragmentDiameter / 
				BoardThickness , -1.203 );
		} 
		else
		{
			BallisticLimitVelocity = -10000001;//�������ڹ�ʽ���÷�Χ
		}
		return BallisticLimitVelocity;
	}
}

