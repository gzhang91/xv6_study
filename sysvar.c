#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

char sh_var[32];

int
sys_write_sh_var(void)
{
  char *p;
  int n, i;

  if (argint(1, &n) < 0 || argptr(0, &p, n) < 0) {
    return -1;
  }

  for (i = 0; i < 32; i++) {
    if (p[i] == '\0') {
      break;
    }

    sh_var[i] = p[i];
  }
  return 0;
}

int
sys_read_sh_var(void)
{
  int n, i;
  char *p;

  if (argint(1, &n) < 0 || argptr(0, &p, n) < 0) {
    return -1;
  }

  for (i = 0; i < 32; i++) {
    if (sh_var[i] == '\0' || n <= i) {
      break;
    }

    p[i] = sh_var[i];
  }

  return 0;
}