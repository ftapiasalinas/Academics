/*Implementation of ls | wc -l*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
int main(void)
{
	int pfds[2];
	pipe(pfds);
	
	if (!fork()) 
	{
		//close(1); 				/* close normal stdout */
        
		dup2(pfds[1],1); 				/* make stdout same as pfds[1] */
        printf("sahil");
		close(pfds[0]); 			/* we don't need this
 */ 
        char in[4];
        read(pfds[0],in,5);
        printf("read in child is %s\n",in);
//		execlp("ls", "ls", NULL);
	} 
	else 
	{
		close(0); 				/* close normal stdin */
		dup(pfds[0]); 				/* make stdin same as pfds[0] */
//		close(pfds[1]);				/* we don't need this */
        char input[25];
        read(pfds[0],input,25);
        printf("length is %d\n",strlen(input));
        input[strlen(input)] = '\0';
        printf("reading in %s\n",input);  
		//execlp("wc", "wc", "-l", NULL);
	}
	return 0;
}

