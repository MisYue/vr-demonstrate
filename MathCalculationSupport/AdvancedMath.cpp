#include "AdvancedMath.h"

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//定义Pi值 = 3.1415926

namespace BIT
{
	AdvancedMath::AdvancedMath(void)
	{
	}


	AdvancedMath::~AdvancedMath(void)
	{
	}

	//测试 高等数学类 中的成员函数
	double AdvancedMath::testAdvancedMathClass(const double di, const double dj)
	{
		return sqrt(di*dj);
	}

	// 角度转弧度（编写：徐豫新，测试：徐豫新）
	double AdvancedMath::AngleToRadian(const double Angle)
	{// Angle：输入角度

		double Radian = 0;
		Radian = ( Angle / 180 ) * pi;
		return Radian;

	}

	// 弧度转角度（编写：徐豫新，测试：徐豫新）
	double AdvancedMath::RadianToAngle(const double Radian)
	{// Radian：弧度

		double Angle = 0;
		Angle = ( Radian / pi ) * 180;
		return Angle;

	}

	// 计算插值（编写：徐豫新，测试：）
	double AdvancedMath::LinearInterpolation(double xx, double tt[ ], double yy[ ], int jj)
	{// XX：X值，tt[]:X表，yy[]:Y表，jj：X和Y表中的数字个数
		double Value = 0;
		for( int ii = 1 ; ii <= jj ; ii++ )
		{

			if( ( xx > tt[ii-1]|| ( xx == tt[ii-1]) ) && ( xx < tt[ii]) )
			{
				Value = yy[ii-1] + ( xx - tt[ii-1] ) *
					( yy[ii] - yy[ii-1] ) / ( tt[ii] - tt[ii-1] );
				break;
			}
		}
		return Value;
	}

	//计算Delta(德尔塔)
	double AdvancedMath::ComputeDelta(const double aa , const double bb , const double cc)
	{
		double Delta = bb * bb - 4 * aa * cc;
		return Delta;
	}

	// 求解一元二次方程( a * x^2 + b * x + c = 0)
	double AdvancedMath::function_1yuan2ci(const double aa, const double bb, const double cc, const double Xmin, const double Xmax)
	{
		double XX = 0;
		double Delta = ComputeDelta( aa , bb ,cc ) ;
		if ( Delta < 0 )
		{
			XX = -10001;   //不能计算
		}
		else
		{
			double XX1 = (- bb + sqrt(Delta)) / 2 / aa; //原代码有误已修正
			double XX2 = (- bb - sqrt(Delta)) / 2 / aa; //原代码有误已修正
			if (( XX2 > Xmax || XX2 < Xmin) && ( XX1 > Xmax || XX1 < Xmin ))//有修正
			{
				XX = -10002;  //不在范围内
			}
			else
			{
				if ( ( ( XX1 < Xmax || XX1 == Xmax ) && ( XX1 > Xmin || XX1 == Xmin ) ) 
					&&  ( ( XX2 < Xmax || XX2 == Xmax ) && ( XX2 > Xmin || XX2 == Xmin ) ))//有修正
				{
					XX = -10003;  //范围内两个值
				} 
				else
				{
					if ( ( XX1 > Xmin || XX1 == Xmin ) &&  ( XX1 < Xmax || XX1 == Xmax ) )//有修正
					{
						XX = XX1;
					} 
					else
					{
						XX = XX2;
					}
				}
			}
		}

		return XX;
	}

	// 求一元二次方程较大解(王潇)
	double AdvancedMath::function_1yuan2ci_Max(const double aa, const double bb, const double cc)
	{
		double XX = 0;
		double Delta = ComputeDelta( aa , bb ,cc ) ;
		if ( Delta < 0 )
		{
			XX = -10001;   //不能计算
		}
		else{
			XX = (- bb + sqrt(Delta)) / 2 / aa;
		}
		return XX;
	}
	// 求一元二次方程较小解(王潇)
	double AdvancedMath::function_1yuan2ci_Min(const double aa, const double bb, const double cc)
	{
		double XX = 0;
		double Delta = ComputeDelta( aa , bb ,cc ) ;
		if ( Delta < 0 )
		{
			XX = -10001;   //不能计算
		}
		else{
			XX = (- bb - sqrt(Delta)) / 2.0 / aa;
		}
		return XX;
	}

