#include <unistd.h>
#include "strerr.h"
#include "pathexec.h"

#define FATAL "pgrphack: fatal: "

int main(int argc,char * const *argv,char * const *envp)
{
  if (!argv[1]) strerr_die1x(100,"pgrphack: usage: pgrphack child");
  setsid(); /* shouldn't fail; if it does, too bad */
  pathexec_run(argv[1],argv + 1,envp);
  strerr_die4sys(111,"pgrphack: fatal: ","unable to run ",argv[1],": ");
}
