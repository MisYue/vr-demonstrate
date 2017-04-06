/************************************************
	���ƣ���ƬȺ������������ WarheadFragmentGroupPower
	���ܣ����㵼��ս������ը����ƬȺ������������������Ƭ���١������ֲ���
			�뱬��һ�����������Ƭ�ٶȺͷֲ��ܶ�
	�����ˣ�
	����ʱ�䣺
	�汾��1.0



	�޸��ˣ���Ⱥ��
	�޸����ڣ�2016��5��30��
	�޸��������޸Ŀ��ʹ�ýӿ�
	�汾��1.1


*************************************************/

#pragma once
// ���庣ƽ������ܶ�(��λ��kg/m^3)
#define AirDensityInSeaPlane 1.225
#include "poweranalysisbase_global.h"

namespace BIT
{
	class POWERANALYSISBASE_EXPORT WarheadFragmentGroupPower
	{
	public:
		WarheadFragmentGroupPower(void);
		~WarheadFragmentGroupPower(void);

		//���� ��ƬȺ�������������� �еĳ�Ա����
		static double testWarheadFragmentGroupPowerClass(double di, double dj);

		// ���������
		//BlaseVelocity�����٣���ʽϵ����a����ʽϵ����b
		static double ComputeGurneyEnergy(double BlaseVelocity, double aa, double bb);
		
		// ������Ƭ��ʼ�ٶ�
		//WLC��װ��ϵ����GE��������,(m/s)
		static double ComputeFragmengtVelocity_OnGurneyformula(double WLC, double GE);

		// �����ڱ��ڰ�Ԥ��ս����
		//WLC��װ��ϵ����װҩ����/����������BlaseVelocity��ըҩ����
		static double ComputeFragmengtVelocity_ThinWall( double WLC , double BlaseVelocity );

		// �����ں��ս����
		//WLC��װ��ϵ��,װҩ����/��������
		static double ComputeFragmengtVelocity_ThickWall( double WLC );

		// �����ڴ��ͱ��ڰ�Ԥ����Ƭս����
		// WLC_All��װ��ϵ����װҩ����/(װҩ����+��������)��BlaseVelocity��ըҩ����
		static double ComputeFragmengtVelocity_LargeThinWallSemiPreformed( double WLC_All , double BlaseVelocity );

		// �����ڻ������ʽ1
		// ShellMass������������ChargeMass��װҩ������BlaseVelocity��ըҩ����
		static double ComputeFragmengtVelocity_Rocket1( double ShellMass , double ChargeMass , double BlaseVelocity );

		// �����ڻ������ʽ2
		// WLC_All��װ��ϵ����װҩ����/(װҩ����+��������)��BlaseVelocity��ըҩ����
		static double ComputeFragmengtVelocity_Rocket2( double WLC_All , double BlaseVelocity );

		// �õ���Ƭƽ����������������Gurney��Sarmousakis������
		// KK��ȡ����ըҩ��ϵ����(kg1/2/m3/2)��tt������ƽ���ں�(m)��
		// ����ƽ���ھ���(m)��װҩ������(kg)������������(kg)��
		// �������kg
		static double ComputeFragmentAverageMass_OnGurAndSar(double KK, double tt, double dd, 
			double Me, double Mf);
		
		// �õ���Ƭƽ����������������Mott������
		// ShellThickness������ں�cm��d0�������ھ���mm��K��ըҩ������g^(1/2)/cm^(7/6)
		// �������g
		static double ComputeFragmentAverageMass_OnMott( double ShellThickness , double d0 , double K );

		// �õ���Ƭƽ����������(������Ƭ������)
		//kk������������ʧϵ��(����0,С�ڵ���1)��
		//ShellMass����������,(kg)��FragmentNumber����Ƭ����,(N)
		static double ComputeFragmentAverageMass_OnFragAllNum(double kk, double ShellMass, 
			double FragmentNumber);
		
		// �õ���Ƭ�����������㷽��һ���յ�ЧӦ��P66��
		// ShellMass����������,(kg)��FragmentAverageMass����Ƭƽ������,(kg)
		static int ComputeFragmentNumber_OnAvMass(double ShellMass, double FragmentAverageMass);
		
		// �õ���Ƭ�����������������ʺ��񵯣�
		// //aa��ϵ����WholeMass��������������WLC��װ��ϵ��
		static int ComputeFragmentNumber_2(double aa, double WholeMass, double WLC);
		
		// ����ĳһ������Ƭ�ۼ�������Mott��
		// FragmentN0����Ƭ����,(ö)��OneMassFragment��ĳһ��Ƭ������(g)��
		//FragmentAverageMass����Ƭƽ��������(g)
		static int ComputeOneMassFragmentN_Mott(int FragmentN0, double OneMassFragment, 
			double FragmentAverageMass);
		
		// ����ĳһ������Ƭ�ۼ���������2
		static int ComputeOneMassFragmentN_2(int FragmentN0, double OneMassFragment,
			double aa, double bb);
		
		// ����С�ڻ����ĳһ��������Ƭ������
		static double ComputeOneMassFragmentMass_Held(double kk, double ShellMass, 
			double OneMassFragment, double aa, double bb);

