# Changelog

- Mar 19, 2025, version 0.79
  - Moved 'package' and 'src' to the top dir
  - Version grabbed from 'VERSION' in package/upgrade

- Feb 9, 2025,  version 0.78.4
  - several adjustments to get clang version 18.1.6 compatibility
  - restored !/bin/sh in all scripts

- Oct 14, 2024, version 0.78.3
  - all package/ scripts now run the bash shell
  - package/run script will recognize if we are in an lxc container to skip inittab configuration
  - package/run.rclocal will find both /etc/rc.local /etc/rc.d/rc.local
  - daemontools-0.78.2 directory renamed to daemontools

- Oct 10, 2024, version 0.78.2
  - added -ltr to conf-ld to link librt.so for systems with glibc prior to v. 2.17

- Oct 10, 2024, version 0.78.2
  - added -ltr to conf-ld to link librt.so for systems with glibc prior to v. 2.17

- Oct 4, 2024,  version 0.78.1
  - added missing package/compile script (tx Bai Borko)

- July 2024, version 0.78
  - multilog prints a readable datetime if used with "d" flag, it prints timestamps if used in the usual way with the "t" flag
  - fixed several compilation warnings and/or breaks on gcc-14.1

- Dec 9, 2023,  version 0.77 (Roberto Puzzanghera)
  - errno patch
  - multilog_filesize_limit patch by Sam Tang, which extends the file log size limit to 100MB (default is 16MB).
  - multilog-readable_datetime patch, which replaces the timestamp with a human readable datetime.


## pre-version 0.77 era (djb)

- 19990824
  - version: daemontools 0.60, alpha.

- 19990825
  - portability problem: some systems need sys/time.h, not just time.h, before sys/resource.h.
    - impact: couldn't compile.
    - fix: change time.h to sys/time.h in softlimit.c.
    - tnx Jos Backus and Chris Johnson.
  - portability problem: echo -n echoes literal -n under traditional System V.
    - tnx Tim Goodwin. impact: rts mismatch.
    - fix: echo | tr -d.
  - doc: removed note on man pages in conf-home. tnx Mate Wierdl.
  - ui: do pidchange() and announce() before opening supervise/ok in supervise.c.

- 19990826
  - version: daemontools 0.61, alpha.

- 20000304
  - internal: upgraded to latest installation system.
  - internal: switched from substdio to buffer.
  - internal: switched from execvp to pathexec.
  - internal: miscellaneous cleanups.
  - internal: sped up tai64n.
  - ui: svscan sleeps only 5 seconds.
  - ui: svscan chdirs to argv[1] if argv[1] is supplied.
  - ui: supervise does exec without waiting 1 second in child; but it waits 1 second before continuing in parent.
  - ui: svstat reports time since last supervise pid change.
  - ui: added envdir.
  - ui: incorporated setlock from serialmail.

- 20000305
  - internal: switched to new sig library.
  - internal: switched to iopause.
  - internal: more cleanups.
  - internal: sped up multilog.
  - ui: multilog sets current to mode 644 on restart.
  - version: daemontools 0.70, beta.

- 20000315
  - internal: new iopause.

- 20000316
  - internal: supervise does announce() only after changing state. Avoids disk writes when supervise is idle.

- 20010707
  - internal: added const at various places.
  - internal: miscellaneous cleanups.
  - portability problem: with recent versions of glibc, and on AIX, including sys/time.h doesn't define struct tm.
    - impact: couldn't compile.
    - fix: also include time.h.
    - tnx many people.
  - portability problem: although sleep() isn't interrupted by signals on my old BSD/OS development machine, it is
interrupted by signals on all new systems.
    - impact: if a supervised process dies quickly (but not too quickly), supervise's 1-second sleep is interrupted,
and the process is restarted immediately.
    - fix: new deepsleep().
  - internal: switched signal handling in supervise and multilog to blocked-by-default.
  - ui: multilog accepts ALRM to immediately rotate all cyclic logs for which current is nonempty.
    -tnx Peter Samuel and William E. Baxter.

- 20010708
  - portability problem: under System V, one process can hold many exclusive locks on one file. impact: no impact on normal
use, but some of the setlock regression tests fail. fix: change the tests to invoke an intermediate sh. tnx Mads Eilertsen.
  - internal: fitfiles() in multilog.
  - ui: added readproctitle.
  - ui: added svscanboot. tnx Matthias Andree.
  - ui: svscan checks for log directory instead of sticky bit. tnx many people.

- 20010709
  - ui: added pgrphack.

- 20010710
  - internal: upgraded to latest installation system.

- 20010711
  - version: daemontools 0.75, beta.

- 20010712
  - internal: ./package/compile creates ./compile/home.
  - internal: ./package/compile creates absolute ./compile/src symlink instead of using .., so ./compile can itself be
a symlink. tnx Paul Jarc.
  - portability problem: Solaris sh has a built-in test that doesn't support -e, even though the test program supports -e.
impact: package/{compile,run,upgrade} fail. tnx Mate Wierdl. fix: use -d, -h, -r.
  - version: daemontools 0.76, beta.
