#include "AdvancedMath.h"

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{
	AdvancedMath::AdvancedMath(void)
	{
	}


	AdvancedMath::~AdvancedMath(void)
	{
	}

	//���� �ߵ���ѧ�� �еĳ�Ա����
	double AdvancedMath::testAdvancedMathClass(const double di, const double dj)
	{
		return sqrt(di*dj);
	}

	// �Ƕ�ת���ȣ���д����ԥ�£����ԣ���ԥ�£�
	double AdvancedMath::AngleToRadian(const double Angle)
	{// Angle������Ƕ�

		double Radian = 0;
		Radian = ( Angle / 180 ) * pi;
		return Radian;

	}

	// ����ת�Ƕȣ���д����ԥ�£����ԣ���ԥ�£�
	double AdvancedMath::RadianToAngle(const double Radian)
	{// Radian������

		double Angle = 0;
		Angle = ( Radian / pi ) * 180;
		return Angle;

	}

	// �����ֵ����д����ԥ�£����ԣ���
	double AdvancedMath::LinearInterpolation(double xx, double tt[ ], double yy[ ], int jj)
	{// XX��Xֵ��tt[]:X��yy[]:Y��jj��X��Y���е����ָ���
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

	//����Delta(�¶���)
	double AdvancedMath::ComputeDelta(const double aa , const double bb , const double cc)
	{
		double Delta = bb * bb - 4 * aa * cc;
		return Delta;
	}

	// ���һԪ���η���( a * x^2 + b * x + c = 0)
	double AdvancedMath::function_1yuan2ci(const double aa, const double bb, const double cc, const double Xmin, const double Xmax)
	{
		double XX = 0;
		double Delta = ComputeDelta( aa , bb ,cc ) ;
		if ( Delta < 0 )
		{
			XX = -10001;   //���ܼ���
		}
		else
		{
			double XX1 = (- bb + sqrt(Delta)) / 2 / aa; //ԭ��������������
			double XX2 = (- bb - sqrt(Delta)) / 2 / aa; //ԭ��������������
			if (( XX2 > Xmax || XX2 < Xmin) && ( XX1 > Xmax || XX1 < Xmin ))//������
			{
				XX = -10002;  //���ڷ�Χ��
			}
			else
			{
				if ( ( ( XX1 < Xmax || XX1 == Xmax ) && ( XX1 > Xmin || XX1 == Xmin ) ) 
					&&  ( ( XX2 < Xmax || XX2 == Xmax ) && ( XX2 > Xmin || XX2 == Xmin ) ))//������
				{
					XX = -10003;  //��Χ������ֵ
				} 
				else
				{
					if ( ( XX1 > Xmin || XX1 == Xmin ) &&  ( XX1 < Xmax || XX1 == Xmax ) )//������
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

	// ��һԪ���η��̽ϴ��(����)
	double AdvancedMath::function_1yuan2ci_Max(const double aa, const double bb, const double cc)
	{
		double XX = 0;
		double Delta = ComputeDelta( aa , bb ,cc ) ;
		if ( Delta < 0 )
		{
			XX = -10001;   //���ܼ���
		}
		else{
			XX = (- bb + sqrt(Delta)) / 2 / aa;
		}
		return XX;
	}
	// ��һԪ���η��̽�С��(����)
	double AdvancedMath::function_1yuan2ci_Min(const double aa, const double bb, const double cc)
	{
		double XX = 0;
		double Delta = ComputeDelta( aa , bb ,cc ) ;
		if ( Delta < 0 )
		{
			XX = -10001;   //���ܼ���
		}
		else{
			XX = (- bb - sqrt(Delta)) / 2.0 / aa;
		}
		return XX;
	}

	// ����Ԫ���η���( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0)
	// ����д����ԥ�£����ԣ����죩
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
				YY = -10001;   //���ܼ���
			}
			else
			{
				double YY1 = (- B + sqrt(Delta)) / 2 / A; //ԭ��������������
				double YY2 = (- B - sqrt(Delta)) / 2 / A; //ԭ��������������
				if (( YY2 > Ymax || YY2 < Ymin) && ( YY1 > Ymax || YY1 < Ymin ))//������
				{
					YY = -10002;  //���ڷ�Χ��
				} 
				else
				{
					if ( ( ( YY1 < Ymax || YY1 == Ymax ) && ( YY1 > Ymin || YY1 == Ymin ) ) 
						&&  ( ( YY2 < Ymax || YY2 == Ymax ) && ( YY2 > Ymin || YY2 == Ymin ) ))//������
					{
						YY = -10003;  //��Χ������ֵ
					} 
					else
					{
						if ( ( YY1 > Ymin || YY1 == Ymin ) &&  ( YY1 < Ymax || YY1 == Ymax ) )//������
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
				YY = -10004; //�޽�
				b = false;
			}
		}

		return YY;
	}

	// ��Ԫ���η�����( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0) 
	//����д�����죬���ԣ����죩
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
					KK = -10002;  //���ڷ�Χ��
				} 
				else
				{
					if (( YY1 <= Ymax &&  YY1 >= Ymin ) && ( YY2 <= Ymax &&  YY2 >= Ymin ))
					{
						KK = -10003;  //��Χ������ֵ
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
				KK = -10004;//�޽�
				b = false;
			}
		}
		return KK;
	}

	// ��������֮��
	int AdvancedMath::TheDefferenceofTwoIntegers(const int Nmax, const int Nmin)
	{// Nmax������; Nmin��С��
		return Nmax - Nmin;
	}

	// ����������֮��
	double AdvancedMath::TheDefferenceofTwoFloatNumber(const double Nmax , const double Nmin )
	{
		return Nmax - Nmin;
	}

	// ����N�����е����ֵ����(��д����ԥ�£�)
	double AdvancedMath::ComputeMaxValueInArray(const int N, const double Array[] )
	{// N:������SingleP[]��ÿһ���ĸ���
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

	// ����N�����е�ƽ��
	double AdvancedMath::ComputeAverageValueInArray( const int N, const double Array[] )
	{
		double Average = 0;
		for( int i = 0 ; i < N ; i++)
		{
			Average = Average + Array[i];
		}
		return Average / N;
	}

	// ��һ�����е���С������
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

	// �����������ֵĽϴ�ֵ
	double AdvancedMath::CompareForMin(const double aa , const double bb)
	{
		//if ( aa > bb )
		//{
		//	return bb;
		//}
		//else return aa;

		//==========[�����޸� 2015-7-8]==========
		return (aa>bb) ? aa : bb;
	}

	// �����������ֵĽ�Сֵ
	double AdvancedMath::CompareForMax(const double aa , const double bb)
	{
		//if ( aa > bb )
		//{
		//	return aa;
		//}
		//else return bb;

		//==========[�����޸� 2015-7-8]==========
		return (aa>bb) ? bb : aa;
	}

	// �������Ҷ���֪�������߼���Ƕȣ�
	//IncludedAngleSideOneLength���нǱ�1���ȣ�
	//IncludedAngleSideTwoLength���нǱ�2���ȣ�
	//IncludedAngleFaceSideLength���нǶԱ߳���
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

	// ����Ƕ����¼��ġ��롱��1-(1-P1)(1-P2)...������
	double AdvancedMath::TheAndComputation(const int N, const double SingleP[] )
	{
		double ComValue = 1 - SingleP[0];
		for( int i = 1 ; i < N; i++ )
		{
			ComValue = ComValue * ( 1 - SingleP[i] );
		}

		return 1 - ComValue;
	}

	// ��һ�����е���С�����������
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

	// ����׼ֵ��Χֵ����Ϊ��׼ֵ
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

	// ����N�������׼��( ���� )
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