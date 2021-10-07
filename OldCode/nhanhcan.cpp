#include <stdio.h>
int main() {
	char str[] = "Ibqqz!Cjsuiebz", *p;
	p = str;
	while(*p!='\0')
    	--*p++;
	printf("%s\n", str);
	printf("From bTs with love <3\n");
}
