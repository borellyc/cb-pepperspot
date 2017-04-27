// Copyright (c) 2008, Thibault VANCON and Sebastien VINCENT

//!
//!  \file compat.h
//!  \brief Compatibility functions.
//!

#ifndef _COMPAT_H
#define _COMPAT_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__) || \
    defined(__OpenBSD__)
typedef unsigned long u_long;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned char u_char;
#endif

#if (!defined(HAVE_CLEARENV) && !defined(_XOPEN_SOURCE)) || defined(__APPLE__)

// code from miredo
#if defined(__APPLE__)
#include <crt_externs.h>
#define environ \
  (*_NSGetEnviron()) //!< Extern variable environ replacement for Mac OS X
#else
extern char *
    *environ; //!< environ variable which contains environment variable
#endif

//!
//!  \brief clearenv replacement function (non POSIX).
//!
//!  Clear the environnement variables.
//!  \return 0
//!
int clearenv(void);

#endif

#if !defined(HAVE_DAEMON) && !defined(_XOPEN_SOURCE)

//!
//!  \brief daemon replacement function (non POSIX).
//!  \param nochdir if 0, the child change to "/" directory
//!  \param noclose if 0, the child redirect stdin, stdout and stderr to
//!  /dev/null
//!  \return O if OK, -1 otherwise (errno is set).
//!
int daemon(int nochdir, int noclose);

#endif

#ifdef __cplusplus
}
#endif

#endif // !_COMPAT_H
