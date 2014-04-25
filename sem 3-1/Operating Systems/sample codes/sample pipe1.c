/*This is a small program that gives an example of how a pipe works.
 *The array of two file descriptors is fd[2]. Whatever is written to fd[1] will be read from fd[0]. */
#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
int main(int argc, char **argv)
{
 int n;
 int fd[2];
 char buf[1025]; 
 char *data = "hello"; 
 char array[1] = "fasfa";
 printf("asfas %s\n",array);
  printf("read %d bytes from the pipe: \"%s\"\n", n, buf); 
 pipe(fd);
 write(fd[1], array, strlen(array));
 if ((n = read(fd[0], buf, 1024)) >= 0)
 {
    printf("printing n %d\n",n);
  buf[n] = 'j'; /* terminate the string */
  printf("read %d bytes from the pipe: \"%s\"\n", n, buf); 
 }
 else perror("read");
 exit(0); 
} 
