#ifndef ENTITYDATA_GLOBAL_H
#define ENTITYDATA_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef ENTITYDATA_LIB
# define ENTITYDATA_EXPORT Q_DECL_EXPORT
#else
# define ENTITYDATA_EXPORT Q_DECL_IMPORT
#pragma comment(lib, "entitydata.lib")
#endif

#endif // ENTITYDATA_GLOBAL_H
