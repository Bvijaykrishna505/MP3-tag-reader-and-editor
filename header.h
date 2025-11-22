#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mp3 {
    char tag[5];
    int size;
    char flag[3];
    char data[256];
};

extern struct mp3 song;  

void view_part(const char *filename);
void edit_part(const char *filename, const char *option, const char *new_con);
void help(char *argv);
void tag_id(struct mp3 *song, FILE *fp);
void little(int *size);
void tag_size(struct mp3 *song, FILE *fp);

#endif
