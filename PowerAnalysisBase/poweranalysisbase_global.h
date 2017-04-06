#ifndef POWERANALYSISBASE_GLOBAL_H
#define POWERANALYSISBASE_GLOBAL_H

#ifdef POWERANALYSISBASE_LIB
# define POWERANALYSISBASE_EXPORT __declspec(dllexport)
#else
# define POWERANALYSISBASE_EXPORT __declspec(dllimport)
#pragma comment(lib, "PowerAnalysisBase.lib")
#endif

#endif // POWERANALYSISBASE_GLOBAL_H
