#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
  char val[100] = "XV6_GZHANGXV6_GZHANGXV6_GZHANGXV6_GZHANGXV6_GZHANGXV6_GZHANGXV6_GZHANGXV6_GZHANGXV6_GZHANG";
  char dst_val[100] = {0};
  int ret;

  write_sh_var(val, strlen(val));
  ret = read_sh_var(dst_val, sizeof(dst_val));
  printf(1, "get write val result[%d], content is: %s\n", ret, dst_val);
  exit();
}