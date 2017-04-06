/*
���ƣ���������������� ProbabilityTheoryAndRandom
���ܣ�֧�Ž����������ȡ�ȼ���
�����ˣ�
����ʱ�䣺
�汾��1.0
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

		static double testProbabilityTheoryAndRandomClass(double di, double dj);//���� ����������������� �еĳ�Ա����

		// �������������
        // Number��������ķ�Χ��Amount�������������RandomNumber[]�����������
		static void GenerateRandom( double Number , int Amount  , double RandomNumber[] );
		// �õ���׼��̬�ֲ�����cos��
		static double GetStandardNormalDistributionRandom_cos( double r1 , double r2 );
		// �õ���׼��̬�ֲ�����sin��
		static double GetStandardNormalDistributionRandom_sin( double r1 , double r2 );
		// ��ö����������
		static double ComputeExpectationOnMultiNumber( int N , double Number[] );
		// ��ö�����ε��ƽ��ֵ
		static CoordinatesPosition GetExpectationOnMultiPoint( int N , CoordinatesPosition Point[] );
		// �������������������
		//int:��������>0�����������(0-1֮��������)��õ�ֵ���������
		static void SampleOnSampleNumber( const int , double RN_AEPA[]);
	};
	
}

