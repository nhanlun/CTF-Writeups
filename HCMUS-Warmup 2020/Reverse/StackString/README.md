# StackString (50 points)

First, use dump all the string using `strings stackstring` but could not find any string. So we debug by `gdb stackstring`, breaking at <main>. We see that they assign the flag byte by byte. Execute the code step by step and watch the byte moved to offset(%rbp) to get the flag HCMUS-CTF{St4cK_Str1ng_G00D_old_techn1qu3}.

