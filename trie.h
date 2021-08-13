struct Hash
{
    char chave[200];
    int valor;
} hash;

struct Trie *addNode();
void inserir(struct Trie *root, const char *key);
int procurar(struct Trie *root, const char *key);
void display(struct Trie *root, struct Hash paval, int level, int n);