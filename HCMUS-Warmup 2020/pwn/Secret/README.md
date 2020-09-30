# Challenge secret (150pts)
Use gdb to analyze ELF file. First it get the string in "flag.txt" file. The pseudo-code
``` C++
scanf(input)
len = strlen(input)
if (strcmp(flag, input, len) == 0){
    system("cat flag.txt");
}
```

It compare the input string with *len* character of the flag. We know the flag is in format HCMUS-CTF{...}. So any prefix of HCMUS-CTF{ is ok.

The flag is HCMUS-CTF{strncmp_is_so_fun}