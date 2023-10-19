#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	
	int fd[2], n;
	char buffer[100];
	
	n = atoi(argv[1])

	for(int i=1; i<=argc; i++){
		if(i%2==1) buffer[i] = *argv[i];
		else buffer[i] = 'i'
	}

	pid_t p;
	pipe(fd);
	int summ = 0;
	p=fork();

	if(p>0){
		printf("Parent passing value to child\n");
		for (int i=1; i<=n; i++){
			write(fd[1], buffer, 1);
		}
	}
	else{
		printf("Child received data\n");

		for(int i=1; i<=n; i++){
			n = read(fd[0], buffer, 1);
			if(n%2==1) summ+= n;
		}
		write(1, buffer, n);
	}


	//FILE *rd;
	//char buffer[50];
	
	//rd = popen("ls", "r");
	//fread(buffer, 1, 10, rd);
	//printf("%s\n", buffer);
	
	//sprintf(buffer, "Hello World");
	
	//rd = popen("wc -c", "w");
	
	//fwrite(buffer, 1, 5, rd);
	
	//pclose(fd);

}

