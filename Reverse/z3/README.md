# z3 (150 points)

Let `inp` be our input string. By reading disassembler's code, we see that if `check(inp)` returns true then we did input the flag, false otherwise. However, the number of assembly code in `check` function is over 9000! So we need a roundabout approach.

We observe that:

1. At the function prologue, the input string is moved to `-0x8(%rbp)`
2. Every accesses to `inp` since the point 1 is solely through `-0x8(%rbp)`.
3. There is no access to global variable. This implies that `check` does not use any external data beside `inp` (stored at `-0x8(%rbp)`).
4. There is no write to `inp`, i.e, the `inp` is not edited during `check`.
5. It seems that the function just performs simple arithmetics on some bytes of `inp`. This implies that every value in the registers, whenever they don't store the address, they must store a linear combination of (inp[0], inp[1], inp[2], ..., inp[n-1], _free coefficient_). 

Therefore we propose a solution:

1. We can simulate the value in the register by seeing each register as a vector in n+1 dimensions of inp[0], inp[1], inp[2] ..., inp[n-1], _free coefficient_.
2. We can replay the `check` function by simulating instructions `add`, `sub`, `lea`, `shl`. For an example, let `eax` be a vector: 2\*inp[0] + 3\*inp[1] and `ecx` be a vector 4\*inp[0] + 6\*inp[1], then the instruction

   `addl %eax, %ecx ;AT&T syntax`

   will assign 6\*inp[0] + 9\*inp[1] to `ecx`. We do not store just the value but the whole vector (6, 9, 0, 0, ... 0) to vector `ecx`.

   For each paragraph of `cmp $value, %register` then `jne checkFailed`, we get a requirement of a linear combination of values of `inp` that it must equal some value, in the form of an equation.

   Results, we get 36 equations about 36 unknowns of inp[0], inp[1], ..., inp[35].

3. Use some software such as Maple to do a Gauss-Jordan elimination, we get the supposed values of inp[0], inp[1], ... inp[35], which is the flag.

The flag is HCMUS-CTF{H4v3_y0u_ev3r_he4rd_0f_z3}. No, I have not.
 
 