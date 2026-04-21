#include <stdio.h>
#include <string.h>

#define MAX 100
#define EMPTY -1

int table[MAX];
int m;

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash table full, cannot insert %d\n", key);
}

// Search using quadratic probing
int search(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY)
            return 0;

        if (table[newIndex] == key)
            return 1;
    }

    return 0;
}

int main() {
    int q;
    char op[10];
    int key;

    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
