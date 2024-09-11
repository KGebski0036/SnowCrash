Date: 9/11/2024

Entry:

Today, after logging into the machine, we received the message *You got new mail*.

At first, we checked if we had access to the `mail` command, but this was a dead end.

Next, we checked the `/var/mail` directory where we found a file named `level05` containing
**cron** commands to execute the script `/usr/sbin/openarenaserver`, which included the following code:

```bash
for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
After checking if we had permission to create a file in that location, we created a file named `aaa.sh`
containing the following code, which allowed us to obtain the flag:
```bash
getflag | wall
```
