#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) {

    struct stat stats;
    stat("test.txt", &stats);
    int fil =  open("test.txt",O_APPEND);

    if(fil ==-1){
        fil =  open("test.txt",O_CREAT|O_APPEND);

    }

    int size = (int)stats.st_size;

    char buffer[sizeof("lol")];
   // size_t red;
   // read(fil, buffer, size);

    //strcat(buffer,"lol");
    //printf("%s \n", buffer);

    write(fil, buffer, sizeof("lol")+size-1);
    memset(buffer, 0,sizeof(buffer));
    read(fil, buffer, size );
    printf("%s \n", buffer);
    close(fil);


    return 0;
}
