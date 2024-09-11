Date: 9/11/2024

Entry:

Today, we found two files: `level06` with `suid` and `sgid` permissions, and `level06.php`.
We discovered that we have **PHP v5.3**, which has a vulnerability in the `preg_replace()`
function present in our code, allowing for **OS injection**. After creating a file in the
`/var/tmp/` directory, we tried to inject PHP code, which proved ineffective. Following this lead,
we continued to modify the contents of the file until we finally managed to execute the `getflag` command using:
```txt
[x ${`getflag`}]
```
