/************************************************
	���ƣ���Ƭ������� FragmentCoordinatePoint
	���ܣ�����������Ƭ��ɢ�����е������
	�����ˣ���ԥ��
	����ʱ�䣺2015��4��22��
	�汾��1.0
*************************************************/


#pragma once
#include "poweranalysisbase_global.h"
#include <math.h>
#include "MathCalculationSupport/CoordinatesPosition.h"
// ��������
#include "MaterialProperty/BaseMechanicsAndpPhysicsProperty.h"

namespace BIT
{
	template class __declspec(dllexport) std::allocator<char>;
	template class __declspec(dllexport) std::basic_string<char>;

	class POWERANALYSISBASE_EXPORT FragmentCoordinatePosition
	{
	public:
		FragmentCoordinatePosition(
			string FragGUID = "" ,
			string FragMatGUID = "",
			double FlyDirAng = 0 ,
			double FlyCirAng = 0,
			CoordinatesPosition IniCoordPos_M = ( 0 , 0 , 0) ,
			CoordinatesPosition IniCoordPos_T = ( 0 , 0 , 0) ,
			CoordinatesPosition TerCoordPos_M = ( 0 , 0 , 0) ,
			CoordinatesPosition TerCoordPos_T = ( 0 , 0 , 0) ,
			double SingFragMass = 0,
			double SingFragIniStatFlyVel = 0,
			double SingFragIniDynaFlyVel = 0,
			double SingFragDynaTerFlyVel = 0,
			double SingFragFlyDist = 0,
			double SingDynaFlyDirAngle = 0,
			double SingFragResistCoe = 0,
			double BalLimForTar = 0
			);

		~FragmentCoordinatePosition(void);

		// �������캯��
		FragmentCoordinatePosition( const FragmentCoordinatePosition& FCP);

		//************���ö���******************
		//�������
		BaseMechanicsAndpPhysicsProperty *Frag_Material;

		//***********���ú���˽�б���***********
		//������Ƭ��Ψһ��ʶ
		const void SetFragmentGUID( const string & );
		//������Ƭ���ϵ�Ψһ��ʶ
		const void SetFragmentMatGUID( const string& );
		//���÷��з����,����
		const void SetSFragStaticFlyDirectionAngle( const double& );
		//���÷��������,����
		const void SetSFragStaticFlyCircumferenceAngle( const double & );
		//���õ�������ϵ������(���),mm
		const void SetSFragIniCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//����Ŀ������ϵ������(���)��mm
		const void SetSFragIniCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//���õ�������ϵ������(�յ�),mm
		const void SetSFragTerCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//����Ŀ������ϵ������(�յ�)��mm
		const void SetSFragTerCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//���õ�ö��Ƭ����,g
		const void SetSFragMass( const double& );
		//���õ�ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		const void SetSFragStaticIniFlyVelocity( const double& );
		//���õ�ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		const void SetSFragDynamicIniFlyVelocity( const double& );
		//���õ�ö��Ƭ��̬(ĩ��)��ɢ�ٶ�,m/s
		const void SetSFragDynamicTerFlyVelocity( const double& );
		//���õ�ö��Ƭ���о��룬m
		const void SetSFragFlyDistance( const double& );
		//���õ�ö��Ƭ��̬��ɢ�����,��
		const void SetSFragDynamicFlyDirectionAngle( const double & );
		//���õ�ö��Ƭ���ٶ�˥��ϵ��
		const void SetSFragVelocityReductionCoefficient( const double & );
		//���ö�ĳһ����ĵ��������ٶȣ�m/s
		const void SetBallisticLimitForTarget( const double & );

		//***********�õ�����˽�б���************
		//�õ���Ƭ��Ψһ��ʶ
		const string GetFragmentGUID( void ) const;
		//�õ���Ƭ���ϵ�Ψһ��ʶ
		const string GetFragmentMatGUID( void ) const;
		//�õ����з����,����
		const double GetSFragStaticFlyDirectionAngle( void ) const;
		//�õ����������,����
		const double GetSFragStaticFlyCircumferenceAngle( void ) const;
		//�õ���������ϵ������(���),mm
		const CoordinatesPosition GetSFragIniCoordinatesPositionPoint_M( void ) const;
		//�õ�Ŀ������ϵ������(���)��mm
		const CoordinatesPosition GetSFragIniCoordinatesPositionPoint_T( void ) const;
		//�õ���������ϵ������(�յ�),mm
		const CoordinatesPosition GetSFragTerCoordinatesPositionPoint_M( void ) const;
		//�õ�Ŀ������ϵ������(�յ�),mm
		const CoordinatesPosition GetSFragTerCoordinatesPositionPoint_T( void ) const;
		//�õ���ö��Ƭ����,g
		const double GetSFragMass( void ) const;
		//�õ���ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		const double GetSFragStaticIniFlyVelocity( void ) const;
		//�õ���ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		const double GetSFragDynamicIniFlyVelocity( void ) const;
		//�õ���ö��Ƭ��̬(ĩ��)��ɢ�ٶ�,m/s
		const double GetSFragDynamicTerFlyVelocity( void ) const;
		////�õ���ö��Ƭ���о��룬m
		const double GetSFragFlyDistance( void ) const;
		//�õ���ö��Ƭ��̬��ɢ�����,��
		const double GetSFragDynamicFlyDirectionAngle( void )const ;
		//�õ���ö��Ƭ������ϵ��
		const double GetSFragResistanceCoefficient( void ) const;
		//�õ���ĳһ����ĵ��������ٶȣ�m/s
		const double GetBallisticLimitForTarget( void ) const;

	

	private:
		//��Ƭ��ţ�Ψһ��ʶ��
		string FragmentGUID;
		//��Ƭ����GUID
		string FragmentMatGUID;
		// ���з����,����
		double StaticFlyDirectionAngle;
		// ���������,����
		double StaticFlyCircumferenceAngle;
		//��������ϵ�����꣨��㣩,mm
		CoordinatesPosition InitializeCoordinatesPosition_M;
		// ��ö��ƬĿ������ϵ�����꣨��㣩,mm
		CoordinatesPosition InitializeCoordinatesPosition_T;
		// ��������ϵ�����꣨�յ㣩,mm
		CoordinatesPosition TerminalCoordinatesPosition_M;
		// ��ö��ƬĿ������ϵ�����꣨�յ㣩,mm
		CoordinatesPosition TerminalCoordinatesPosition_T;
		//��ö��Ƭ����,g
		double SingleFragmentMass;
		////��Ƭ��������(�����������һ��)
		//string FragmentMaterialName;
		//��ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		double SingleFragmentStaticIniFlyVelocity;
		//��ö��Ƭ��̬(��ʼ)��ɢ�ٶ�,m/s
		double SingleFragmentDynamicIniFlyVelocity;
		//��ö��Ƭ��̬��ĩ�ˣ��ٶȣ�m/s
		double SingleFragmentDynamicTerFlyVelocity;
		//��ö��Ƭ���о��룬m
		double SingleFragmentFlyDistance;
		//��ö��Ƭ��̬��ɢ�����,��
		double SingleDynamicFlyDirectionAngle;
		//��ö��Ƭ������ϵ��
		double SingleFragmentVelocityReductionCoefficient;
		//��ĳһ����ĵ��������ٶȣ�m/s
		double BallisticLimitForTarget;
	};

}
