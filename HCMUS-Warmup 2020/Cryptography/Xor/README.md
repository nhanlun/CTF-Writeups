# Xor
The encoded message is encoded using xor. The length of the encoded is odd, so, we padded 0 at the beginning of the string to make it even. Then, we picked the first 9 characters, which is 18 hex in the string, and xor it with the string HCMUS-CTF. We got the key FITFITFIT, so we assumed the key is FIT and xor the string with it.

The flag is HCMUS-CTF{XoR_1s_a_KinD_oF_Crypto}