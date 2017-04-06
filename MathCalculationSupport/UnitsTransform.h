/*
名称： 单位转换  UnitsTransform
功能：支撑进行不同单位值之间的转换计算
创建人：徐豫新
创建时间： 2015年4月5
版本：1.0
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

		//******压力单位制转换**********
		// 1巴（bar）=10^5帕（Pa） 
		static double BarToPa(double Bar);
		// 1帕(Pa) = 10^-5巴(bar)
		static double PaToBar(double Pa);
		// 1Psi = 0.00689Mpa
		static double PsiToMPa(double Psi);
		// 1MPa = 145.03725(Psi = 磅力/英寸2)
		static double MpaToPsi(double Mpa);

		//******质量单位制转换**********
		// 1磅(lb)=0.4536千克(kg)
		static double BlToKg(double Bl);
		// 1千克(Kg)=2.2046磅(Bl)
		static double KgToBl(double Kg);
		// 克(g)=10^-3千克(kg)
		static double GToKg( double G );
		// 1千克(kg) = 10^3克(g)
		static double KgToG( double Kg );

		//*******长度单位制转换*********
		// 1米(M)=39.37英寸(in)
		static double MiToIn(double Mi);
		// 1英寸(in)=0.0254米(M)
		static double InToMi(double In);
		// 1米(M)=3.2808英寸(in)
		static double MiToFt(double Mi);
		// 1英寸(ft)=0.3048米(M)
		static double FtToMi(double Ft);
		// 1米(m) = 1000毫米(mm)
		static double MiToMm( double Mi );
		// 1毫米(mm) = 0.001米(m)
		static double MmToMi( double Mm );
		// 1毫米(mm) = 0.1厘米(cm)
		static double MmToCm( double Mm );
		// 1毫米(mm) = 0.01分米(dm)
		static double MmToDm( double Mm );
		// 1厘米(cm) = 10毫米(mm)
		static double CmToMm( double Cm );
		// 1厘米(mm) = 0.1分米(dm)
		static double CmToDm( double Cm );
		// 1厘米(mm) = 0.01米(cm)
		static double CmToMi( double Cm );
		// 1分米(dm) = 100毫米(mm)
		static double DmToMm( const double & );
		// 1米(Mi) = 10分米(dm)
		static double MiToDm( const double & );

		//*******体积单位制转换*********
		//1立方厘米(cm^3) = 10^3立方毫米(mm^3)
		static double CubeCmToCubeMm(double CubeCm);
		//1立方毫米(mm^3) = = 10^-3立方厘米(cm^3)
		static double CubeMmToCubeCm(double CubeMm);
		//1立方米（m^3） = 10^9立方毫米(mm^3)	
		static double CubeMiToCubeMm(double CubeMi);
		//1立方毫米(mm^3) = 10^-9立方米(m^3)
		static double CubeMmToCubeMi(double CubeMm);

		//*******密度单位转换***********
		// 1 g/cm^3=1000 kg/m^3
		static double GCubeCmToKgCubeMi(double GCC );

		//*******时间单位转换***********
		// 1 us=10^-6s
		static double UsToS( double Us );
		// 1 ms=10^-3s
		static double MsToS( double Ms );
	};
}

