#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *string = (char *)malloc(100 * sizeof(char));

    printf("Digite uma string para ela ser criptografada:\n");
    fgets(string, 100, stdin);

    //*Etapa 1;

    for (int i = 0; i < strlen(string); i++)
    {
        *(string + i) += 3;
    }

    puts(string);

    char Suporte;
    //*Etapa 2;

    for (int i = 0; i < strlen(string) / 2; i++)
    {
        Suporte = *(string + i);
        *(string + i) = string[strlen(string) - i - 1];
        string[strlen(string) - i - 1] = Suporte;
    }

    puts(string);

    //*Etapa 3

    for (int i = 0; i < strlen(string) / 2; i++)
    {
        *(string + i + strlen(string) / 2) -= 1;
    }

    puts(string);

    return 0;
}
