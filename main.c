#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "trie.h"

int main(int argc, char *argv[])
{
    FILE *file = NULL;
    char palavra[200];
    int i = 0;
    int x = 0;
    struct Hash bgr;
    struct Hash *rec;
    int n = 3;
    int total_pala = 0;
    char c;

    // for (int j = 0; j < argc; j++)
    // {
    //     // printf("%s", argv[j]);
    // }
    // printf("%s", argv[2]);

    struct Trie *root = addNode();

    file = fopen(argv[3], "r");

    if (file == NULL)
    {
        printf("\n -- Problema ao abrir o arquivo de texto! -- \n");
    }
    else
    {

        while ((c = getc(file)) != EOF)
        {
            c = tolower(c);
            //ignora numeros e espaco
            if ((c > 47) && (c < 58) || (c == ' ') && (i == 0))
            {
            }
            //adiciona caracteres somente de a-z
            if ((c >= 97) && (c <= 122))
            {
                palavra[i] = c;
                i++;
            }
            // insere palavra na trie apos encontrar
            else if ((c == '\n') || (c == 32))
            {
                palavra[i] = '\0';
                total_pala++;
                inserir(root, palavra);
                i = 0;
            }
        }

        if (strcmp(argv[1], "--freq") == 0)
        {
            display(root, bgr, x, n);
            printf("---total de palavras: %d---\n", total_pala);
        }
        else if (strcmp(argv[1], "--freq-word") == 0)
        {
            printf("\n %s: %d\n", argv[2], procurar(root, argv[2]));
        }
        else if (strcmp(argv[1], "--search") == 0)
        {
        }

        fclose(file);
    }

    return 0;
}