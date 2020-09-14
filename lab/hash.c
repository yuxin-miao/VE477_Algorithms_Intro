#include "hash.h"
#include <stdlib.h>
// define your only data structure here, you may define hashtable, buckets, elements, etc...
// hash function: key % size
typedef struct ele_t ele;
typedef struct bucket_t bucket;

struct ele_t {
    int key;
    int value;
    ele * next;
    ele * pre;
};

struct bucket_t {
    ele* first;
};


void *initializer(int size)
{
   bucket * table = (bucket*)malloc(sizeof(bucket)*size);
   for (int i = 0; i < size; i++) {
       table[i].first = NULL;
   }
   return table;
}

void insert(void* hashtable, int size, int key, int value)
{
    bucket * table = hashtable;
    int index = key % size;
    ele * newEle = (ele*)malloc(sizeof(ele));
    newEle->key = key;
    newEle->value = value;
    newEle->pre = NULL;
    ele * first = table[index].first;
    table[index].first = newEle;
    if (first == NULL) {
        newEle->next = NULL;
    }
    else {
        first->pre = newEle;
        newEle->next = first;
    }

}

void delete(void* hashtable, int size, int key)
{
    ele* current = search(hashtable, size, key);
    if (current) {
        ele* preCurr = current->pre;
        ele* afterCurr = current->next;
        preCurr->next = afterCurr;
        afterCurr->pre = preCurr;
        free(current);
    }
}

void* search(void* hashtable, int size, int key)
{
    bucket * table = hashtable;
    int index = key % size;
    ele* current = table[index].first;
    while (current) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int getValue(void* element)
{
    ele* elem = element;
    return elem->value;
}

void freeHashtable(void* hashtable, int size)
{
    bucket * table = hashtable;
    for (int i = 0; i < size; i++) {
        ele * current = table[i].first;
        while (current) {
            ele* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table);
}


