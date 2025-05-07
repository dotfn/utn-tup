// platform.h
#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#else
#define CLEAR "clear"
#define PAUSE "read -p '\nPresione Enter para continuar...' var"
#endif

#endif // PLATFORM_H
