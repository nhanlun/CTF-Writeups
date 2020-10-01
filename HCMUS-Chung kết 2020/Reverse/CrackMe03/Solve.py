flag = [0x5b200 ,   0x1189      , 
    0x00001861  ,   0x00fd02ff  , 
    0x000a0c47  ,   0x00adcea1  , 
    0x000014d1  ,   0x0c1e12c0  ,
	0x00073db8	,	0x50dba58b	,
	0x00002e69	,	0x1d9c7600	,
	0x0020c181	,	0x7f0fe057	,
	0x00002e69	,	0x10483f03b ,
	0x00000a90	,	0x00355bc4	,
	0x00003931	,	0x0031b6a9	,
	0x00003664	,	0x1f7cb52cd	,
	0x00231840	,	0x0048d951	,
	0x00003c10	,	0x00271000	,
	0x00003931	,	0x49532bec0	,
	0x0020c181	,	0x009b4664	,
	0x00003d09	,	0x008cd484	,
	0x000024c1	,	0x09afa59359,
	0x0020c181	,	0x152ff03a9	,
	0x00006541	] 

assert len(flag) == 0x25

for i in range(len(flag)):
    x = pow(flag[i], 0.5)
    if x - int(x) < 0.000001:
        flag[i] = int(x)
    else:
        flag[i] = int(pow(flag[i], 1/3)) + 1
        
for i in range(len(flag)):
    if i % 2 == 1:
        flag[i] = flag[i] // i
    else:
        flag[i] = flag[i] - i

print(flag)
flag = [chr(x) for x in flag if x > 0]
print("".join(flag))
