#include <stdio.h>
#include <stdlib.h>

void clean(){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    setbuf(stderr, 0);

}

void success(void) {
	char flag[64];
	
	FILE* fp = fopen("flag.txt", "r");
	if(!fp) {
		puts("File not found?, please contact admin");
		exit(0);
	}
	
	fgets(flag, sizeof(flag), fp);
	fclose(fp);
	puts(flag);
}

void fail(void) {
	puts("Try again :)!\n");
	fflush(stdout);
	exit(0);
}

int main(void) {
	clean();
  void (*fp)(); 
	char bof[64];
	
	fp = &fail;
	
	scanf("%s", bof);
	fp();
	return 0;
}
