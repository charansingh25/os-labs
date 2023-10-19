#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void * shared_memory;
    char buff[100], input[100];
    int shmid;

    shmid = shmget((key_t)2346, 1024, 0666|IPC_CREAT);

    printf("Key of shared memory si %d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0);

    printf("Process attached at %p\n", shared_memory);
    printf("Data recieved from shared memory is : %s\n", (char *) shared_memory);

    char ans[100];
    strcpy(ans, shared_memory);

    char longest[100];
    int ct =0, mx = 0, index = 0, length;
    length = strlen(ans);

    for(int i=0; i<length; i++){
        if(ans[i] != ' '){
            ct++;
        }
        else{
            if(ct>mx){
                mx = ct;
                index = i-mx;
            }
            ct =0;
        }
    }
    
    if(ct>mx){
        mx = ct;
        index = length-mx;
    }

    int j =0;
    for(int i = index; i<index+mx; i++){
        longest[j] = ans[i];
        j++;
    }

    longest[j] = '\0';

    printf("Word is : %s\n", longest);


    int space = 0;
    for(int i=0; i<length; i++){
        if(ans[i] = ' '){
            space++;
        }
    }

    int arr[space][2];
    int ctt =0;
    int mxx = 0;
    int indexx = 0;

    for(int i=0; i<length; i++){
        if(ans[i] != ' '){
            ctt++;
        }
        else{
            if(ctt>mxx){
                mxx = ctt;
                indexx = i-mxx;
            }
            ctt =0;
        }

        arr[i][1] = 
    }
    if(ctt>mxx){
        mxx = ctt;
        indexx = length-mxx;
    }



    // now sort according to the length
}