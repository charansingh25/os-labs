#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, int* argv[]){
	
	int fd[2], n;
	int buffer[100];

	for(int i=1; i<=argc; i++){

	}

	pid_t p;
	pipe(fd);
	int summ = 0;
	p=fork();

	if(p>0){
		printf("Parent passing value to child\n");
		for (int i=1; i<=n; i++){
			write(fd[1], argv[i], sizeof(int));
		}
	}
	else{
		printf("Child received data\n");

		for(int i=1; i<=n; i++){
			n = read(fd[0], argv[i], sizeof(int));
			if(n%2==1) summ+= n;
		}
		write(1, summ, sizeof(int));
	}


	//FILE *rd;
	//char buffer[50];
	
	//rd = popen("ls", "r");
	//fread(buffer, 1, 10, rd);
	//printf("%s\n", buffer);
	
	//sprintf(buffer, "Hello World");
	
	//rd = popen("wc -c", "w");
	
	//fwrite(buffer, 1, 5, rd);
	
	pclose(rd);

}
