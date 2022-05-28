#include <stdio.h>

int func4(int param_1, int zero, int fourteen)
{
  int iVar1;
  int iVar2;

  iVar2 = (fourteen - (int)zero) / 2 + (int)zero;
  if (param_1 < iVar2) {
    iVar1 = func4(param_1,zero,iVar2 - 1);
    iVar1 = iVar1 * 2;
  }
  else {
    iVar1 = 0;
    if (iVar2 < param_1) {
      iVar2 = func4(param_1,iVar2 + 1, fourteen);
      iVar1 = iVar2 * 2 + 1;
    }
  }
  printf("ivar1: %d\n", iVar1);
  return iVar1;
}

int main() {
    int r = func4(1, 0, 14);
    printf("%d", r);
    return 0;
}
