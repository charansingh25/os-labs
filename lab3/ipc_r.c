#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	
	FILE *rd;
	char buffer[50];
	
	rd = popen("ls", "r");
	fread(buffer, 1, 10, rd);
	printf("%s\n", buffer);
	
	//sprintf(buffer, "Hello World");
	
	//rd = popen("wc -c", "w");
	
	//fwrite(buffer, 1, 5, rd);
	
	pclose(rd);

}
