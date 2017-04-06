/*
名称：概率论与随机抽样 ProbabilityTheoryAndRandom
功能：支撑进行随机数抽取等计算
创建人：
创建时间：
版本：1.0
*/


#pragma once
#include "MathCalculationSupport_Global.h"

#include "CoordinatesPosition.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>


namespace BIT
{
	class MATHCALCULATIONSUPPORT_API ProbabilityTheoryAndRandom
	{
	public:
		ProbabilityTheoryAndRandom(void);
		~ProbabilityTheoryAndRandom(void);

		static double testProbabilityTheoryAndRandomClass(double di, double dj);//测试 概率论与随机抽样类 中的成员函数

		// 产生随机数函数
        // Number：随机数的范围，Amount：随机数个数，RandomNumber[]产生的随机数
		static void GenerateRandom( double Number , int Amount  , double RandomNumber[] );
		// 得到标准正态分布基于cos的
		static double GetStandardNormalDistributionRandom_cos( double r1 , double r2 );
		// 得到标准正态分布基于sin的
		static double GetStandardNormalDistributionRandom_sin( double r1 , double r2 );
		// 获得多个数的期望
		static double ComputeExpectationOnMultiNumber( int N , double Number[] );
		// 获得多个几何点的平均值
		static CoordinatesPosition GetExpectationOnMultiPoint( int N , CoordinatesPosition Point[] );
		// 根据样本进行随机抽样
		//int:样本量（>0），随机抽样(0-1之间的随机数)获得的值放入的数组
		static void SampleOnSampleNumber( const int , double RN_AEPA[]);
	};
	
}

