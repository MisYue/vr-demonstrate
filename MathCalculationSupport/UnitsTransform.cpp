//====*  ��λ����  *========
#include "UnitsTransform.h"


namespace BIT
{
	UnitsTransform::UnitsTransform(void)
	{
	}


	UnitsTransform::~UnitsTransform(void)
	{
	}

	//******ѹ����λ��ת��**********
	//1�ͣ�bar��=10^5����Pa�� 
	double UnitsTransform::BarToPa( double Bar )
	{//Bar: �������
		double temp_Pa;
		temp_Pa = Bar * 10e5;
		return temp_Pa;
	}

	// 1��(Pa) = 10^-5��(bar)
	double UnitsTransform::PaToBar( double Pa )
	{//Pa: ������
		double temp_Bar;
		temp_Bar = Pa * 10e-5;
		return temp_Bar;

	}
	
	// 1Psi = 0.00689Mpa
	double UnitsTransform::PsiToMPa( double Psi )
	{// Psi:����Psi��Ŀ
		double temp_MPa;
		temp_MPa = Psi * 0.00689;
		return temp_MPa;
	}

// 1MPa = 145.03725(Psi = ����/Ӣ��2)
	double UnitsTransform::MpaToPsi( double Mpa )
	{// Mpa:����MPa��Ŀ
		double temp_Psi;
		temp_Psi = Mpa * 145.03725;
		return temp_Psi;
	}

	//******������λ��ת��**********
	// 1��(lb)=0.4536ǧ��(kg)
	double UnitsTransform::BlToKg( double Bl )
	{// Bl:�������
		double temp_Kg;
		temp_Kg = Bl * 0.4536;
		return temp_Kg;
	}

	// 1ǧ��(Kg)=2.2046��(Bl)
	double UnitsTransform::KgToBl( double Kg )
	{// Kg:����ǧ����

		double temp_Bl;
		temp_Bl = Kg * 2.2046;
		return temp_Bl;

	}

	// ��(g)=10^-3ǧ��(kg)
	double UnitsTransform::GToKg( double G )
	{
		double temp_Kg;
		temp_Kg = G / 1000;
		return temp_Kg;
	}

	// 1ǧ��(kg) = 10^3��(g)
	double UnitsTransform::KgToG( double Kg )
	{
		double temp_G;
		temp_G = Kg * 1000;
		return temp_G;
	}

	//*******���ȵ�λ��ת��*********
	// 1��(M)=39.37Ӣ��(in)
	double UnitsTransform::MiToIn( double Mi )
	{// Mi:���������
		double temp_In;
		temp_In = Mi * 39.37;
		return temp_In;
	}

	// 1Ӣ��(in)=0.0254��(M)
	double UnitsTransform::InToMi( double In )
	{//In:�����Ӣ����
		double temp_Mi;
		temp_Mi = In * 0.0254;
		return temp_Mi;
	}

	// 1��(M)=3.2808Ӣ��(in)
	double UnitsTransform::MiToFt( double Mi )
	{// Mi:���������
		double temp_Ft;
		temp_Ft = Mi * 3.2808;
		return temp_Ft;

	}

	// 1Ӣ��(ft)=0.3048��(M)
	double UnitsTransform::FtToMi( double Ft )
	{// Ft:�����Ӣ����
		double temp_Mi;
		temp_Mi = Ft * 0.3048;
		return temp_Mi;
	}

	// 1��(m) = 1000mm(����)
	double UnitsTransform::MiToMm( double Mi )
	{// Mi�����������
		double temp_Mm;
		temp_Mm = Mi * 1000;
		return temp_Mm;
	}

	// 1����(mm) = 10^-3��(m)
	double UnitsTransform::MmToMi( double Mm )
	{// Mi������ĺ�����
		double temp_Mi;
		temp_Mi = Mm / 1000.0;
		return temp_Mi;
	}

	// 1����(mm) = 10����(cm)
	double UnitsTransform::MmToCm( double Mm )
	{
		double temp_Cm;
		temp_Cm = Mm / 10.0;
		return temp_Cm;
	}

	// 1����(mm) = 0.01����(dm)
	double UnitsTransform::MmToDm( double Mm )
	{
		double temp_Dm;
		temp_Dm = Mm / 100.0;
		return temp_Dm;
	}

	// 1����(mm) = 10����(cm)
	double UnitsTransform::CmToMm( double Cm )
	{
		double temp_Mm;
		temp_Mm = Cm * 10;
		return temp_Mm;
	}

	// 1����(mm) = 0.1����(dm)
	double UnitsTransform::CmToDm( double Cm )
	{
		double temp_Mm;
		temp_Mm = Cm * 0.1;
		return temp_Mm;
	}

	// 1����(mm) = 0.01��(cm)
	double UnitsTransform::CmToMi( double Cm )
	{
		double temp_Mi;
		temp_Mi = Cm * 0.01;
		return temp_Mi;
	}

	// 1����(dm) = 100����(mm)
	double UnitsTransform::DmToMm( const double &Dm )
	{
		double temp_Mm;
		temp_Mm = Dm * 100;
		return temp_Mm;
	}
	// 1��(Mi) = 10����(dm)
	double UnitsTransform::MiToDm( const double &Mi )
	{
		double temp_Dm;
		temp_Dm = Mi * 10;
		return temp_Dm;
	}

	// 1��������(cm^3) = 10^3��������(mm^3)
	// 1cm^3 = 10^3mm^3
	double UnitsTransform::CubeCmToCubeMm( double CubeCm )
	{//CubeCm:��������cm
		double temp_CubeMm;
		temp_CubeMm = CubeCm * 1000;
		return temp_CubeMm;
	}

	//1��������(mm^3) = = 10^-3��������(cm^3)
	//// 1mm^3 = 10^-3cm^3
	double UnitsTransform::CubeMmToCubeCm( double CubeMm )
	{//CubeMm:��������mm
		double temp_CubeCm;
		temp_CubeCm = CubeMm / 1000;
		return temp_CubeCm;
	}

	//1�����ף�m^3�� = 10^9��������(mm^3)
	double UnitsTransform::CubeMiToCubeMm( double CubeMi )
	{//CubeMi������������,
		double temp_CubeMm;
		temp_CubeMm = CubeMi * 1e9;
		return temp_CubeMm;
	}

	//1��������(mm^3) = 10^-9������(m^3)
	double UnitsTransform::CubeMmToCubeMi( double CubeMm )
	{//CubeMm��������������
		double temp_CubeMi;
		temp_CubeMi = CubeMm * 1e-9;
		return temp_CubeMi;
	}

	// 1 g/cm^3=1000 kg/m^3
	double UnitsTransform::GCubeCmToKgCubeMi( double GCC )
	{//GCC������g/cm^3
		double temp_KgCubeMi;
		temp_KgCubeMi = GCC * 1000;
		return temp_KgCubeMi;
	}

	// 1 us=10^-6s
	double UnitsTransform::UsToS( double Us )
	{
		double temp_S;
		temp_S = Us * 0.000001;
		return temp_S;
	}

	// 1 ms=10^-3s
	double UnitsTransform::MsToS( double Ms )
	{
		double temp_S;
		temp_S = Ms * 0.001;
		return temp_S;
	}
}
