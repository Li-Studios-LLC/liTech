#ifndef LITECHBASE_TYPEDEFS_H
#define LITECHBASE_TYPEDEFS_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Convert definitions to proper ones
#ifdef _WIN32
#define LITECH_WIN32
#endif

#ifdef _MSC_VER
#define LITECH_EXPORT __declspec(dllexport)
#define LITECH_IMPORT __declspec(dllimport)
#else
#define LITECH_EXPORT
#define LITECH_IMPORT
#endif

class liPlaceholder { };

#endif