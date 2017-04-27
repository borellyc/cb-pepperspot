// Copyright (c) 2008, Thibault VANCON and Sebastien VINCENT

//!
//!  \file compat.c
//!  \brief Compatibility functions.
//!

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "compat.h"

#if !defined(HAVE_CLEARENV) || !defined(_XOPEN_SOURCE)

// clearenv replacement function (non POSIX)
int clearenv(void) {
  environ = NULL;
  return 0;
}

#endif

#if !defined(HAVE_DAEMON) || defined(_POSIX_C_SOURCE)

// daemon replacement function (non POSIX)
int daemon(int nochdir, int noclose) {
  pid_t pid = -1;
  pid = fork();

  if (pid == -1) // error
  {
    return -1;
  } else if (pid == 0) // child
  {
    if (setsid() == -1) { return -1; }

    if (!nochdir) { chdir("/"); }

    if (!noclose) {
      // open /dev/null
      int fd = -1;
      if ((fd = open("/dev/null", O_RDWR, 0)) != -1) {
        // redirect stdin, stdout and stderr to /dev/null
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);

        if (fd > -1) { close(fd); }
      }
    }

    return 0;
  } else // father
  {
    _exit(EXIT_SUCCESS);
  }
}

#endif
