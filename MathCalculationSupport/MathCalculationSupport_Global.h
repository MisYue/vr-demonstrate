/************************************************
	���ƣ���ѧ����ģ�鵼��dll��̬�������ļ� MathcalculationSupport_global
	���ܣ�����dll
	�����ˣ�����
	����ʱ�䣺2015-1-26
	�汾��1.0
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