	// 求解二元二次方程( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0)
	// （编写：徐豫新；测试：王潇）
	double AdvancedMath::function_2yuan2ci(const double aa, const  double bb, const  double cc, const double dd, const double ee,
										const double ff, const double Ymin, const double Ymax, const double xx, bool &b)
	{
		double YY = 0;

		if ( bb !=0 )
		{
			double A = bb;          
			double B = cc * xx + ee;             
			double C = aa * xx * xx + dd * xx + ff ;

			double Delta = ComputeDelta( A , B , C );

			if ( Delta < 0 )
			{
				YY = -10001;   //不能计算
			}
			else
			{
				double YY1 = (- B + sqrt(Delta)) / 2 / A; //原代码有误已修正
				double YY2 = (- B - sqrt(Delta)) / 2 / A; //原代码有误已修正
				if (( YY2 > Ymax || YY2 < Ymin) && ( YY1 > Ymax || YY1 < Ymin ))//有修正
				{
					YY = -10002;  //不在范围内
				} 
				else
				{
					if ( ( ( YY1 < Ymax || YY1 == Ymax ) && ( YY1 > Ymin || YY1 == Ymin ) ) 
						&&  ( ( YY2 < Ymax || YY2 == Ymax ) && ( YY2 > Ymin || YY2 == Ymin ) ))//有修正
					{
						YY = -10003;  //范围内两个值
					} 
					else
					{
						if ( ( YY1 > Ymin || YY1 == Ymin ) &&  ( YY1 < Ymax || YY1 == Ymax ) )//有修正
						{
							YY = YY1;
						} 
						else
						{
							YY = YY2;
						}
					}
				}
			}
		}
		else
		{
			if( cc * xx + ee != 0 )
			{
				YY = - ( aa * xx * xx + dd * xx + ff ) / ( cc * xx + ee );
				b = true;
			}

			else {
				YY = -10004; //无解
				b = false;
			}
		}

		return YY;
	}

	// 二元二次方程求导( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0) 
	//（编写：王潇，测试：王潇）
	double AdvancedMath::function2yuan2ci_differential(const double aa, const double bb, const double cc, const double dd, const double ee,
		const double ff, const double Ymin, const double Ymax, const double xx, bool &b)
	{
		double YY=0 , KK=0 ;

		if ( bb !=0 )
		{
			double delta =( ee + cc * xx ) * ( ee + cc * xx ) - 4 * bb * ( aa * xx * xx + dd * xx + ff );
			if ( delta < 0 )
			{
				KK = -10001;
			}
			else
			{
				double YY1 = ( sqrt( delta ) - ( ee + cc * xx ) ) / ( 2 * bb );
				double YY2 = ( -sqrt( delta ) - ( ee + cc * xx ) ) / ( 2 * bb );

				if (( YY2 > Ymax || YY2 < Ymin) && ( YY1 > Ymax || YY1 < Ymin ))
				{
					KK = -10002;  //不在范围内
				} 
				else
				{
					if (( YY1 <= Ymax &&  YY1 >= Ymin ) && ( YY2 <= Ymax &&  YY2 >= Ymin ))
					{
						KK = -10003;  //范围内两个值
					} 
					else
					{
						if ( YY1 >= Ymin && YY1 <= Ymax )
						{
							YY = YY1;
						} 
						else
						{
							YY = YY2;
						}
					}
					KK = - ( 2 * aa * xx + cc * YY + dd ) / ( 2 * bb * YY + cc * xx + ee );
				}
			}
		}
		else 
		{
			if ( cc * xx + ee != 0 )
			{
				YY = - ( aa * xx * xx + dd * xx + ff ) / ( cc * xx + ee );
				KK = - ( 2 * aa * xx + cc * YY + dd ) / ( 2 * bb * YY + cc * xx + ee );
				b = true;
			}
			else {
				KK = -10004;//无解
				b = false;
			}
		}
		return KK;
	}

	// 两个整数之差
	int AdvancedMath::TheDefferenceofTwoIntegers(const int Nmax, const int Nmin)
	{// Nmax：大数; Nmin：小数
		return Nmax - Nmin;
	}

	// 两个浮点数之差
	double AdvancedMath::TheDefferenceofTwoFloatNumber(const double Nmax , const double Nmin )
	{
		return Nmax - Nmin;
	}

