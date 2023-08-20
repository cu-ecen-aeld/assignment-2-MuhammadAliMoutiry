#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char *argv[]){
ssize_t nr;
char filename[50];
char  writestr[50];
openlog(NULL, 0, LOG_USER);
if(argc == 1) return 1;
else if(argc < 3){
    syslog(LOG_ERR,"Expected args are 2 but %d passed",argc);
    return 1;
}else if(argc == 3){
   stpcpy(filename, argv[1]); 
   stpcpy(writestr, argv[2]);
}
int fd = creat(filename,0664);
if (fd == -1 ){
    syslog(LOG_ERR,"Couldn't open or create the file");
}else{

    nr = write(fd, writestr, strlen(writestr));
    syslog(LOG_DEBUG,"Writing %s to %s",writestr, filename);
    close(fd);

}




}
