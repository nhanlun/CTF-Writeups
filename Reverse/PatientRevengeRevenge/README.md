# PatientRevengeRevenge (250 pts)

"-_- I challenge you to use AutoClick :)". We see that we cannot click repeatedly, because of some kind of `Delay()` or `Sleep()` that freeze the program between each click. So we made the first propose: Patch those codes that delay the program to `NOP` commands then automate the clicks. However, we see that this approach is not fun. It is easy and boring for a 250-point-challenge. The past-solved Patients are enough. So we don't take problem settler's challenge, for a more interesting challenge of ourselves. Note that we cannot use a simple tool as `objdump` or `gdb` in this challenge but a more complex one such as `OllyDbg` as it has better functions and better support for Windows API.

As we read the disassembler, we see that:

1. There is a hardcoded sequence of 42 bytes, let's call this `seed`.
2. After each click, the program generates random 42 bytes, let's call them `key`. This `key` is XORed byte-by-byte with `seed` and assign to `seed`, i.e `seed = seed ^ key`. So we dive deeper into how the program generates `key` on each click. This results in the following.
3. The key is generated from a hardcoded `table` which is a sequence of 256 bytes. After each click, `table` is somehow modified.
4. After the click left equals 0, `seed` is checked whether it begins with `HCMUS-CTF{`. If it is, we honestly clicked 100000 times without using Cheat Engines or any kind of memory manipulating. We see that the flag is `initialized-seed ^ first key ^ second key ^ ... ^ 100000-th key`.

So we get to a solution: dump the initialized seed and `table`, then simulate the key-generating process 100000 times to get the flag.

![Simulate1](key.png)

where `genkey()` simulate the process of generating `key` from `table` as follows:

![genkey](genkey.png)

The flag is HCMUS-CTF{d0_y0u_kn0w_ARc_fourrrrrrrrrrrr}. No I don't.