# TakeMyShell (178pts)

Reading the source code of the program, we know that it allocate memory of 60 bytes then let user input into that section and execute it.

So the goal is to fill it with byte code of system("/bin/sh") to spawn a shell and get the code

The shell code is from [here](http://www.kernel-panic.it/security/shellcode/shellcode5.html). Send it to spawn a shell and retrieve the flag.

Sorry we lost the flag