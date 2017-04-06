#include "ProbabilityTheoryAndRandom.h"

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{

	ProbabilityTheoryAndRandom::ProbabilityTheoryAndRandom(void)
	{
		srand((unsigned) time(0));  // 用时间做种
	}


	ProbabilityTheoryAndRandom::~ProbabilityTheoryAndRandom(void)
	{
	}

//测试 概率论与随机抽样类 中的成员函数
	double ProbabilityTheoryAndRandom::testProbabilityTheoryAndRandomClass(double di, double dj)
	{
		return (di+dj)*0.5;//返回两数的算术平均值
	}
    
// 产生随机数(编写：徐豫新， 测试：)
	void ProbabilityTheoryAndRandom::GenerateRandom( double Number , int Amount  , double RandomNumber[] )
	{// Number：随机数的范围，Amount：随机数个数 < 1000000

		int i = 0;

		

		for ( i = 0 ; i < Amount ; i++ )
		{
			// 产生0～Number之间的随机数
			RandomNumber[i] = rand() * Number / ( 1.0 + RAND_MAX );
		}
	}
// 得到标准正态分布基于cos的
	double ProbabilityTheoryAndRandom::GetStandardNormalDistributionRandom_cos( double r1 , double r2 )
	{
		if( ( r1 > 0 && r1 < 1.0 ) && ( r2 > 0 && r2 < 1.0 ) )
		{
			return  sqrt ( -2 * log( r1 ) ) * cos( 2 * pi * r2 );
		}
		else
			return -10001;
		
	}
// 得到标准正态分布基于sin的
	double ProbabilityTheoryAndRandom::GetStandardNormalDistributionRandom_sin( double r1 , double r2 )
	{
		return  sqrt ( -2 * log( r1 ) ) * sin( 2 * pi * r2 );
	}

// 获得多个数的期望
	double ProbabilityTheoryAndRandom::ComputeExpectationOnMultiNumber( int N , double Number[] )
	{
		double Temp = 0;
		for( int i = 0 ; i < N ; i++ )
		{
			Temp = Temp + Number[i];
		}
		return Temp / N;
	}

// 获得多个几何点的平均值
	BIT::CoordinatesPosition ProbabilityTheoryAndRandom::GetExpectationOnMultiPoint( int N , CoordinatesPosition Point[] )
	{
		CoordinatesPosition P1 = ( 0 , 0 , 0 );
		if( N == 0 )
		{

		}
		else
		{
			for( int i = 0 ; i < N ; i++ )
			{
				P1.Set_x( P1.Get_x() + Point[i].Get_x() );
				P1.Set_y( P1.Get_y() + Point[i].Get_y() );
				P1.Set_z( P1.Get_z() + Point[i].Get_z() );
			}

			P1.Set_x( P1.Get_x() / N );
			P1.Set_y( P1.Get_y() / N );
			P1.Set_z( P1.Get_z() / N );
		}

		return P1;
	}
	//int:样本量（>0），随机抽样(0-1之间的随机数)获得的值放入的数组
	void ProbabilityTheoryAndRandom::SampleOnSampleNumber( const int SN , double RN_AEPA[] )
	{
		if( SN < 0 || SN == 0 )
		{
			return;
		}
		else
		{
			GenerateRandom( 1 , SN , RN_AEPA );
		}
	}

}