#include "FragmentCoordinatePosition.h"

namespace BIT
{

	FragmentCoordinatePosition::FragmentCoordinatePosition(
		string FragGUID ,string FragMatGUID, 
		double FlyDirAng , double FlyCirAng ,
		CoordinatesPosition IniCoordPos_M ,
		CoordinatesPosition IniCoordPos_T ,
		CoordinatesPosition TerCoordPos_M ,
		CoordinatesPosition TerCoordPos_T ,
		double SingFragMass, double SingFragStatIniFlyVel, 
		double SingFragDynaIniFlyVel, double SingFragDynaTerFlyVel,
		double SingFragFlyDist,
		double SingDynaFlyDirAngle , double SingFragResistCoe ,
		double BalLimForTar )
	{
		//��ƬΨһ��ʶ
		FragGUID = FragmentGUID;
		//��Ƭ����Ψһ��ʶ
		FragMatGUID = FragmentMatGUID;
		// ���з����
		StaticFlyDirectionAngle = FlyDirAng;
		// ���������
		StaticFlyCircumferenceAngle = FlyCirAng;
		// ��������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_M = IniCoordPos_M;
		// ��ö��ƬĿ������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_T = IniCoordPos_T;
		// ��������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_M = TerCoordPos_M;
		// ��ö��ƬĿ������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_T = TerCoordPos_T;
		// ��ö��Ƭ����,g
		SingleFragmentMass = SingFragMass;
		//��ö��Ƭ��̬����ʼ����ɢ�ٶ�,m/s
		SingleFragmentStaticIniFlyVelocity = SingFragStatIniFlyVel;
		//��ö��Ƭ��̬����ʼ����ɢ�ٶ�,m/s
		SingleFragmentDynamicIniFlyVelocity = SingFragDynaIniFlyVel;
		//��ö��Ƭ��̬��ĩ�ˣ������ٶȣ�m/w
		SingleFragmentDynamicTerFlyVelocity = SingFragDynaTerFlyVel;
		//��ö��Ƭ���о��룬m
		SingFragFlyDist = SingleFragmentFlyDistance;
		//��ö��Ƭ��̬��ɢ�����,��
		SingleDynamicFlyDirectionAngle = SingDynaFlyDirAngle;
		//��ö��Ƭ������ϵ��
		SingleFragmentVelocityReductionCoefficient = SingFragResistCoe;
		//��ĳһ����ĵ��������ٶȣ�m/s
		BallisticLimitForTarget = BalLimForTar;

		// ��Ƭ����
		Frag_Material = new BaseMechanicsAndpPhysicsProperty();
	}
	
	// �������캯��
	FragmentCoordinatePosition::FragmentCoordinatePosition( const FragmentCoordinatePosition& FCP )
	{
		//��Ƭ��ţ�Ψһ��ʶ��
		FragmentGUID = FCP.FragmentGUID;
		//��Ƭ����GUID
		FragmentMatGUID = FCP.FragmentMatGUID;
		// ���з����,����
		StaticFlyDirectionAngle = FCP.StaticFlyDirectionAngle;
		// ���������,����
		StaticFlyCircumferenceAngle = FCP.StaticFlyCircumferenceAngle;
		//��������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_M = FCP.InitializeCoordinatesPosition_M;
		// ��ö��ƬĿ������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_T = FCP.InitializeCoordinatesPosition_T;
		// ��������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_M = FCP.TerminalCoordinatesPosition_M;
		// ��ö��ƬĿ������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_T = FCP.TerminalCoordinatesPosition_T;
		//��ö��Ƭ����,g
		SingleFragmentMass = FCP.SingleFragmentMass;
		////��Ƭ��������(�����������һ��)
		//string FragmentMaterialName;
		//��ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		SingleFragmentStaticIniFlyVelocity = FCP.SingleFragmentStaticIniFlyVelocity;
		//��ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		SingleFragmentDynamicIniFlyVelocity = FCP.SingleFragmentDynamicIniFlyVelocity;
		//��ö��Ƭ��̬��ĩ�ˣ��ٶȣ�m/s
		SingleFragmentDynamicTerFlyVelocity = FCP.SingleFragmentDynamicTerFlyVelocity;
		//��ö��Ƭ���о��룬m
		SingleFragmentFlyDistance = FCP.SingleFragmentFlyDistance;
		//��ö��Ƭ��̬��ɢ�����,��
		SingleDynamicFlyDirectionAngle = FCP.SingleDynamicFlyDirectionAngle;
		//��ö��Ƭ������ϵ��
		SingleFragmentVelocityReductionCoefficient = FCP.SingleFragmentVelocityReductionCoefficient;
		//��ĳһ����ĵ��������ٶȣ�m/s
		BallisticLimitForTarget = FCP.BallisticLimitForTarget;
	}

