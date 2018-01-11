#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
 
char* program_name;
 
void system_error(char* cause, int exit_code)
{
fprintf(stderr,"%s: %s: %s\n",program_name,cause, (char*) strerror(errno));
exit(exit_code);
}
 
 /* Zmiana nr 2
int main(int argc, char **argv)
{
if(argc != 2)
{
printf("Usage: %s <filename>\n",argv[0]);
exit(EXIT_FAILURE);
}
program_name = argv[0];
*/

/* Permisions for the new file */
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
 
/* filename for the new file */
char* filename = argv[1];
 
/* Create a new file */
int fd = open(filename,O_CREAT | O_EXCL,mode);
if(fd == -1)
{
system_error("open",EXIT_FAILURE);
}
 
exit(EXIT_SUCCESS);
}