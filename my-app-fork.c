#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
  int a;
  printf(1, "This is my own app!\n");
  a = fork();
  a = fork();
  while(1) {
    a++;
  }
  exit();
}