	FragmentCoordinatePosition::~FragmentCoordinatePosition(void)
	{
		// ��Ƭ����
		if( Frag_Material != NULL ) 
			delete Frag_Material;
	}
	//***********���ú���˽�б���***********
	//������Ƭ��Ψһ��ʶ
	const void FragmentCoordinatePosition::SetFragmentGUID( const string &FGUID )
	{
		FragmentGUID = FGUID;
	}
	//������Ƭ���ϵ�Ψһ��ʶ
	const void FragmentCoordinatePosition::SetFragmentMatGUID( const string &FMatGUID )
	{
		FragmentMatGUID = FMatGUID ;
	}
	//���÷��з����,����
	const void FragmentCoordinatePosition::SetSFragStaticFlyDirectionAngle( 
		const double &SFDA )
	{
		StaticFlyDirectionAngle = SFDA;
	}
	//���÷��������,����
	const void FragmentCoordinatePosition::SetSFragStaticFlyCircumferenceAngle( 
		const double &SFCA )
	{
		StaticFlyCircumferenceAngle = SFCA;
	}
	//���õ�������ϵ������(���),mm
	const void FragmentCoordinatePosition::SetSFragIniCoordinatesPositionPoint_M( 
		const CoordinatesPosition &ICPP_M )
	{
		InitializeCoordinatesPosition_M = ICPP_M;
	}
	//����Ŀ������ϵ������(�յ�)��mm
	const void FragmentCoordinatePosition::SetSFragIniCoordinatesPositionPoint_T( 
		const CoordinatesPosition &ICPP_T )
	{
		InitializeCoordinatesPosition_T = ICPP_T;
	}
	//���õ�������ϵ������(�յ�),mm
	const void FragmentCoordinatePosition::SetSFragTerCoordinatesPositionPoint_M( 
		const CoordinatesPosition &TCPP_M )
	{
		TerminalCoordinatesPosition_M = TCPP_M;
	}

	//����Ŀ������ϵ������(�յ�)��mm
	const void FragmentCoordinatePosition::SetSFragTerCoordinatesPositionPoint_T( 
		const CoordinatesPosition &TCPP_T )
	{
		// ��ö��ƬĿ������ϵ������,mm
		TerminalCoordinatesPosition_T = TCPP_T;
	}
	//���õ�ö��Ƭ����,g
	const void FragmentCoordinatePosition::SetSFragMass( const double &SFM )
	{
		// ��ö��Ƭ����,g
		SingleFragmentMass = SFM;
	}
	//���õ�ö��Ƭ��̬����ʼ����ɢ�ٶ�,m/s
	const void FragmentCoordinatePosition::SetSFragStaticIniFlyVelocity( const double &SFSIFV )
	{
		//��ö��Ƭ��̬����ʼ����ɢ�ٶ�,m/s
		SingleFragmentStaticIniFlyVelocity = SFSIFV;
	}
	//���õ�ö��Ƭ��̬����ʼ����ɢ�ٶ�,m/s
	const void FragmentCoordinatePosition::SetSFragDynamicIniFlyVelocity( const double &SFDIFV )
	{
		//��ö��Ƭ��̬����ʼ����ɢ�ٶ�,m/s
		SingleFragmentDynamicIniFlyVelocity = SFDIFV;
	}
	//���õ�ö��Ƭ��̬(ĩ��)��ɢ�ٶ�,m/s
	const void FragmentCoordinatePosition::SetSFragDynamicTerFlyVelocity( const double &SFDTFV )
	{
		SingleFragmentDynamicTerFlyVelocity = SFDTFV;
	}
	//���õ�ö��Ƭ��̬��ɢ�����,��
	const void FragmentCoordinatePosition::SetSFragDynamicFlyDirectionAngle( const double &SDFDA )
	{
		//��ö��Ƭ��̬��ɢ�����,��
		SingleDynamicFlyDirectionAngle = SDFDA;
	}
	//���õ�ö��Ƭ������ϵ��
	const void FragmentCoordinatePosition::SetSFragVelocityReductionCoefficient( const double &SFVRC )
	{
		//��ö��Ƭ������ϵ��
		SingleFragmentVelocityReductionCoefficient = SFVRC;
	}
	//������Ƭ��ĳһ����ĵ�������
	const void FragmentCoordinatePosition::SetBallisticLimitForTarget( const double &BLFT )
	{
		BallisticLimitForTarget = BLFT;
	}
	// ���õ�ö��Ƭ���о���
	const void FragmentCoordinatePosition::SetSFragFlyDistance( const double &SFFD )
	{
		SingleFragmentFlyDistance = SFFD;
	}

