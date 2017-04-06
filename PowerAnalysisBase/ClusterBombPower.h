/************************************************
	���ƣ���ĸ�������������� ClusterBombPower
	���ܣ������ӵ�ɢ���뾶���ӵ�ɢ���ܶȵ�
	�����ˣ�
	����ʱ�䣺
	�汾��1.0
*************************************************/

#pragma once
#include "poweranalysisbase_global.h"
#include "MathCalculationSupport/AdvancedMath.h"
#include <math.h>
#include "MathCalculationSupport/CoordinatesPosition.h"

namespace BIT
{
	class POWERANALYSISBASE_EXPORT ClusterBombPower
	{
	public:
		ClusterBombPower(
			CoordinatesPosition IniCoordPos_M = ( 0 , 0 , 0) ,
			CoordinatesPosition IniCoordPos_T = ( 0 , 0 , 0) ,
			CoordinatesPosition TerCoordPos_M = ( 0 , 0 , 0) ,
			CoordinatesPosition TerCoordPos_T = ( 0 , 0 , 0) ,
			bool EmbedTarget = false ,
			double Velocity = 0
			);
		~ClusterBombPower(void);

		// �������캯��
		ClusterBombPower( const ClusterBombPower& CBP);

		//���� ��ĸ���������������� �еĳ�Ա����
		double testClusterBombPowerClass(double di, double dj);

		//���õ�������ϵ������(���),mm
		const void SetSubIniCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//����Ŀ������ϵ������(���)��mm
		const void SetSubIniCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//���õ�������ϵ������(�յ�),mm
		const void SetSubTerCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//����Ŀ������ϵ������(�յ�)��mm
		const void SetSubTerCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//�����ӵ��Ƿ�Ƕ��Ŀ��
		const void SetSubAmmuniEmbedTarget( const bool & );
		//�����ӵ��ٶ�,m/s
		const void SetSubAmmuniVelocity( const double &);

		//�õ���������ϵ������(���),mm
		const CoordinatesPosition GetSubIniCoordinatesPositionPoint_M( void ) const;
		//�õ�Ŀ������ϵ������(���)��mm
		const CoordinatesPosition GetSubIniCoordinatesPositionPoint_T( void ) const;
		//�õ���������ϵ������(�յ�),mm
		const CoordinatesPosition GetSubTerCoordinatesPositionPoint_M( void ) const;
		//�õ�Ŀ������ϵ������(�յ�),mm
		const CoordinatesPosition GetSubTerCoordinatesPositionPoint_T( void ) const;
		// �õ��ӵ��Ƿ���Ŀ��
		const bool GetSubAmmuniEmbedTarget( void ) const;
		// �õ��ӵ��ٶȣ�m/s
		const double GetSubAmmuniVelocity( void ) const;

	private:

		//�����ӵ���������ϵ�����꣨��㣩,mm
		CoordinatesPosition InitializeCoordinatesPosition_M;
		//�����ӵ�Ŀ������ϵ�����꣨��㣩,mm
		CoordinatesPosition InitializeCoordinatesPosition_T;
		//�����ӵ�����ϵ�����꣨�յ㣩,mm
		CoordinatesPosition TerminalCoordinatesPosition_M;
		//�����ӵ���ƬĿ������ϵ�����꣨�յ㣩,mm
		CoordinatesPosition TerminalCoordinatesPosition_T;
		//�ӵ��Ƿ�ʵ�������Ƕ��Ŀ��ﵽ����Ŀ��
		bool SubAmmuniEmbedTarget;
		//�ӵ�ҩ������,m/s
		double SubAmmuniVelocity;
	};

}

