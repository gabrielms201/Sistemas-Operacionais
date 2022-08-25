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

    const char* destinyFilePath = argv[2];
    const char* sourceFilePath = argv[1];

    FILE* sourceFile = fopen(sourceFilePath, "r");
    FILE* destinyFile = fopen(destinyFilePath, "w+");


    if (sourceFile == NULL)
    {
        puts("ERROR TENTANDO ABRIR O ARQUIVO FONTE!");
        exit(1);
    }
    if (destinyFile == NULL)
    {
        puts("ERRO TENTANDO ABRIR O ARQUIVO DESTINO!");
        exit(1);
    }
    char ch;
    while (ch != EOF)
    {
        ch = fgetc(sourceFile);
        fputc(ch, destinyFile);
    }
    fclose(sourceFile);
    fclose(destinyFile);

}