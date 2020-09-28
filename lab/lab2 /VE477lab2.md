<p align="right">Yu xinmiao 于欣淼 518021910792</p>

# VE477 Lab2

### C programming

1. The `Union-Find` data structure && Kruskal’s algorithm 

   `Union-Find` is used when implement the Kruskal’s algorithm.

   ```c
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
   ```

   **Time complexity** for $G = (V, E)$,

   - sort the edges according to the weight: using `qsort`, $\mathcal{O}(ElogE)$
   - For sorted edge, add the edge if no cycle created. Create `parent` to store `parent` and `rank`: $|V|$ operations. In for loop, `Find` and `Union` operations are performed in $\mathcal{O}(E)$ times,  as we use union-by-rank and path-compression mehods, the operations should grow in a very slow rate when $V$ increases. Such that we could state that totally $\mathcal{O}((E+V)\alpha(V))$ time, where $\alpha$ is inverse Ackerman’s function. 

   As $|E|\geq |V| - 1$, so takes totally $\mathcal{O}(E\alpha(V))$ times of operation. So for the whole algorithm, the time complexity is $\mathcal{O}(ElogE)$. 

   (ignore the part that after find MST, sort to print)

2. Prim’s algorithm 

   ```c
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
     // compare function for qsort, to output in correct order 
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
     // find the minimum distance among not added node
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
       distance[0] = 0; added[0] = true; parent[0] = -1; // add the first element 
       for (int i = 0; i < vNum - 1; i++) {
           int v = minDis(distance, added, vNum);
           added[v] = true; // add the node with minimum distance 
           for (int u = 0; u < vNum; ++u) {
               if (graph[v][u] && !added[u] && distance[u] > graph[u][v]){
                   parent[u] = v; // update 
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
   		return 0;
   };
   
   ```

   **Time complexity** for $G = (V, E)$,

   If implement with an adjacency matrix, the time complexity is $\mathcal{O}(V^2)$, which is caused by the traversal. However, if optimazied through Fibnacci Heap, the running time will be $\mathcal{O}(E+VlogV)$. 

3. Compare 

   It depends on the type of graphs. For **dense graph**, Prim algorithm will have a better performance. For **sparse graph**, Kruskal algorithm will have a better performance. 