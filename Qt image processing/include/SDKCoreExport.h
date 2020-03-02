#ifndef C4_LUMISUITE_EXPORT_H
#define C4_LUMISUITE_EXPORT_H

// Do not include Qt stuff here!

#include "stdbool.h"

//#define USE_QT_GLOBALS 1
#ifdef USE_QT_GLOBALS
    //#include <QtGlobal>
    #include <qsystemdetection.h>
#else

// OS-X?
#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#  define Q_OS_DARWIN
#  define Q_OS_BSD4
#  define QT_VISIBILITY_AVAILABLE
#  ifdef __LP64__
#    define Q_OS_DARWIN64
#  else
#    define Q_OS_DARWIN32
#  endif
#  if defined(Q_OS_DARWIN)
#    define Q_OS_MAC
#    if defined(Q_OS_DARWIN64)
#       define Q_OS_MAC64
#    elif defined(Q_OS_DARWIN32)
#       define Q_OS_MAC32
#    endif
#    if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#       define Q_OS_OSX
#       define Q_OS_MACX // compatibility synonym
#    endif
#  endif
#endif

// Windows?
#if !defined(SAG_COM) && (!defined(WINAPI_FAMILY) || WINAPI_FAMILY==WINAPI_FAMILY_DESKTOP_APP) && (defined(WIN64) || defined(_WIN64) || defined(__WIN64__))
#  define Q_OS_WIN32
#  define Q_OS_WIN64
#elif !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
#  define Q_OS_WIN32
#endif
#if defined(Q_OS_WIN32) || defined(Q_OS_WIN64)
#  define Q_OS_WIN
#endif

#endif


// Define import/export and visibility
#  ifdef Q_OS_WIN
#    define Q_DECL_EXPORT     __declspec(dllexport)
#    define Q_DECL_IMPORT     __declspec(dllimport)
#  elif defined(QT_VISIBILITY_AVAILABLE)
#    define Q_DECL_EXPORT     __attribute__((visibility("default")))
#    define Q_DECL_IMPORT     __attribute__((visibility("default")))
#    define Q_DECL_HIDDEN     __attribute__((visibility("hidden")))
#  endif

#if !defined(Q_DECL_EXPORT) || !defined(Q_DECL_IMPORT)
#   error Platform not supported!
#endif


#ifdef USE_LUMISUITE_EXTERNAL_INTERFACES
#   define USE_C4LUMISUITE
#endif


// Define import or export
#if defined(MAKE_C4LUMISUITE)
#  define C4LUMISUITE_EXPORT Q_DECL_EXPORT
#  define C4LUMISUITE_IMPORT extern
#else
#  define C4LUMISUITE_EXPORT Q_DECL_IMPORT
#  define C4LUMISUITE_IMPORT Q_DECL_IMPORT
#endif

#endif // endif C4_LUMISUITE_EXPORT_H
