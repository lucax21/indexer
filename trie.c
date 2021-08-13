#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trie.h"

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#define ALPHABET_SIZE (26)

struct Trie
{
    int eh_palavra;
    int count;
    struct Trie *filhos[ALPHABET_SIZE];
};

struct Trie *addNode()
{

    struct Trie *node = (struct Trie *)malloc(sizeof(struct Trie));

    node->eh_palavra = 0;

    for (int i = 0; i < 26; i++)
    {
        node->filhos[i] = NULL;
    }
    return node;
}

int eh_palavra(struct Trie *node)
{
    if (node->eh_palavra == 1)
    {
        return node->eh_palavra;
    }
}

void inserir(struct Trie *root, const char *key)
{

    int length = strlen(key);
    struct Trie *pCrawl = root;

    for (int level = 0; level < length; level++)
    {

        int index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->filhos[index])
            pCrawl->filhos[index] = addNode();
        pCrawl = pCrawl->filhos[index];
    }

    // marca com 1 se for folha (palavra)
    pCrawl->count++;
    pCrawl->eh_palavra = 1;
}

int procurar(struct Trie *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct Trie *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->filhos[index])

            return 0;

        pCrawl = pCrawl->filhos[index];
    }

    return (pCrawl->count);
}

void display(struct Trie *root, struct Hash paval, int level, int n)
{
    int i;
    struct Hash vet[n];

    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (eh_palavra(root) == 1)
    {

        paval.chave[level] = '\0';
        paval.valor = root->count;

        if (paval.valor > vet[i].valor)
        {
            strcpy(vet[i].chave, paval.chave);
            vet[i].valor = paval.valor;
            printf("%s - > %d\n", vet[i].chave, vet[i].valor);
            i++;
        }
    }

    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->filhos[i])
        {
            paval.chave[level] = i + 'a';
            display(root->filhos[i], paval, level + 1, n);
        }
    }
}
