#include "header.h"

void help(char *argv) {
    printf("Usage: %s [mode] [filename] [options]\n", argv);
    printf("Modes:\n");
    printf("  -v <file>             View ID3v2 tags\n");
    printf("  -e <file> <option> <value>  Edit a tag\n");
    printf("Options:\n");
    printf("  -t    Title\n");
    printf("  -a    Artist\n");
    printf("  -y    Year\n");
    printf("  -A    Album\n");
    printf("  -n    Genre\n");
    printf("  -c    Comment\n");
}
