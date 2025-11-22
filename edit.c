#include "header.h"

void edit_part(const char*filename,const char *option,const char*new_con)
{
    printf("--------------------------------------------\n");
    FILE *fp=fopen(filename,"rb");
    FILE *fptr=fopen("temp.mp3","wb");
    if(fp==NULL || fptr==NULL)
    {
        printf("Error opening file\n");
        //return;
    }
    printf("--------------selected edit option------------\n");
    char header[10];
    fread(header,10,1,fp);//read the header from source file
    fwrite(header,10,1,fptr);//copy in to the destination
    char tagname[5];
        if(strcmp(option,"-t")==0)
        {
            printf("--------------selected title to change----------> ");
            strcpy(tagname,"TIT2");
        }
        else if(strcmp(option,"-a")==0)
        {
            printf("--------------selected artist to change----------> ");
            strcpy(tagname,"TPE1");
        }
         else if(strcmp(option,"-y")==0)
        {
            printf("--------------selected year to change----------> ");
            strcpy(tagname,"TYER");
        }
         else if(strcmp(option,"-A")==0)
        {
            printf("--------------selected album to change----------> ");
            strcpy(tagname,"TALB");
        }
         else if(strcmp(option,"-n")==0)
        {
            printf("--------------selected content to change----------> ");
           strcpy(tagname,"TCON");
        }
         else if(strcmp(option,"-c")==0)
        {
            printf("--------------selected comment to change----------");
           strcpy(tagname,"COMM");
        }
        else
        {
            printf("Unknown tag option entered :%s\n",option);
        }
    int i=0;
    while(i<6)
    {     
        tag_id(&song,fp);//read the tag id
        tag_size(&song,fp);//read the tag size
        //fread(song.tag,4,1,fp);
        if(strcmp(song.tag,tagname)==0)//if current name matches with the  update tag
        {
            fwrite(song.tag, 4, 1, fptr);//copy the tag in to the destination
            int newsize=strlen(new_con)+1;
            printf("%s",new_con);
            little(&newsize);//convert big endian to little endian
            fwrite(&newsize, sizeof(int), 1, fptr);
            fread(song.flag,3,1,fp);//read the flag from source
            fwrite(song.flag, 3, 1, fptr);//copy the tag in to the destnation
            little(&newsize);
          
            fwrite(new_con,newsize-1, 1, fptr);//write the content in to the destination 
            fseek(fp, song.size - 1, SEEK_CUR); // Skip old frame data
            printf("\nUpdated tag %s with %s\n", tagname, new_con);//print the updated tag name and content
            break;
        }
        else
        {
            fwrite(song.tag, 4, 1, fptr);//copy the tag in to the destination
            int var = song.size;
            little(&var);//convert big endian to little endian
            fwrite(&var, 4, 1, fptr);
            fread(song.flag,3,1,fp);//read the flag from source
            fwrite(&song.flag, 3, 1, fptr);//copy the tag in to the destnation
            char *buffer = (char*)malloc(song.size - 1);//allocate memory
            fread(buffer, song.size-1, 1, fp);
            fwrite(buffer, song.size-1, 1, fptr);
            free(buffer); 
        }
        i++;
    }
    char ch;
    while(fread(&ch,1,1,fp)>0)//read remaining bytes from the input file
    {
        fwrite(&ch,1,1,fptr);//write in to the output file
    }
    
    fclose(fp);
    fclose(fptr);
    remove(filename);//remove the source file
    rename("temp.mp3",filename);//rename the destnation file as source file
    printf("File updated successfully.\n");
    //return 0;
}