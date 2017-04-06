#include "ClusterBombPower.h"

namespace BIT
{
	ClusterBombPower::ClusterBombPower(
		CoordinatesPosition IniCoordPos_M ,
		CoordinatesPosition IniCoordPos_T ,
		CoordinatesPosition TerCoordPos_M ,
		CoordinatesPosition TerCoordPos_T ,
		bool EmbedTarget ,
		double Velocity )
	{
		// ��������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_M = IniCoordPos_M;
		// ��ö��ƬĿ������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_T = IniCoordPos_T;
		// ��������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_M = TerCoordPos_M;
		// ��ö��ƬĿ������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_T = TerCoordPos_T;
		// �Ƿ�Ƕ��Ŀ��
		SubAmmuniEmbedTarget = EmbedTarget;
		//�ӵ��ٶ�
		SubAmmuniVelocity = Velocity;
	}
	// �������캯��
	ClusterBombPower::ClusterBombPower( const ClusterBombPower& CBP )
	{
		//��������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_M = CBP.InitializeCoordinatesPosition_M;
		// ��ö��ƬĿ������ϵ�����꣨��㣩,mm
		InitializeCoordinatesPosition_T = CBP.InitializeCoordinatesPosition_T;
		// ��������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_M = CBP.TerminalCoordinatesPosition_M;
		// ��ö��ƬĿ������ϵ�����꣨�յ㣩,mm
		TerminalCoordinatesPosition_T = CBP.TerminalCoordinatesPosition_T;
		// �Ƿ�Ƕ��Ŀ��
		SubAmmuniEmbedTarget = CBP.SubAmmuniEmbedTarget;
		// �ӵ��ٶ�
		SubAmmuniVelocity = CBP.SubAmmuniVelocity;
	}


	ClusterBombPower::~ClusterBombPower(void)
	{
	}

	//���� ��ĸ���������������� �еĳ�Ա����
	double ClusterBombPower::testClusterBombPowerClass(double di, double dj)
	{
		AdvancedMath aMath;
		double res = aMath.testAdvancedMathClass(0.001, 1000.0);
		return di+dj;//�����������ĺ�
	}
	//���õ�������ϵ������(���),mm
	const void ClusterBombPower::SetSubIniCoordinatesPositionPoint_M( 
		const CoordinatesPosition &ICPP_M )
	{
		InitializeCoordinatesPosition_M = ICPP_M;
	}
	//����Ŀ������ϵ������(�յ�)��mm
	const void ClusterBombPower::SetSubIniCoordinatesPositionPoint_T( 
		const CoordinatesPosition &ICPP_T )
	{
		InitializeCoordinatesPosition_T = ICPP_T;
	}
	//���õ�������ϵ������(�յ�),mm
	const void ClusterBombPower::SetSubTerCoordinatesPositionPoint_M( 
		const CoordinatesPosition &TCPP_M )
	{
		TerminalCoordinatesPosition_M = TCPP_M;
	}
	//����Ŀ������ϵ������(�յ�)��mm
	const void ClusterBombPower::SetSubTerCoordinatesPositionPoint_T( 
		const CoordinatesPosition &TCPP_T )
	{
		// ��ö��ƬĿ������ϵ������,mm
		TerminalCoordinatesPosition_T = TCPP_T;
	}
	//�����ӵ��Ƿ�Ƕ��Ŀ��
	const void ClusterBombPower::SetSubAmmuniEmbedTarget( const bool &AET )
	{
		SubAmmuniEmbedTarget = AET;
	}

	//�����ӵ��ٶ�
	const void ClusterBombPower::SetSubAmmuniVelocity( const double &SAV )
	{
		if( SAV < 0)
		{
			SubAmmuniVelocity = 0;
		}
		else
			SubAmmuniVelocity = SAV;
	}

	//�õ���������ϵ������(���),mm
	const CoordinatesPosition ClusterBombPower::GetSubIniCoordinatesPositionPoint_M( void ) const
	{
		return InitializeCoordinatesPosition_M;
	}
	//�õ�Ŀ������ϵ������(���)��mm
	const CoordinatesPosition ClusterBombPower::GetSubIniCoordinatesPositionPoint_T( void ) const
	{
		return InitializeCoordinatesPosition_T;
	}
	//�õ���������ϵ������(�յ�),mm
	const CoordinatesPosition ClusterBombPower::GetSubTerCoordinatesPositionPoint_M( void ) const
	{
		return TerminalCoordinatesPosition_M;
	}
	//�õ�Ŀ������ϵ������(�յ�),mm
	const CoordinatesPosition ClusterBombPower::GetSubTerCoordinatesPositionPoint_T( void ) const
	{
		return TerminalCoordinatesPosition_T;
	}
	// �õ��ӵ�Ƕ��Ŀ��
	const bool ClusterBombPower::GetSubAmmuniEmbedTarget( void ) const
	{
		return SubAmmuniEmbedTarget;
	}
	// �õ��ӵ��ٶ�
	const double ClusterBombPower::GetSubAmmuniVelocity( void ) const
	{
		return SubAmmuniVelocity;
	}
}