Date: 9/21/2024

Entry:
In this challenge, we had access to the code of the server operating in `lua`. This line `prog = io.popen("echo "..pass.." | sha1sum", "r")` attracted out attention, revieling possible code injection. After connecting with the server, it asked for a password. We injected this code in the password field `$(getflag > /tmp/flag)` and managed to successfully get the flag.