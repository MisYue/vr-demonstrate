/************************************************
	名称：数学计算模块导出dll动态库配置文件 MathcalculationSupport_global
	功能：导出dll
	创建人：尹鹏
	创建时间：2015-1-26
	版本：1.0
*************************************************/

#ifndef MATHCALCULATIONSUPPORT_GLOBAL_H
#define MATHCALCULATIONSUPPORT_GLOBAL_H

#ifdef MATHCALCULATIONSUPPORT_LIB
#define MATHCALCULATIONSUPPORT_API __declspec(dllexport)
#else
#define MATHCALCULATIONSUPPORT_API __declspec(dllimport)
#pragma comment(lib, "MathCalculationSupport.lib")
#endif

#endif // MATHCALCULATIONSUPPORT_GLOBAL_H