	// 计算N个数中的最大值“或”(编写：徐豫新，)
	double AdvancedMath::ComputeMaxValueInArray(const int N, const double Array[] )
	{// N:个数，SingleP[]：每一个的概率
		double Max = Array[0];

		for( int i = 1 ; i < N; i++ )
		{
			if( Max < Array[i] || Max == Array[i] ) 
			{
				Max = Array[i];
			}
			else
			{
				Max = Max;
			}
		}

		return Max; 
	}

	// 计算N个数中的平均
	double AdvancedMath::ComputeAverageValueInArray( const int N, const double Array[] )
	{
		double Average = 0;
		for( int i = 0 ; i < N ; i++)
		{
			Average = Average + Array[i];
		}
		return Average / N;
	}

	// 求一组数中的最小数函数
	double AdvancedMath::ComputeMinValueInArray(const int N, const double Array[])
	{
		double MinNum = Array[0];

		for( int j = 1 ; j < N ; j++ )
		{
			if( MinNum < Array[j] )
				MinNum = MinNum ;
			else
				MinNum = Array[j];
		}

		return MinNum;

	}

	// 计算两个数种的较大值
	double AdvancedMath::CompareForMin(const double aa , const double bb)
	{
		//if ( aa > bb )
		//{
		//	return bb;
		//}
		//else return aa;

		//==========[尹鹏修改 2015-7-8]==========
		return (aa>bb) ? aa : bb;
	}

	// 计算两个数种的较小值
	double AdvancedMath::CompareForMax(const double aa , const double bb)
	{
		//if ( aa > bb )
		//{
		//	return aa;
		//}
		//else return bb;

		//==========[尹鹏修改 2015-7-8]==========
		return (aa>bb) ? bb : aa;
	}

	// 计算余弦定理（知道三个边计算角度）
	//IncludedAngleSideOneLength：夹角边1长度，
	//IncludedAngleSideTwoLength：夹角边2长度，
	//IncludedAngleFaceSideLength：夹角对边长度
	double AdvancedMath::ComputeFaceSideAngle(const double IncludedAngleSideOneLength ,
		const double IncludedAngleSideTwoLength , const double IncludedAngleFaceSideLength )
	{
		double IncludedAngle = 0;
		double temp = ( IncludedAngleSideOneLength * IncludedAngleSideOneLength 
			+ IncludedAngleSideTwoLength * IncludedAngleSideTwoLength 
			- IncludedAngleFaceSideLength * IncludedAngleFaceSideLength ) /
			( 2 * IncludedAngleSideOneLength * IncludedAngleSideTwoLength );
		IncludedAngle = acos( temp );
		return IncludedAngle;
	}

	// 计算非独立事件的“与”（1-(1-P1)(1-P2)...）函数
	double AdvancedMath::TheAndComputation(const int N, const double SingleP[] )
	{
		double ComValue = 1 - SingleP[0];
		for( int i = 1 ; i < N; i++ )
		{
			ComValue = ComValue * ( 1 - SingleP[i] );
		}

		return 1 - ComValue;
	}

	// 求一组数中的最小数函数及序号
	double AdvancedMath::ComputeMinValueAndNumberInArray( 
		const int N, const double Array[], int Num[] )
	{
		double MinValue = Array[0];

		for( int j = 1 ; j < N ; j++ )
		{
			if( MinValue < Array[j] )
				MinValue = MinValue;
			else
				MinValue = Array[j];
		}
		for( int i = 0 , k = 0; i < N ; i++)
		{
			if( MinValue == Array[i])
			{
				Num[k] = i;
				k++;
			}
		}

		return MinValue;
	}

	// 将标准值周围值近似为标准值
	double AdvancedMath::ComputeSimilarStandardValue( 
		const double SimilarValue , const double InputValue , const double StandardValue )
	{
		double SimilarStandardValue = 0;
		if( abs( SimilarValue - InputValue ) < StandardValue )
		{
			return SimilarValue;
		}
		else
			return InputValue;
	}

	// 计算N个数里标准差( 高鹏 )
	double AdvancedMath::ComputeStandardDifference( const int N , const double Array[] )
	{
		double StandardDifference = 0;
		double Average = 0;
		Average = ComputeAverageValueInArray( N , Array );
		for( int j = 0 ; j < N ; j++)
		{
			StandardDifference = StandardDifference 
				+ ( Average - Array[j] )*( Average - Array[j]);
		}
		StandardDifference = StandardDifference / N;
		return StandardDifference;
	}

}