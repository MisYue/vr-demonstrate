#include "ProbabilityTheoryAndRandom.h"

#ifdef pi
#undef pi
#endif

#define pi 3.14159265358979323846			//����Piֵ = 3.1415926

namespace BIT
{

	ProbabilityTheoryAndRandom::ProbabilityTheoryAndRandom(void)
	{
		srand((unsigned) time(0));  // ��ʱ������
	}


	ProbabilityTheoryAndRandom::~ProbabilityTheoryAndRandom(void)
	{
	}

//���� ����������������� �еĳ�Ա����
	double ProbabilityTheoryAndRandom::testProbabilityTheoryAndRandomClass(double di, double dj)
	{
		return (di+dj)*0.5;//��������������ƽ��ֵ
	}
    
// ���������(��д����ԥ�£� ���ԣ�)
	void ProbabilityTheoryAndRandom::GenerateRandom( double Number , int Amount  , double RandomNumber[] )
	{// Number��������ķ�Χ��Amount����������� < 1000000

		int i = 0;

		

		for ( i = 0 ; i < Amount ; i++ )
		{
			// ����0��Number֮��������
			RandomNumber[i] = rand() * Number / ( 1.0 + RAND_MAX );
		}
	}
// �õ���׼��̬�ֲ�����cos��
	double ProbabilityTheoryAndRandom::GetStandardNormalDistributionRandom_cos( double r1 , double r2 )
	{
		if( ( r1 > 0 && r1 < 1.0 ) && ( r2 > 0 && r2 < 1.0 ) )
		{
			return  sqrt ( -2 * log( r1 ) ) * cos( 2 * pi * r2 );
		}
		else
			return -10001;
		
	}
// �õ���׼��̬�ֲ�����sin��
	double ProbabilityTheoryAndRandom::GetStandardNormalDistributionRandom_sin( double r1 , double r2 )
	{
		return  sqrt ( -2 * log( r1 ) ) * sin( 2 * pi * r2 );
	}

// ��ö����������
	double ProbabilityTheoryAndRandom::ComputeExpectationOnMultiNumber( int N , double Number[] )
	{
		double Temp = 0;
		for( int i = 0 ; i < N ; i++ )
		{
			Temp = Temp + Number[i];
		}
		return Temp / N;
	}

// ��ö�����ε��ƽ��ֵ
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
	//int:��������>0�����������(0-1֮��������)��õ�ֵ���������
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