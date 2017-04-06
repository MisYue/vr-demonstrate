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
		//破片唯一标识
		FragGUID = FragmentGUID;
		//破片材料唯一标识
		FragMatGUID = FragmentMatGUID;
		// 飞行方向角
		StaticFlyDirectionAngle = FlyDirAng;
		// 飞行周向角
		StaticFlyCircumferenceAngle = FlyCirAng;
		// 弹体坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_M = IniCoordPos_M;
		// 单枚破片目标坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_T = IniCoordPos_T;
		// 弹体坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_M = TerCoordPos_M;
		// 单枚破片目标坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_T = TerCoordPos_T;
		// 单枚破片质量,g
		SingleFragmentMass = SingFragMass;
		//单枚破片静态（初始）飞散速度,m/s
		SingleFragmentStaticIniFlyVelocity = SingFragStatIniFlyVel;
		//单枚破片动态（初始）飞散速度,m/s
		SingleFragmentDynamicIniFlyVelocity = SingFragDynaIniFlyVel;
		//单枚破片动态（末端）飞行速度，m/w
		SingleFragmentDynamicTerFlyVelocity = SingFragDynaTerFlyVel;
		//单枚破片飞行距离，m
		SingFragFlyDist = SingleFragmentFlyDistance;
		//单枚破片动态飞散方向角,度
		SingleDynamicFlyDirectionAngle = SingDynaFlyDirAngle;
		//单枚破片的阻力系数
		SingleFragmentVelocityReductionCoefficient = SingFragResistCoe;
		//对某一靶体的弹道极限速度，m/s
		BallisticLimitForTarget = BalLimForTar;

		// 破片材料
		Frag_Material = new BaseMechanicsAndpPhysicsProperty();
	}
	
	// 拷贝构造函数
	FragmentCoordinatePosition::FragmentCoordinatePosition( const FragmentCoordinatePosition& FCP )
	{
		//破片序号（唯一标识）
		FragmentGUID = FCP.FragmentGUID;
		//破片材料GUID
		FragmentMatGUID = FCP.FragmentMatGUID;
		// 飞行方向角,弧度
		StaticFlyDirectionAngle = FCP.StaticFlyDirectionAngle;
		// 飞行周向角,弧度
		StaticFlyCircumferenceAngle = FCP.StaticFlyCircumferenceAngle;
		//弹体坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_M = FCP.InitializeCoordinatesPosition_M;
		// 单枚破片目标坐标系内坐标（起点）,mm
		InitializeCoordinatesPosition_T = FCP.InitializeCoordinatesPosition_T;
		// 弹体坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_M = FCP.TerminalCoordinatesPosition_M;
		// 单枚破片目标坐标系内坐标（终点）,mm
		TerminalCoordinatesPosition_T = FCP.TerminalCoordinatesPosition_T;
		//单枚破片质量,g
		SingleFragmentMass = FCP.SingleFragmentMass;
		////破片材料名称(与材料类名称一致)
		//string FragmentMaterialName;
		//单枚破片静态(初始)飞散速度,m/s
		SingleFragmentStaticIniFlyVelocity = FCP.SingleFragmentStaticIniFlyVelocity;
		//单枚破片动态(初始)飞散速度,m/s
		SingleFragmentDynamicIniFlyVelocity = FCP.SingleFragmentDynamicIniFlyVelocity;
		//单枚破片动态（末端）速度，m/s
		SingleFragmentDynamicTerFlyVelocity = FCP.SingleFragmentDynamicTerFlyVelocity;
		//单枚破片飞行距离，m
		SingleFragmentFlyDistance = FCP.SingleFragmentFlyDistance;
		//单枚破片动态飞散方向角,度
		SingleDynamicFlyDirectionAngle = FCP.SingleDynamicFlyDirectionAngle;
		//单枚破片的阻力系数
		SingleFragmentVelocityReductionCoefficient = FCP.SingleFragmentVelocityReductionCoefficient;
		//对某一靶体的弹道极限速度，m/s
		BallisticLimitForTarget = FCP.BallisticLimitForTarget;
	}

	FragmentCoordinatePosition::~FragmentCoordinatePosition(void)
	{
		// 破片材料
		if( Frag_Material != NULL ) 
			delete Frag_Material;
	}
	//***********设置函数私有变量***********
	//设置破片的唯一标识
	const void FragmentCoordinatePosition::SetFragmentGUID( const string &FGUID )
	{
		FragmentGUID = FGUID;
	}
	//设置破片材料的唯一标识
	const void FragmentCoordinatePosition::SetFragmentMatGUID( const string &FMatGUID )
	{
		FragmentMatGUID = FMatGUID ;
	}
	//设置飞行方向角,弧度
	const void FragmentCoordinatePosition::SetSFragStaticFlyDirectionAngle( 
		const double &SFDA )
	{
		StaticFlyDirectionAngle = SFDA;
	}
	//设置飞行周向角,弧度
	const void FragmentCoordinatePosition::SetSFragStaticFlyCircumferenceAngle( 
		const double &SFCA )
	{
		StaticFlyCircumferenceAngle = SFCA;
	}
	//设置弹体坐标系内坐标(起点),mm
	const void FragmentCoordinatePosition::SetSFragIniCoordinatesPositionPoint_M( 
		const CoordinatesPosition &ICPP_M )
	{
		InitializeCoordinatesPosition_M = ICPP_M;
	}
	//设置目标坐标系内坐标(终点)，mm
	const void FragmentCoordinatePosition::SetSFragIniCoordinatesPositionPoint_T( 
		const CoordinatesPosition &ICPP_T )
	{
		InitializeCoordinatesPosition_T = ICPP_T;
	}
	//设置弹体坐标系内坐标(终点),mm
	const void FragmentCoordinatePosition::SetSFragTerCoordinatesPositionPoint_M( 
		const CoordinatesPosition &TCPP_M )
	{
		TerminalCoordinatesPosition_M = TCPP_M;
	}

	//设置目标坐标系内坐标(终点)，mm
	const void FragmentCoordinatePosition::SetSFragTerCoordinatesPositionPoint_T( 
		const CoordinatesPosition &TCPP_T )
	{
		// 单枚破片目标坐标系内坐标,mm
		TerminalCoordinatesPosition_T = TCPP_T;
	}
	//设置单枚破片质量,g
	const void FragmentCoordinatePosition::SetSFragMass( const double &SFM )
	{
		// 单枚破片质量,g
		SingleFragmentMass = SFM;
	}
	//设置单枚破片静态（初始）飞散速度,m/s
	const void FragmentCoordinatePosition::SetSFragStaticIniFlyVelocity( const double &SFSIFV )
	{
		//单枚破片静态（初始）飞散速度,m/s
		SingleFragmentStaticIniFlyVelocity = SFSIFV;
	}
	//设置单枚破片动态（初始）飞散速度,m/s
	const void FragmentCoordinatePosition::SetSFragDynamicIniFlyVelocity( const double &SFDIFV )
	{
		//单枚破片动态（初始）飞散速度,m/s
		SingleFragmentDynamicIniFlyVelocity = SFDIFV;
	}
	//设置单枚破片动态(末端)飞散速度,m/s
	const void FragmentCoordinatePosition::SetSFragDynamicTerFlyVelocity( const double &SFDTFV )
	{
		SingleFragmentDynamicTerFlyVelocity = SFDTFV;
	}
	//设置单枚破片动态飞散方向角,度
	const void FragmentCoordinatePosition::SetSFragDynamicFlyDirectionAngle( const double &SDFDA )
	{
		//单枚破片动态飞散方向角,度
		SingleDynamicFlyDirectionAngle = SDFDA;
	}
	//设置单枚破片的阻力系数
	const void FragmentCoordinatePosition::SetSFragVelocityReductionCoefficient( const double &SFVRC )
	{
		//单枚破片的阻力系数
		SingleFragmentVelocityReductionCoefficient = SFVRC;
	}
	//设置破片对某一靶体的弹道极限
	const void FragmentCoordinatePosition::SetBallisticLimitForTarget( const double &BLFT )
	{
		BallisticLimitForTarget = BLFT;
	}
	// 设置单枚破片飞行距离
	const void FragmentCoordinatePosition::SetSFragFlyDistance( const double &SFFD )
	{
		SingleFragmentFlyDistance = SFFD;
	}

	//***********得到函数私有变量************
	//得到破片的唯一标识
	const std::string FragmentCoordinatePosition::GetFragmentGUID( void ) const
	{
		return FragmentGUID;
	}
	//得到破片材料的唯一标识
	const std::string FragmentCoordinatePosition::GetFragmentMatGUID( void ) const
	{
		return FragmentMatGUID;
	}
	//得到飞行方向角,弧度
	const double FragmentCoordinatePosition::GetSFragStaticFlyDirectionAngle( void ) const
	{
		return StaticFlyDirectionAngle;
	}

	//得到飞行周向角,弧度
	const double FragmentCoordinatePosition::GetSFragStaticFlyCircumferenceAngle( void ) const
	{
		return StaticFlyCircumferenceAngle;
	}
	//得到弹体坐标系内坐标(起点),mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragIniCoordinatesPositionPoint_M( void ) const
	{
		return InitializeCoordinatesPosition_M;
	}
	//得到目标坐标系内坐标(起点)，mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragIniCoordinatesPositionPoint_T( void ) const
	{
		return InitializeCoordinatesPosition_T;
	}
	//得到弹体坐标系内坐标(终点),mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragTerCoordinatesPositionPoint_M( void ) const
	{
		return TerminalCoordinatesPosition_M;
	}

	//得到目标坐标系内坐标(终点)，mm
	const BIT::CoordinatesPosition FragmentCoordinatePosition::GetSFragTerCoordinatesPositionPoint_T( void ) const
	{
		return TerminalCoordinatesPosition_T;
	}
	//得到单枚破片质量,g
	const double FragmentCoordinatePosition::GetSFragMass( void ) const
	{
		return SingleFragmentMass;
	}
	//得到单枚破片静态飞散速度,m/s
	const double FragmentCoordinatePosition::GetSFragStaticIniFlyVelocity( void ) const
	{
		return SingleFragmentStaticIniFlyVelocity;
	}
	//得到单枚破片动态飞散速度,m/s
	const double FragmentCoordinatePosition::GetSFragDynamicIniFlyVelocity( void ) const
	{
		return SingleFragmentDynamicIniFlyVelocity;
	}
	//得到单枚破片动态(末端)飞散速度,m/s
	const double FragmentCoordinatePosition::GetSFragDynamicTerFlyVelocity( void ) const
	{
		return SingleFragmentDynamicTerFlyVelocity;
	}
	//得到单枚破片动态飞散方向角,度
	const double FragmentCoordinatePosition::GetSFragDynamicFlyDirectionAngle( void ) const
	{
		return SingleDynamicFlyDirectionAngle;
	}
	//得到单枚破片的阻力系数
	const double FragmentCoordinatePosition::GetSFragResistanceCoefficient( void ) const
	{
		return SingleFragmentVelocityReductionCoefficient;
	}

	

	//得到对某一靶体的弹道极限速度，m/s
	const double FragmentCoordinatePosition::GetBallisticLimitForTarget( void )const
	{
		return BallisticLimitForTarget;
	}
	
	////得到单枚破片飞行距离，m
	const double FragmentCoordinatePosition::GetSFragFlyDistance( void ) const
	{
		return SingleFragmentFlyDistance;
	}

}
