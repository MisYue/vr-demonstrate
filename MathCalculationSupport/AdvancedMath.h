/*
名称：高等数学 AdvancedMath
功能：支撑进行高等数据的分析计算
创建人：
创建时间：
版本：1.0

修改人：岳群磊
修改日期：2016年5月30日
修改描述：修改库的使用接口
版本：1.1
*/
#include <cstdlib>
#include <time.h>
#include <math.h>

#pragma once
#include "MathCalculationSupport_Global.h"

namespace BIT
{
	class MATHCALCULATIONSUPPORT_API AdvancedMath
	{
	public:
		AdvancedMath(void);
		~AdvancedMath(void);

		static double testAdvancedMathClass(const double di, const double dj);//测试 高等数学类 中1成员函数

		// 角度转弧度
		static double AngleToRadian(const double Angle);
		// 弧度转角度
		static double RadianToAngle(const double Radian);
		// 求插值
		static double LinearInterpolation(double xx, double tt[ ], double yy[ ], int jj);
		//计算Delta(德尔塔)
		static double ComputeDelta(const double aa , const double bb , const double cc);
		// 求解一元二次方程( a * x^2 + b * x + c = 0)
		static double function_1yuan2ci(const double aa, const double bb, const double cc, const double Xmin, const double Xmax);
		// 求一元二次方程较大解( a * x^2 + b * x + c = 0)
		static double function_1yuan2ci_Max(const double aa, const double bb, const double cc);
		// 求一元二次方程较小解( a * x^2 + b * x + c = 0)
		static double function_1yuan2ci_Min(const double aa, const double bb, const double cc);

		//==========[尹鹏 修改 2015-7-8]==========
		// 求解二元二次方程( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0)
		static double function_2yuan2ci(const double aa, const  double bb, const  double cc, const double dd, const double ee,
							const double ff, const double Ymin, const double Ymax, const double xx, bool &b);
		// 二元二次方程求导( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0) 
		static double function2yuan2ci_differential(const double aa, const double bb, const double cc, const double dd, const double ee,
										const double ff, const double Ymin, const double Ymax, const double xx, bool &b);

		//==========[尹鹏 改用模板函数较好 2015-7-8]==========
		// 两个整数之差
		static int TheDefferenceofTwoIntegers(const int Nmax, const int Nmin);
		// 两个浮点数之差
		static double TheDefferenceofTwoFloatNumber(const double Nmax ,const double Nmin);

		// 求一组数中的最小数函数
		static double ComputeMinValueInArray(const int N, const double Array[] );

		// 求一组数中的最小数函数及序号
		static double ComputeMinValueAndNumberInArray(const int N, const double Array[], int Num[]);
		
		// 求两个数中的较小数
		static double CompareForMin(const double aa , const double bb);
		// 求两个数中的较大数
		static double CompareForMax(const double aa , const double bb);

		// 计算N个数中的最大值
		static double ComputeMaxValueInArray(const int N, const double Array[] );
		// 计算N个数中的平均
		static double ComputeAverageValueInArray(const int N, const double Array[] );
		// 计算N个数中的标准差
		static double ComputeStandardDifference( const int N , const double Array[]);
		// 计算非独立事件的“与”（1-(1-P1)(1-P2)...）函数
		static double TheAndComputation(const int N, const double SingleP[] );

		// 计算余弦定理（知道三个边计算角度）
		//IncludedAngleSideOneLength：夹角边1长度，
		//IncludedAngleSideTwoLength：夹角边2长度，
		//IncludedAngleFaceSideLength：夹角对边长度
		static double ComputeFaceSideAngle(const double IncludedAngleSideOneLength ,
			const double IncludedAngleSideTwoLength , const double IncludedAngleFaceSideLength );
		
		// 将标准值周围值近似为标准值
		static double ComputeSimilarStandardValue( const double SimilarValue ,
			const double InputValue , const double StandardValue );
	};
}

