/************************************************
	名称：破片坐标点类 FragmentCoordinatePoint
	功能：辅助进行破片飞散过程中的坐标点
	创建人：徐豫新
	创建时间：2015年4月22日
	版本：1.0
*************************************************/


#pragma once
#include "poweranalysisbase_global.h"
#include <math.h>
#include "MathCalculationSupport/CoordinatesPosition.h"
// 部件材料
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

		// 拷贝构造函数
		FragmentCoordinatePosition( const FragmentCoordinatePosition& FCP);

		//************设置对象******************
		//定义材料
		BaseMechanicsAndpPhysicsProperty *Frag_Material;

		//***********设置函数私有变量***********
		//设置破片的唯一标识
		const void SetFragmentGUID( const string & );
		//设置破片材料的唯一标识
		const void SetFragmentMatGUID( const string& );
		//设置飞行方向角,弧度
		const void SetSFragStaticFlyDirectionAngle( const double& );
		//设置飞行周向角,弧度
		const void SetSFragStaticFlyCircumferenceAngle( const double & );
		//设置弹体坐标系内坐标(起点),mm
		const void SetSFragIniCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//设置目标坐标系内坐标(起点)，mm
		const void SetSFragIniCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//设置弹体坐标系内坐标(终点),mm
		const void SetSFragTerCoordinatesPositionPoint_M( const CoordinatesPosition & );
		//设置目标坐标系内坐标(终点)，mm
		const void SetSFragTerCoordinatesPositionPoint_T( const CoordinatesPosition & );
		//设置单枚破片质量,g
		const void SetSFragMass( const double& );
		//设置单枚破片静态(初始)飞散速度,m/s
		const void SetSFragStaticIniFlyVelocity( const double& );
		//设置单枚破片动态(初始)飞散速度,m/s
		const void SetSFragDynamicIniFlyVelocity( const double& );
		//设置单枚破片动态(末端)飞散速度,m/s
		const void SetSFragDynamicTerFlyVelocity( const double& );
		//设置单枚破片飞行距离，m
		const void SetSFragFlyDistance( const double& );
		//设置单枚破片动态飞散方向角,度
		const void SetSFragDynamicFlyDirectionAngle( const double & );
		//设置单枚破片的速度衰减系数
		const void SetSFragVelocityReductionCoefficient( const double & );
		//设置对某一靶体的弹道极限速度，m/s
		const void SetBallisticLimitForTarget( const double & );

		//***********得到函数私有变量************
		//得到破片的唯一标识
		const string GetFragmentGUID( void ) const;
		//得到破片材料的唯一标识
		const string GetFragmentMatGUID( void ) const;
		//得到飞行方向角,弧度
		const double GetSFragStaticFlyDirectionAngle( void ) const;
		//得到飞行周向角,弧度
		const double GetSFragStaticFlyCircumferenceAngle( void ) const;
		//得到弹体坐标系内坐标(起点),mm
		const CoordinatesPosition GetSFragIniCoordinatesPositionPoint_M( void ) const;
		//得到目标坐标系内坐标(起点)，mm
		const CoordinatesPosition GetSFragIniCoordinatesPositionPoint_T( void ) const;
		//得到弹体坐标系内坐标(终点),mm
		const CoordinatesPosition GetSFragTerCoordinatesPositionPoint_M( void ) const;
		//得到目标坐标系内坐标(终点),mm
		const CoordinatesPosition GetSFragTerCoordinatesPositionPoint_T( void ) const;
		//得到单枚破片质量,g
		const double GetSFragMass( void ) const;
		//得到单枚破片静态(初始)飞散速度,m/s
		const double GetSFragStaticIniFlyVelocity( void ) const;
		//得到单枚破片动态(初始)飞散速度,m/s
		const double GetSFragDynamicIniFlyVelocity( void ) const;
		//得到单枚破片动态(末端)飞散速度,m/s
		const double GetSFragDynamicTerFlyVelocity( void ) const;
		////得到单枚破片飞行距离，m
		const double GetSFragFlyDistance( void ) const;
		//得到单枚破片动态飞散方向角,度
		const double GetSFragDynamicFlyDirectionAngle( void )const ;
		//得到单枚破片的阻力系数
		const double GetSFragResistanceCoefficient( void ) const;
		//得到对某一靶体的弹道极限速度，m/s
		const double GetBallisticLimitForTarget( void ) const;

	

	private:
		//破片序号（唯一标识）
		string FragmentGUID;
		//破片材料GUID
		string FragmentMatGUID;
		// 飞行方向角,弧度
		double StaticFlyDirectionAngle;
		// 飞行周向角,弧度
		double StaticFlyCircumferenceAngle;
		//弹体坐标系内坐标（起点）,mm
		CoordinatesPosition InitializeCoordinatesPosition_M;
		// 单枚破片目标坐标系内坐标（起点）,mm
		CoordinatesPosition InitializeCoordinatesPosition_T;
		// 弹体坐标系内坐标（终点）,mm
		CoordinatesPosition TerminalCoordinatesPosition_M;
		// 单枚破片目标坐标系内坐标（终点）,mm
		CoordinatesPosition TerminalCoordinatesPosition_T;
		//单枚破片质量,g
		double SingleFragmentMass;
		////破片材料名称(与材料类名称一致)
		//string FragmentMaterialName;
		//单枚破片静态(初始)飞散速度,m/s
		double SingleFragmentStaticIniFlyVelocity;
		//单枚破片动态(初始)飞散速度,m/s
		double SingleFragmentDynamicIniFlyVelocity;
		//单枚破片动态（末端）速度，m/s
		double SingleFragmentDynamicTerFlyVelocity;
		//单枚破片飞行距离，m
		double SingleFragmentFlyDistance;
		//单枚破片动态飞散方向角,度
		double SingleDynamicFlyDirectionAngle;
		//单枚破片的阻力系数
		double SingleFragmentVelocityReductionCoefficient;
		//对某一靶体的弹道极限速度，m/s
		double BallisticLimitForTarget;
	};

}
