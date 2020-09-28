#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct graph_t Graph;
typedef struct edge_t Edge;
typedef struct node_t Node;
struct edge_t{
    int v1, v2, wt;
};

struct graph_t{
    int Vnum, Enum;
    Edge* edge;
};

struct node_t{
    int parent;
    int rank;
};

Graph* createGraph(int V, int E){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vnum = V;
    graph->Enum = E;
    graph->edge = (Edge*)malloc(sizeof(Edge)*E);
    return graph;
};

void addEdge(Graph* graph, int E) {
    for (int i = 0; i < E; i++) {
        int v1, v2, wt;
        scanf("%d %d %d", &v1, &v2, &wt);
        if (v1 > v2) {
            int temp = v2;
            v2 = v1;
            v1 = temp;
        }
        graph->edge[i].v1 = v1;
        graph->edge[i].v2 = v2;
        graph->edge[i].wt = wt;
    }
}

int compare(const void * a, const void * b){
    // compare function to sort the edge according to weight
    Edge * e1 = (Edge*) a;
    Edge * e2 = (Edge*) b;
    if (e1->wt > e2->wt) return 1;
    else if (e1->wt < e2->wt) return -1;
    else return 0;
}
int vertexCom(const void*a, const void*b) {
    // compare function to sort the vertex
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    if (e1->v1 < e2->v1) return -1;
    else if (e1->v1 > e2->v1) return 1;
    else return e1->v2 > e2->v2;
}

// Union-Find data structure
int Find(Node* nodes, int i) {
    if (nodes[i].parent != i)
        nodes[i].parent = Find(nodes, nodes[i].parent); // update parent among the path
    return nodes[i].parent;
}
void Union(Node* nodes, int x, int y){
    int xRoot = Find(nodes, x);
    int yRoot = Find(nodes, y);
    // make the node with lower rank as the parent
    if (nodes[xRoot].rank < nodes[yRoot].rank)
        nodes[xRoot].parent = yRoot;
    else if (nodes[xRoot].rank > nodes[yRoot].rank)
        nodes[yRoot].parent = xRoot;
    else {
        nodes[xRoot].parent = yRoot;
        nodes[xRoot].rank++;
    }
}
void kruskalMST(Graph* graph){
    // sort based on the weight
    qsort(graph->edge, graph->Enum, sizeof(graph->edge[0]), compare);
    Edge result[graph->Vnum - 1];
    Node* nodes = (Node*)malloc(sizeof(Node) * graph->Vnum);
    for (int i = 0; i < graph->Vnum; i++) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }

    int eTaken = 0;
    int e = 0;
    while (eTaken < graph->Vnum - 1 && e < graph->Enum) {
        // for the edge in non-decreasing order
        Edge next = graph->edge[e++];
        int v1Root = Find(nodes, next.v1);
        int v2Root = Find(nodes, next.v2);
        if (v1Root != v2Root) { // no cycle created
            result[eTaken++] = next;
            Union(nodes, v1Root, v2Root); // union
        }
    }
    free(nodes);
    qsort(result, graph->Vnum - 1, sizeof(result[0]), vertexCom);
    for (int i = 0; i < graph->Vnum - 1; i++) {
        printf("%d--%d\n", result[i].v1, result[i].v2);
    }
}

int main() {
    int Vnum, Enum;
    scanf("%d", &Enum);
    scanf("%d", &Vnum);
    Graph * graph = createGraph(Vnum, Enum);
    addEdge(graph, Enum);
    kruskalMST(graph);
    free(graph->edge);
    free(graph);
    return 0;
}

