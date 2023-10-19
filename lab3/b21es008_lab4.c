#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    int fd[2];
    int fd2[2];

    int buffer[100];

    pid_t p;

    pipe(fd);
    pipe(fd2);

    p = fork();

    if(p == 0)
    {
        wait(NULL);

        int n;
        int arr[15];

        int a = read(fd[0], &n, sizeof(int));

        int b = read(fd2[0], &arr, sizeof(int) * n);

        printf("\n%d %d", a, b);

        printf("\n\n");

        for(int i=0; i<n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        int n;
        printf("Enter the number of elements to be tranfered : \n");
        scanf("%d", &n);

	int summ = 0;
        int arr[n];

        printf("\nGenerating a random array of %d size...\n", n);

        srand(time(NULL));
            
        for(int i=0; i<n; i++)
        {
            arr[i] = rand() % 50;
            if (arr[i]%2 == 1) summ += arr[i]
            
            printf("%d ", arr[i]);
        }

            write(fd[1], &n, sizeof(int));
            write(fd2[1], &arr, sizeof(int) * n);
    }



    return 0;
}
