#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


typedef struct node_t node;
struct node_t {
    int v1; int v2;
};

int cmp (const void*a, const void*b) {
    node* n1 = (node*) a;
    node* n2 = (node*) b;
    if (n1->v1 < n2->v1) return -1;
    else if (n1->v1 > n2->v1) return 1;
    else return n1->v2 > n2->v2;
 }
void printGraph(int vNum, const int parent[]) {
    node* nodes = (node*)malloc(sizeof(node) * vNum);
    nodes[0].v1 = 0; nodes[0].v2 = 0;
    for (int i = 1; i < vNum; ++i) {
        if (i > parent[i]) {nodes[i].v1 = parent[i]; nodes[i].v2 = i;}
        else {nodes[i].v1 = i; nodes[i].v2 = parent[i];}
    }
    qsort(nodes, vNum, sizeof(nodes[0]), cmp);
    for (int i = 1; i < vNum; i++) {
        printf("%d--%d\n", nodes[i].v1, nodes[i].v2);
    }
    free(nodes);
}

int minDis(const int distance[], const bool added[], int vNum) {
    int minimum = INT_MAX;
    int index = 0;
    for (int i = 0; i < vNum; i++) {
        if (distance[i] < minimum && !added[i]) {
            minimum = distance[i];
            index = i;
        }
    }
    return index;
}

void primMST(int** graph, int vNum) {
    int parent[vNum]; int distance[vNum]; bool added[vNum];
    for (int i = 0; i < vNum; i++) {
        distance[i] = INT_MAX;
        added[i] = false;
    }
    distance[0] = 0; added[0] = true; parent[0] = -1;
    for (int i = 0; i < vNum - 1; i++) {
        int v = minDis(distance, added, vNum);
        added[v] = true;
        for (int u = 0; u < vNum; ++u) {
            if (graph[v][u] && !added[u] && distance[u] > graph[u][v]){
                parent[u] = v;
                distance[u] = graph[u][v];
            }
        }
    }
    printGraph(vNum, parent);
}

int main (){
    int vNum, eNum;
    scanf("%d", &eNum);
    scanf("%d", &vNum);
    int** graph = (int**)malloc(sizeof(int*) * vNum);
    for (int i = 0; i < vNum; i++) graph[i] = (int*)malloc(sizeof(int) * vNum);
    for (int i = 0; i < eNum; i++) {
        int v1, v2, wt;
        scanf("%d %d %d", &v1, &v2, &wt);
        graph[v1][v2] = graph[v2][v1] = wt;
    }
    primMST(graph, vNum);

    for (int i = 0; i < vNum; i++) free(graph[i]);
    free(graph);


};
