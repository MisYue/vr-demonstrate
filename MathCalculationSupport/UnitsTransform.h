/*
���ƣ� ��λת��  UnitsTransform
���ܣ�֧�Ž��в�ͬ��λֵ֮���ת������
�����ˣ���ԥ��
����ʱ�䣺 2015��4��5
�汾��1.0
*/

#pragma once

#include "MathCalculationSupport_Global.h"

namespace BIT
{
	class MATHCALCULATIONSUPPORT_API UnitsTransform
	{
	public:
		UnitsTransform(void);
		~UnitsTransform(void);

		//******ѹ����λ��ת��**********
		// 1�ͣ�bar��=10^5����Pa�� 
		static double BarToPa(double Bar);
		// 1��(Pa) = 10^-5��(bar)
		static double PaToBar(double Pa);
		// 1Psi = 0.00689Mpa
		static double PsiToMPa(double Psi);
		// 1MPa = 145.03725(Psi = ����/Ӣ��2)
		static double MpaToPsi(double Mpa);

		//******������λ��ת��**********
		// 1��(lb)=0.4536ǧ��(kg)
		static double BlToKg(double Bl);
		// 1ǧ��(Kg)=2.2046��(Bl)
		static double KgToBl(double Kg);
		// ��(g)=10^-3ǧ��(kg)
		static double GToKg( double G );
		// 1ǧ��(kg) = 10^3��(g)
		static double KgToG( double Kg );

		//*******���ȵ�λ��ת��*********
		// 1��(M)=39.37Ӣ��(in)
		static double MiToIn(double Mi);
		// 1Ӣ��(in)=0.0254��(M)
		static double InToMi(double In);
		// 1��(M)=3.2808Ӣ��(in)
		static double MiToFt(double Mi);
		// 1Ӣ��(ft)=0.3048��(M)
		static double FtToMi(double Ft);
		// 1��(m) = 1000����(mm)
		static double MiToMm( double Mi );
		// 1����(mm) = 0.001��(m)
		static double MmToMi( double Mm );
		// 1����(mm) = 0.1����(cm)
		static double MmToCm( double Mm );
		// 1����(mm) = 0.01����(dm)
		static double MmToDm( double Mm );
		// 1����(cm) = 10����(mm)
		static double CmToMm( double Cm );
		// 1����(mm) = 0.1����(dm)
		static double CmToDm( double Cm );
		// 1����(mm) = 0.01��(cm)
		static double CmToMi( double Cm );
		// 1����(dm) = 100����(mm)
		static double DmToMm( const double & );
		// 1��(Mi) = 10����(dm)
		static double MiToDm( const double & );

		//*******�����λ��ת��*********
		//1��������(cm^3) = 10^3��������(mm^3)
		static double CubeCmToCubeMm(double CubeCm);
		//1��������(mm^3) = = 10^-3��������(cm^3)
		static double CubeMmToCubeCm(double CubeMm);
		//1�����ף�m^3�� = 10^9��������(mm^3)	
		static double CubeMiToCubeMm(double CubeMi);
		//1��������(mm^3) = 10^-9������(m^3)
		static double CubeMmToCubeMi(double CubeMm);

		//*******�ܶȵ�λת��***********
		// 1 g/cm^3=1000 kg/m^3
		static double GCubeCmToKgCubeMi(double GCC );

		//*******ʱ�䵥λת��***********
		// 1 us=10^-6s
		static double UsToS( double Us );
		// 1 ms=10^-3s
		static double MsToS( double Ms );
	};
}

