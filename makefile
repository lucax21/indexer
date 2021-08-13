all: indexer

indexer: trie.o main.o
	gcc trie.o main.o -lm -o indexer

arv_avl.o: trie.c trie.h
	gcc -c trie.c

main.o: main.c trie.h
	gcc -c main.c

clear:
	rm -rf *.o indexer


