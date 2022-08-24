#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        puts("USAGE: HandmadeCp [SOURCE] [DESTINY]");
        exit(1);
    }
    char* destinyPath = strcat(argv[2], "/");
    const char* destinyFilePath = strcat(destinyPath, argv[1]);
    const char* sourceFilePath = argv[1];

    FILE* sourceFile = fopen(sourceFilePath, "r");
    FILE* destinyFile = fopen(destinyFilePath, "w+");
}