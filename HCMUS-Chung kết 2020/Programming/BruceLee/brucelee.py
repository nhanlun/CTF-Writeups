from pwn import *
from string import printable


flag = 'HCMUS-CTF{'
for i in range(len(flag), 41):
    for j in printable:
        c = remote('159.65.13.76', 61001)
        inp = str(flag) + j
        x = c.recvline()
        c.sendline(inp.encode())
        x = c.recvline()
        if x[i] == 0x31:
            flag = inp 
            print(x)
            print(flag)
            break 

print(flag)