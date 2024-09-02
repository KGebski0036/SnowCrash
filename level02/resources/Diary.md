Penetration Testing Diary

Date: 9/2/2024
Entry:

Today’s CTF challenge took us into the realm of network analysis. We used `scp` to transfer the `flag02.pcap` file to our local machines and opened it with `Wireshark`.

Our task involved following the `TCP stream` to investigate login attempts. During the inspection, we managed to capture what looked like a password.

To decode it, we simulated the output of the hex values and took special care with the `delete signs` that were present. After some careful analysis, we managed to reconstruct the correct password.

A rewarding challenge that sharpened our skills in network traffic analysis and hex decoding!