//====*  单位换算  *========
#include "UnitsTransform.h"


namespace BIT
{
	UnitsTransform::UnitsTransform(void)
	{
	}


	UnitsTransform::~UnitsTransform(void)
	{
	}

	//******压力单位制转换**********
	//1巴（bar）=10^5帕（Pa） 
	double UnitsTransform::BarToPa( double Bar )
	{//Bar: 输入巴数
		double temp_Pa;
		temp_Pa = Bar * 10e5;
		return temp_Pa;
	}

	// 1帕(Pa) = 10^-5巴(bar)
	double UnitsTransform::PaToBar( double Pa )
	{//Pa: 输入帕
		double temp_Bar;
		temp_Bar = Pa * 10e-5;
		return temp_Bar;

	}
	
	// 1Psi = 0.00689Mpa
	double UnitsTransform::PsiToMPa( double Psi )
	{// Psi:输入Psi数目
		double temp_MPa;
		temp_MPa = Psi * 0.00689;
		return temp_MPa;
	}

// 1MPa = 145.03725(Psi = 磅力/英寸2)
	double UnitsTransform::MpaToPsi( double Mpa )
	{// Mpa:输入MPa数目
		double temp_Psi;
		temp_Psi = Mpa * 145.03725;
		return temp_Psi;
	}

	//******质量单位制转换**********
	// 1磅(lb)=0.4536千克(kg)
	double UnitsTransform::BlToKg( double Bl )
	{// Bl:输入磅数
		double temp_Kg;
		temp_Kg = Bl * 0.4536;
		return temp_Kg;
	}

	// 1千克(Kg)=2.2046磅(Bl)
	double UnitsTransform::KgToBl( double Kg )
	{// Kg:输入千克数

		double temp_Bl;
		temp_Bl = Kg * 2.2046;
		return temp_Bl;

	}

	// 克(g)=10^-3千克(kg)
	double UnitsTransform::GToKg( double G )
	{
		double temp_Kg;
		temp_Kg = G / 1000;
		return temp_Kg;
	}

	// 1千克(kg) = 10^3克(g)
	double UnitsTransform::KgToG( double Kg )
	{
		double temp_G;
		temp_G = Kg * 1000;
		return temp_G;
	}

	//*******长度单位制转换*********
	// 1米(M)=39.37英寸(in)
	double UnitsTransform::MiToIn( double Mi )
	{// Mi:输入的米数
		double temp_In;
		temp_In = Mi * 39.37;
		return temp_In;
	}

	// 1英寸(in)=0.0254米(M)
	double UnitsTransform::InToMi( double In )
	{//In:输入的英寸数
		double temp_Mi;
		temp_Mi = In * 0.0254;
		return temp_Mi;
	}

	// 1米(M)=3.2808英寸(in)
	double UnitsTransform::MiToFt( double Mi )
	{// Mi:输入的米数
		double temp_Ft;
		temp_Ft = Mi * 3.2808;
		return temp_Ft;

	}

	// 1英寸(ft)=0.3048米(M)
	double UnitsTransform::FtToMi( double Ft )
	{// Ft:输入的英尺数
		double temp_Mi;
		temp_Mi = Ft * 0.3048;
		return temp_Mi;
	}

	// 1米(m) = 1000mm(毫米)
	double UnitsTransform::MiToMm( double Mi )
	{// Mi：输入的米数
		double temp_Mm;
		temp_Mm = Mi * 1000;
		return temp_Mm;
	}

	// 1毫米(mm) = 10^-3米(m)
	double UnitsTransform::MmToMi( double Mm )
	{// Mi：输入的毫米数
		double temp_Mi;
		temp_Mi = Mm / 1000.0;
		return temp_Mi;
	}

	// 1毫米(mm) = 10厘米(cm)
	double UnitsTransform::MmToCm( double Mm )
	{
		double temp_Cm;
		temp_Cm = Mm / 10.0;
		return temp_Cm;
	}

	// 1毫米(mm) = 0.01分米(dm)
	double UnitsTransform::MmToDm( double Mm )
	{
		double temp_Dm;
		temp_Dm = Mm / 100.0;
		return temp_Dm;
	}

	// 1厘米(mm) = 10毫米(cm)
	double UnitsTransform::CmToMm( double Cm )
	{
		double temp_Mm;
		temp_Mm = Cm * 10;
		return temp_Mm;
	}

	// 1厘米(mm) = 0.1分米(dm)
	double UnitsTransform::CmToDm( double Cm )
	{
		double temp_Mm;
		temp_Mm = Cm * 0.1;
		return temp_Mm;
	}

	// 1厘米(mm) = 0.01米(cm)
	double UnitsTransform::CmToMi( double Cm )
	{
		double temp_Mi;
		temp_Mi = Cm * 0.01;
		return temp_Mi;
	}

	// 1分米(dm) = 100毫米(mm)
	double UnitsTransform::DmToMm( const double &Dm )
	{
		double temp_Mm;
		temp_Mm = Dm * 100;
		return temp_Mm;
	}
	// 1米(Mi) = 10分米(dm)
	double UnitsTransform::MiToDm( const double &Mi )
	{
		double temp_Dm;
		temp_Dm = Mi * 10;
		return temp_Dm;
	}

	// 1立方厘米(cm^3) = 10^3立方毫米(mm^3)
	// 1cm^3 = 10^3mm^3
	double UnitsTransform::CubeCmToCubeMm( double CubeCm )
	{//CubeCm:输入立方cm
		double temp_CubeMm;
		temp_CubeMm = CubeCm * 1000;
		return temp_CubeMm;
	}

	//1立方毫米(mm^3) = = 10^-3立方厘米(cm^3)
	//// 1mm^3 = 10^-3cm^3
	double UnitsTransform::CubeMmToCubeCm( double CubeMm )
	{//CubeMm:输入立方mm
		double temp_CubeCm;
		temp_CubeCm = CubeMm / 1000;
		return temp_CubeCm;
	}

	//1立方米（m^3） = 10^9立方毫米(mm^3)
	double UnitsTransform::CubeMiToCubeMm( double CubeMi )
	{//CubeMi：输入立方米,
		double temp_CubeMm;
		temp_CubeMm = CubeMi * 1e9;
		return temp_CubeMm;
	}

	//1立方毫米(mm^3) = 10^-9立方米(m^3)
	double UnitsTransform::CubeMmToCubeMi( double CubeMm )
	{//CubeMm：输入立方毫米
		double temp_CubeMi;
		temp_CubeMi = CubeMm * 1e-9;
		return temp_CubeMi;
	}

	// 1 g/cm^3=1000 kg/m^3
	double UnitsTransform::GCubeCmToKgCubeMi( double GCC )
	{//GCC：输入g/cm^3
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
