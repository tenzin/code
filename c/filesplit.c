/** program  split a file
   * -tenzin
   * originally compiled under MinGW-2.0.0
   * Modified to compile under gcc in debian etch
   **/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define SIZE 512

void usage(void);
char *int_to_string(int);

main(int argc, char *argv[])
{
        char buf[SIZE];
        int infd, outfd, joinfd, siz, sizcnt, filecnt=0, filelim;
        if(argc != 3)
        {
                usage();
                exit(1);
        }
        
        switch(atoi(argv[1]))
        {
                case 1440 : filelim = 2880;
                            break;
                case 1200 : filelim = 2400;
                            break;
                case 720  : filelim = 1440;
                            break;
                default   : usage();
                            exit(1);
        }
        infd=open(argv[2], O_RDONLY); /* | O_BINARY); */
        if(infd==-1)
        {
                printf("could'nt open input file %s\n",argv[2]);
                exit(1);
        }
        while(TRUE)
        {
                outfd=open(int_to_string(filecnt),O_WRONLY | O_CREAT | O_TRUNC,0664); /*O_BINARY,0664);*/
                if(outfd==-1)
                {
                        puts("cannot create output file\n");
                        exit(1);
                }
                sizcnt=0;
                while((siz=read(infd,buf,SIZE))>0)
                {
                        write(outfd,buf,siz);
                        sizcnt++;
                        if(sizcnt >= filelim) break;
                }
                close(outfd);
                if(siz==0)
                {
                        printf("total files created = %d\n",filecnt+1);
                        break;
                }
                else filecnt++;
        }
        close(infd);
        /* creating joiner */
        printf("creating Joiner file\n");
        joinfd=open("join.bat",O_WRONLY | O_CREAT | O_TRUNC,0664);
        if(joinfd==-1)
        {
                printf("errro in creating the joiner file\n");
                return 0;
        }
        write(joinfd,"copy /b ",8);
        for(siz=0;siz<=filecnt;siz++)
        {
                strcpy(buf,int_to_string(siz));
                sizcnt=strlen(buf);
                if(siz==filecnt) strcat(buf," ");
                else strcat(buf,"+");
                write(joinfd,buf,sizcnt + 1);
        }
        write(joinfd,argv[2],strlen(argv[2]));
        close(joinfd);
        printf("File split succesfull\n");
        
}

char * int_to_string(int i)
{
	int j,k,l;
	char *c,temp;
	c=(char *)malloc(10*sizeof(char));
	j=0;
	while((i/10)!=0)
	{
		k=i%10;
		c[j]=48+k;
		i=i/10;
		j++;
	}
	c[j]=48+i;
	c[++j]='\0';
	l=strlen(c);
	j=l-1;
	k=0;
	while(j>k)
	{
		temp=c[j];
		c[j]=c[k];
		c[k]=temp;
		k++;
		j--;
	 }
	 c[l]='\0';
	 return c;
}

void usage()
{
        printf("use the program as follows:\n");
        printf("fsplit <size> <filename>\n");
        printf("the value for <size> are :\n");
        printf("1440 for 1.44mb floppy\n1200 for 1.2mb floppy\n720 for 720kb floppy\n");
        printf("<filename> is the name of the file you want to split\n");
}
