# Arguments (128pts)
Decompile the program, we get the important function show_me

![](disass.png)

It first read the input, check if it contains '/' or not, then get the first 3 character and concatenate it into ls command then execute it.

First we think that we could change the control flow of the program to execute the system("/bin/sh") or try to override the GOT table to execute system instead of strchr. But this program use stack canary to protect it from buffer overflow attack, such strategy does not work.

The final solution is very simple. It is bash injection, the payload is ;;sh to spawn the shell and get the flag. This payload fit perfectly into the size of the command. 

We did not solve it during the contest, so there is no flag.