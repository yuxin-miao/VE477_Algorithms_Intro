#include "dictionary.h"
#include <stdlib.h>

// define your only data structure here, you may define dictionary, elements, etc...
typedef struct ele_t ele;
typedef struct dict_t dict;

struct ele_t {
    ele *pred;
    ele *succ;
    int key;
    int value;
};

// sorted double link lists, key in increasing order
struct dict_t {
    ele *first;
    ele *last;
};

void *initializer() {
    dict *dic = (dict *) malloc(sizeof(dict));
    dic->first = NULL;
    dic->last = NULL;
    return dic;
}

void *search(void *dictionary, int key) {
    dict *dic = dictionary;
    ele *current = dic->first;
    while (current) {
        if (key == current->key) return current;
        current =  current->succ;
    }
    return NULL;
}

void insert(void *dictionary, int key, int value) {
    dict *dic = dictionary;
    ele *newEle = (ele *) malloc(sizeof(ele));
    newEle->key = key;
    newEle->value = value;
    if (dic->first == NULL) { // empty dictionary
        dic->first = dic->last = newEle;
        newEle->pred = NULL;
        newEle->succ = NULL;
        return;
    }
    for (ele *fir = dic->first; fir; fir = (ele *) fir->succ) {
        if (key < fir->key) {
            newEle->pred = fir->pred;
            newEle->succ = fir;
            if (fir->pred == NULL) { // will be first ele in the non-empty dict
                dic->first = newEle;
                newEle->pred = NULL;
            } else {
                ele *preNew = fir->pred;
                preNew->succ = newEle;
            }
            fir->pred = newEle;
            return;
        } else if (fir->succ == NULL && key > fir->key) { // will be the last ele in the non-empty dict
            newEle->pred = fir;
            newEle->succ = NULL;
            fir->succ = newEle;
            dic->last = newEle;
            return;
        }
        if (key == fir->key) {
            free(newEle);
            fir->value = value;
            return;
        }
    }

}

void delete(void *dictionary, int key) {
    dict *dic = dictionary;
    ele *toDelete = search(dictionary, key);
    if (toDelete) {
        ele *keyPre = toDelete->pred;
        ele *keySuc = toDelete->succ;
        if (keyPre) keyPre->succ = keySuc;
        else dic->first = keySuc;
        if (keySuc) keySuc->pred = keyPre;
        else dic->last = keyPre;
        free(toDelete);
    }
}

void *minimum(void *dictionary) {
    dict *dic = dictionary;
    return dic->first;
}

void *maximum(void *dictionary) {
    dict *dic = dictionary;
    return dic->last;
}

void *predecessor(void *dictionary, int key) {
    ele *target = search(dictionary, key);
    return target->pred;
}

void *successor(void *dictionary, int key) {
    ele *target = search(dictionary, key);
    return target->succ;
}


int getkey(void *element) {
    ele *ele = element;
    return ele->key;
}

int getvalue(void *element) {
    ele *ele = element;
    return ele->value;
}

void free_dict(void *dictionary) {

    dict *dic = dictionary;
    ele *current = dic->first;
    while (current) {
        ele *temp = current;
        current = current->succ;
        free(temp);
    }
    free(dic);
}


