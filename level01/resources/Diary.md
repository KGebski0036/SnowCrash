Penetration Testing Diary

Date: 9/2/2024

Entry:

Today, during our penetration test, we explored the `/etc/passwd` file and came across a hashed password for the user `flag01`. This discovery provided us with an opportunity to test our hash-cracking skills.

We decided to use `John the Ripper` for this task. We extracted the hash and saved it into a file named `message.txt`. By running the command `john message.txt`, John the Ripper began cracking the hash.

Our efforts paid off, and we successfully recovered the plaintext password. This exercise underscored the importance of securely hashing passwords and maintaining robust password management practices.

Lessons Learned:

Always use strong hashing algorithms and include salting to protect passwords.
John the Ripper is an effective tool for password recovery and hash analysis.
