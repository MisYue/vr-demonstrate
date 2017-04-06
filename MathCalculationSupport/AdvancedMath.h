/*
���ƣ��ߵ���ѧ AdvancedMath
���ܣ�֧�Ž��иߵ����ݵķ�������
�����ˣ�
����ʱ�䣺
�汾��1.0

�޸��ˣ���Ⱥ��
�޸����ڣ�2016��5��30��
�޸��������޸Ŀ��ʹ�ýӿ�
�汾��1.1
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

		static double testAdvancedMathClass(const double di, const double dj);//���� �ߵ���ѧ�� ��1��Ա����

		// �Ƕ�ת����
		static double AngleToRadian(const double Angle);
		// ����ת�Ƕ�
		static double RadianToAngle(const double Radian);
		// ���ֵ
		static double LinearInterpolation(double xx, double tt[ ], double yy[ ], int jj);
		//����Delta(�¶���)
		static double ComputeDelta(const double aa , const double bb , const double cc);
		// ���һԪ���η���( a * x^2 + b * x + c = 0)
		static double function_1yuan2ci(const double aa, const double bb, const double cc, const double Xmin, const double Xmax);
		// ��һԪ���η��̽ϴ��( a * x^2 + b * x + c = 0)
		static double function_1yuan2ci_Max(const double aa, const double bb, const double cc);
		// ��һԪ���η��̽�С��( a * x^2 + b * x + c = 0)
		static double function_1yuan2ci_Min(const double aa, const double bb, const double cc);

		//==========[���� �޸� 2015-7-8]==========
		// ����Ԫ���η���( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0)
		static double function_2yuan2ci(const double aa, const  double bb, const  double cc, const double dd, const double ee,
							const double ff, const double Ymin, const double Ymax, const double xx, bool &b);
		// ��Ԫ���η�����( a * x^2 + b * y^2 + c * x * y + d * x + e * y + f = 0) 
		static double function2yuan2ci_differential(const double aa, const double bb, const double cc, const double dd, const double ee,
										const double ff, const double Ymin, const double Ymax, const double xx, bool &b);

		//==========[���� ����ģ�庯���Ϻ� 2015-7-8]==========
		// ��������֮��
		static int TheDefferenceofTwoIntegers(const int Nmax, const int Nmin);
		// ����������֮��
		static double TheDefferenceofTwoFloatNumber(const double Nmax ,const double Nmin);

		// ��һ�����е���С������
		static double ComputeMinValueInArray(const int N, const double Array[] );

		// ��һ�����е���С�����������
		static double ComputeMinValueAndNumberInArray(const int N, const double Array[], int Num[]);
		
		// ���������еĽ�С��
		static double CompareForMin(const double aa , const double bb);
		// ���������еĽϴ���
		static double CompareForMax(const double aa , const double bb);

		// ����N�����е����ֵ
		static double ComputeMaxValueInArray(const int N, const double Array[] );
		// ����N�����е�ƽ��
		static double ComputeAverageValueInArray(const int N, const double Array[] );
		// ����N�����еı�׼��
		static double ComputeStandardDifference( const int N , const double Array[]);
		// ����Ƕ����¼��ġ��롱��1-(1-P1)(1-P2)...������
		static double TheAndComputation(const int N, const double SingleP[] );

		// �������Ҷ���֪�������߼���Ƕȣ�
		//IncludedAngleSideOneLength���нǱ�1���ȣ�
		//IncludedAngleSideTwoLength���нǱ�2���ȣ�
		//IncludedAngleFaceSideLength���нǶԱ߳���
		static double ComputeFaceSideAngle(const double IncludedAngleSideOneLength ,
			const double IncludedAngleSideTwoLength , const double IncludedAngleFaceSideLength );
		
		// ����׼ֵ��Χֵ����Ϊ��׼ֵ
		static double ComputeSimilarStandardValue( const double SimilarValue ,
			const double InputValue , const double StandardValue );
	};
}

