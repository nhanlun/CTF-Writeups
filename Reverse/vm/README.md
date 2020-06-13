# VM (200 pts)

First, read the assembly code from a disassembler such as gdb. We see that they simulate some machine code in a kind of virtual machine. The structure of the machine is like the following:

```c
struct vm {
        char* data;        //our input string from index 10 onwards input[10..EndOfOurInput]. Must be of length 28.
        char* code;        //string of hardcoded values
        int code_size; //length of *code.
        //The below are zero-initialized.
        short pc; //0x14 //PERHAPS this is PC (Program counter?)
        byte ra; //Register ra store result of the last operation.
        BYTE flag; //Similar to EFLAG
        BYTE sp; //special flag. Iff this register is set to 1 at the end of <runVM>, we input the right flag.
};
```

Second, we read `runVM` assembly code and note down the opcode of the VM in terms of what they do, results in `vm_opcode.txt`. This step and the last step of finding out the structure of the virtual machine are done in parallel.

Third, we dump the hardcoded `vm->code` to a text file. The results look like this:

![Code](codedump.png)

We translate the dumped code to something more human-friendly, using the rules specified in `vm_opcode.txt`. The result looks like this:

![disasm](disasm.png)

Fourth, we reverse the above code to get the flag. This step was poorly done, had we automated the reversing, it could take less time. Anyway, we note down each byte of the flag HCMUS-CTF{M4Lwar3_us3s_v1rtuaL_m4chin3}.