		//������Ƭ��̬��ɢ�ٶ�
		static double ComputeFragmentDynamicFlyVelocity( double AmmunitionVelocity , 
			double FragmentVelocity , double FlyDirectionAngle );

		//������Ƭӭ�����
		//ShapeCoefficient����״ϵ����m^2/kg^(2/3)
		//FragmentMass����Ƭ������kg
		static double ComputeFragmentWindwardArea( double ShapeCoefficient , double FragmentMass );

		//�����ٶ�˥��ϵ��(���������)
		//ResistanceCoefficient����������ϵ����EncounterHeight��������߶ȣ�km��
		//WindwardArea��ӭ�������m^2��FragmentMass����Ƭ������kg
		static double ComputeFragmentVelocityReductionCoefficient( double ResistanceCoefficient , 
			double EncounterHeight , double WindwardArea , double FragmentMass );

		//�ɳ��١����������Ƭ��ĩ���ٶȣ������m/s��
		//FragmentInitialVelocity����Ƭ��ʼ�ٶȣ�m/s��
		//FragmentVelocityReductionCoefficient����Ƭ�ٶ�˥��ϵ����
		//FragmentFlyDistance����Ƭ���о��룬m
		static double ComputeFragmentTerminalVelocityOnIni( double FragmentInitialVelocity 
			, double FragmentVelocityReductionCoefficient , double FragmentFlyDistance );

		//*******************��Ƭ�������޼��㹫ʽ**************************
		//��ʽһ���������ʽ������������λΪm/s
		//ReviseIndexA������ϵ����2000-2600��FragmentDiameter����Ƭֱ����dm��
		//FragmentMass����Ƭ������kg��BoardThickness���а��ȣ�dm��
		//HitAngle���ŰнǶȣ���
		static double ComputeBallisticLimitVelocity_Demar( double ReviseIndexA , 
			double FragmentDiameter , double FragmentMass ,
			double BoardThickness , double HitAngle );

		//��ʽ����Johns Hopkins��ѧ��
		//IndexK,IndexAlpha,IndexBeta,IndexGamma�������������ص�ϵ����BoardThickness���а��ȣ�cm��
		//FragmentAverageContactArea����Ƭƽ���Ű������cm^2��FragmentMass����Ƭ������g��HitAngle���ŰнǶȣ���
		static double ComputeBallisticLimitVelocity_Hopkins( double IndexK , double IndexAlpha , double IndexBeta ,
			double IndexGamma , double BoardThickness , double FragmentAverageContactArea ,
			double FragmentMass , double HitAngle );

		//��ʽ�����Ƴ�ǿ��
		//IndexA��IndexB��ȡ���ڵ���������ϵ����BoardThickness���а��ȣ�m��FragmentDiameter����Ƭֱ����m��
		//BoardDensity���а�����ܶȣ�kg/m^3��FragmentDensity����Ƭ�����ܶȣ�kg/m^3��BoardBreakingPoint���а�ǿ�ȼ��ޣ�MPa
		static double ComputeBallisticLimitVelocity_HuangCQ( double IndexA , double IndexB , double BoardThickness ,
			double FragmentDiameter , double BoardDensity , double FragmentDensity , double BoardBreakingPoint );

		//��ʽ�ģ���־�󣩣���������λΪm/s
		//BoardThickness���а��ȣ�mm��BoardYieldLimit���а��������ޣ�Pa��BoardDensity���а��ܶȣ�kg/m^3��
		//FragmentDensity����Ƭ�ܶȣ�kg/m^3��FragmentDiameter����Ƭֱ����mm
		static double ComputeBallisticLimitVelocity_ChenZB( double BoardThickness , double BoardYieldLimit , double BoardDensity ,
			double FragmentDensity , double FragmentDiameter );

		//��ʽ�壨�����񣩣��ٺϽ��װ�׸֣�����������λΪm/s
		//BoardThickness���а��ȣ�m��FragmentDiameter����Ƭֱ����m��BoardDensity���а�����ܶȣ�kg/m^3��
		//FragmentDensity����Ƭ�����ܶȣ�kg/m^3��BoardBreakingPoint���а�ǿ�ȼ��ޣ�MPa��FragmentBreakingPoint����Ƭǿ�ȼ��ޣ�Mpa
		static double ComputeBallisticLimitVelocity_WuXM( double BoardThickness , double FragmentDiameter , double BoardDensity ,
			double FragmentDensity , double BoardBreakingPoint , double FragmentBreakingPoint , double HitAngle );

		//����93W�ٺϽ���Ƭ��ʵ�������Ϲ�ʽ�����ٺϽ��Q235�֣�����������λΪm/s
		//FragmentDiameter����Ƭֱ����m��BoardThickness���а��ȣ�m
		static double ComputeBallisticLimitVelocity_93W( double FragmentDiameter , double BoardThickness );

		//����95W�ٺϽ���Ƭ��ʵ�������Ϲ�ʽ�����ٺϽ��Q235�֣���������λΪm/s
		//FragmentDiameter����Ƭֱ����m��BoardThickness���а��ȣ�m
		static double ComputeBallisticLimitVelocity_95W( double FragmentDiameter , double BoardThickness );
	};

}

