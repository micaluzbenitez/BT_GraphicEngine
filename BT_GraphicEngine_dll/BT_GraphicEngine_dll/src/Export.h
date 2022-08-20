#pragma once

#ifdef EXPORT
#define DllExport   __declspec( dllexport )
#else
#define DllImport   __declspec( dllimport )
#endif