void main(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  int __fd;
  size_t __n;
  int in_GS_OFFSET;
  undefined local_414 [1024];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == 1) {
    printf("%s [file to read]\n",*param_2);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar1 = strstr((char *)param_2[1],"token");
  if (pcVar1 != (char *)0x0) {
    printf("You may not access \'%s\'\n",param_2[1]);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __fd = open((char *)param_2[1],0);
  if (__fd == -1) {
    err(1,"Unable to open %s",param_2[1]);
  }
  __n = read(__fd,local_414,0x400);
  if (__n == 0xffffffff) {
    err(1,"Unable to read fd %d",__fd);
  }
  write(1,local_414,__n);
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}