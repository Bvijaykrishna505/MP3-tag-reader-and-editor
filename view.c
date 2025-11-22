#include "header.h"

void view_part(const char *filename)
{
        printf("--------------------------------------------\n");
        printf("MP3 tag Reader and Editor for ID3v2.3\n");
        printf("----------------------------------------------\n");
        FILE *fp;
        fp=fopen(filename,"rb"); //open the mp3 file in binary mode 
        if (fp==NULL) 
        {
            printf("Error opening file.\n");
            return ;
        }
        char id3[3]={0};
        fread(id3,3,1,fp);//read the tag
        if(strncmp(id3,"ID3",3)==0)
        {
            printf("ID3v2 tag detected\n");
        }
        else
        {
            printf("No idv3 tag detected\n");
           return;
        }
        fseek(fp,10,SEEK_SET);//skip 10 bytes for header
        int i=0;
        while (i<6)//read the frames
        {
            tag_id(&song,fp);//read the tag id
            tag_size(&song,fp);//read the tag size
            fseek(fp,3,SEEK_CUR);//skip 3 bytes after reading the tag and size for flag
            if (strcmp(song.tag, "TIT2") == 0)  //determine the type of frame and print label 
            {
                printf("Title       :   ");
            }
            else if (strcmp(song.tag, "TPE1") == 0)
            {
                printf("Artist      :   ");
            } 
            else if (strcmp(song.tag, "TALB") == 0)
            {
                printf("Album       :   ");
            } 
            else if (strcmp(song.tag, "TYER") == 0)
            {
                printf("Year        :   ");
            }
            else if (strcmp(song.tag, "TCON") == 0)
            {
                printf("Genre       :   ");
            }
            else if(strcmp(song.tag, "COMM") == 0)
            {
                printf("Comment     :   ");
            }
            i++;
            fread(song.data,song.size -1, 1, fp);//read the frame data 
            song.data[song.size -1] = '\0';//null terminate frame data
            //printf("%s\n", song.data); //print the frame data
            for(int i=0;i<song.size;i++)
            {
                printf("%c",song.data[i]);
            }
            printf("\n");
        } 
        fclose(fp);
        return ;
}