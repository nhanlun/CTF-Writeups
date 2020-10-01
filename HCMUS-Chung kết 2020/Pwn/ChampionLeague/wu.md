tldr: A basic "gets + static function address" buffer overflow with some simple check.

First, we use gdb to observe that the address of each function is not changed between two executions. For example, <kick_off> is always at 0x08048570, <main> is always at 0x0804866f.

Second, <pick_player> call <gets> to input a string, which is prone to buffer overflow attacks. We try to replace saved EIP (the return address) with our target, <kick_off>, which will call system("bin/cat flag.txt").

<kick_off> will do some simple check, we just have to adjust our string to pass the check. The buffer overflow string will contains 0x40 random bytes, 8 more random bytes, the return address (our target <kick_off>), 4 random bytes, int 0x933, then int 0x78, both int in little endian for passing the check in <kick_off>.

Flag: HCMUS-CTF{You_also_can_control_parameters}
