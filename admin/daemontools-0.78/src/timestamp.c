#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "taia.h"
#include "timestamp.h"

static char hex[16] = "0123456789abcdef";
struct tm *tm_info;
struct timespec tv;
char nsec_buf[11];

void timestamp(char s[TIMESTAMP])
{
  struct taia now;
  char nowpack[TAIA_PACK];
  int i;

  taia_now(&now);
  taia_pack(nowpack,&now);

  s[0] = '@';
  for (i = 0;i < 12;++i) {
    s[i * 2 + 1] = hex[(nowpack[i] >> 4) & 15];
    s[i * 2 + 2] = hex[nowpack[i] & 15];
  }
}

void readable_datetime(char s[DT])
{
  clock_gettime(CLOCK_REALTIME, &tv);
  tm_info = localtime(&tv.tv_sec);
  strftime(s, DT, "%F %T", tm_info);
  sprintf(nsec_buf, ".%09ld", tv.tv_nsec);
  strcat(s, nsec_buf);
}