	//***********�õ�����˽�б���************
	//�õ���Ƭ��Ψһ��ʶ
	const std::string FragmentCoordinatePosition::GetFragmentGUID( void ) const
	{
		return FragmentGUID;
	}
	//�õ���Ƭ���ϵ�Ψһ��ʶ
	const std::string FragmentCoordinatePosition::GetFragmentMatGUID( void ) const
	{
		return FragmentMatGUID;
	}
	//�õ����з����,����
	const double FragmentCoordinatePosition::GetSFragStaticFlyDirectionAngle( void ) const
	{
		return StaticFlyDirectionAngle;
	}

	//�õ����������,����
	const double FragmentCoordinatePosition::GetSFragStaticFlyCircumferenceAngle( void ) const
	{
		return StaticFlyCircumferenceAngle;
	}
	//�õ���������ϵ������(���),mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragIniCoordinatesPositionPoint_M( void ) const
	{
		return InitializeCoordinatesPosition_M;
	}
	//�õ�Ŀ������ϵ������(���)��mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragIniCoordinatesPositionPoint_T( void ) const
	{
		return InitializeCoordinatesPosition_T;
	}
	//�õ���������ϵ������(�յ�),mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragTerCoordinatesPositionPoint_M( void ) const
	{
		return TerminalCoordinatesPosition_M;
	}

	//�õ�Ŀ������ϵ������(�յ�)��mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragTerCoordinatesPositionPoint_T( void ) const
	{
		return TerminalCoordinatesPosition_T;
	}
	//�õ���ö��Ƭ����,g
	const double FragmentCoordinatePosition::GetSFragMass( void ) const
	{
		return SingleFragmentMass;
	}
	//�õ���ö��Ƭ��̬��ɢ�ٶ�,m/s
	const double FragmentCoordinatePosition::GetSFragStaticIniFlyVelocity( void ) const
	{
		return SingleFragmentStaticIniFlyVelocity;
	}
	//�õ���ö��Ƭ��̬��ɢ�ٶ�,m/s
	const double FragmentCoordinatePosition::GetSFragDynamicIniFlyVelocity( void ) const
	{
		return SingleFragmentDynamicIniFlyVelocity;
	}
	//�õ���ö��Ƭ��̬(ĩ��)��ɢ�ٶ�,m/s
	const double FragmentCoordinatePosition::GetSFragDynamicTerFlyVelocity( void ) const
	{
		return SingleFragmentDynamicTerFlyVelocity;
	}
	//�õ���ö��Ƭ��̬��ɢ�����,��
	const double FragmentCoordinatePosition::GetSFragDynamicFlyDirectionAngle( void ) const
	{
		return SingleDynamicFlyDirectionAngle;
	}
	//�õ���ö��Ƭ������ϵ��
	const double FragmentCoordinatePosition::GetSFragResistanceCoefficient( void ) const
	{
		return SingleFragmentVelocityReductionCoefficient;
	}

	

	//�õ���ĳһ����ĵ��������ٶȣ�m/s
	const double FragmentCoordinatePosition::GetBallisticLimitForTarget( void )const
	{
		return BallisticLimitForTarget;
	}
	
	////�õ���ö��Ƭ���о��룬m
	const double FragmentCoordinatePosition::GetSFragFlyDistance( void ) const
	{
		return SingleFragmentFlyDistance;
	}

}
