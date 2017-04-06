//***************************************
//	创建时间:	2017:3:28   14:08
//	文件名称: 	penetrationcount.h
//	文件作者:	岳群磊
//	
//	功能说明:	侵彻计算类定义
//***************************************

#ifndef PENETRATIONCOUNT_H
#define PENETRATIONCOUNT_H

#include "penetrationcount_global.h"

// 定义弹道末端数据
// 定义部件数据
// 定义目标数据
// 定义战斗部数据
// 由弹道末端偏航及位置计算弹道线
// 由弹道线计算与各部件的交会点
// 对每个有交会点的部件，求运动到交会点的时间，若时间累积超过引信时间，则在交会之前爆炸，记录爆炸时间，位置，姿态
// 若没有超过引信时间，求是否贯穿
// 若不能贯穿，则战斗部会在靶中爆炸，求侵彻深度，记录时间，位置，姿态
// 若贯穿，求剩余速度，记录时间，交会点，姿态
// 

// 侵彻计算参数
struct PCP
{
	double iv; // 初速 m/s
	double wm; // 质量 kg
	double wd; // 圆柱段直径 m
	double bt; // 靶板厚度 m
	double ca; // 弹头着角 °
	PCP()
		: iv(0), wm(0), wd(0), bt(0), ca(0)
	{

	}
};

// 卵头弹侵彻计算参数
struct PCPOval : public PCP
{
	double oria;	// 卵形弹修正系数A,一般为2400, 与战斗部壳体材料和靶板材料有关
	PCPOval()
		: oria(0)
	{

	}
};

// 尖头弹侵彻计算参数
struct PCPSharp : public PCP
{
	double ctik; // 尖头弹实验系数K
	double cfpd; // 截锥形弹平顶部分直径,m
	double chc; // 尖头弹半锥角,度
	double md; // 靶板材料密度,kg/m^3
	PCPSharp()
		: ctik(0), cfpd(0), chc(0), md(0)
	{

	}
};
class PENETRATIONCOUNT_EXPORT PenetrationCount
{
public:
	PenetrationCount();
	~PenetrationCount();
	// 卵头弹侵彻深度及剩余速度计算
	// pcp:侵彻计算参数
	// vr:剩余速度
	// pd:侵彻深度
	bool CountOval(const PCPOval& pcp, double& vr, double& pd);

	// 尖头弹侵彻深度及剩余速度计算
	// pcp:侵彻计算参数
	// vr:剩余速度
	// pd:侵彻深度
	bool CountSharp(const PCPSharp& pcp, double& vr, double& pd);
private:

};

#endif // PENETRATIONCOUNT_H
