//DESCRIPTION
//NAME:B.VIJAY KRISHNA
//PROJECT NAME:MP3 TAG READER
//DATE:29/08/2025
#include"header.h"

struct mp3 song;
void tag_id(struct mp3*song,FILE*fp)//to read tag id from the file
{
     fread(song->tag,4,1,fp);//read the 4 bytes of the tag id
     song->tag[4]='\0';//null terminate the string
}
void little(int*size)//convert big endian to little endian
{
    char *ch=(char*)size;
    char temp=ch[0];
    ch[0]=ch[3];
    ch[3]=temp;
    temp=ch[1];
    ch[1]=ch[2];
    ch[2]=temp;
}
void tag_size(struct mp3*song,FILE*fp)//read the tag size
{
    fread(&song->size,4,1,fp);//read 4 bytes from the file
    little(&song->size);//convert big endian to little endian
}
void main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("ERROR: Not enough arguments\n");
        printf("Please pass ./a.out -help for the menu\n");

        return ;
    }
    if(strcmp(argv[1],"-help")==0)
    {
        help(argv[1]);//function to modifiers
        return ;
    }
    if(strcmp(argv[1],"-v")==0)
    {
        view_part(argv[2]);//function for view part
    }
    else if (strcmp(argv[1],"-e")==0)
    {
        if(argc<5)
        {
            printf("Not enough arguments\n");
            return ;
        }
        if(argc>=5)
        {
        edit_part(argv[2],argv[3],argv[4]);//function for edit part
        }
        // else
        // {
        //     printf("please enter 5 arguments only\n");
        // }
    }
    else
    {
        printf("unknown mode %s\n",argv[1]);
    }
    return ;
    
}


