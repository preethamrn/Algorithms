#include <iostream>
#define numNodes 20
#define maxINT 35000
using namespace std;

int graph[numNodes][numNodes], weight[numNodes][numNodes], parent[numNodes], sortedDAG[numNodes], count=0;
int n; ///number of nodes

///DFS_Visit, DFS, invert for calculating the topological sort
void DFS_Visit(int s) {
    for(int i=1; i<=graph[s][0]; i++) {
        int v = graph[s][i];
        if(parent[v]==-1) {
            parent[v]=s;
            DFS_Visit(v);
        }
    }
    sortedDAG[count] = s;
    count++;
}

void DFS() {
    for(int i=0; i<n; i++) {
        if(parent[i]==-1) {
            parent[i]=-2;
            DFS_Visit(i);
        }
    }
}

void invert() {
    for(int i=0; i<count/2; i++) {
        int temp = sortedDAG[i];
        sortedDAG[i] = sortedDAG[count-i-1];
        sortedDAG[count-i-1] = temp;
    }
}

int d[numNodes], shortestParents[numNodes];
void shortest(int index, int v) {
    if(index > count) return;
    int u = sortedDAG[index];
    if(u == v) return;
    ///relax all edges
    for(int i=1; i<=graph[u][0]; i++) {
        int next = graph[u][i];
        if(weight[u][next] + d[u] < d[next]) {
            d[next] = weight[u][next] + d[u];
            shortestParents[next] = u;
        }
    }
    shortest(index+1, v);
}

int main() {
    cin >> n;
    int x,y,w;
    fill(parent, parent+numNodes, -1);
    fill(d, d+numNodes, maxINT);
    cin >> x >> y >> w;
    while(x!=-1 && y!=-1) {
        graph[x][0]++;
        graph[x][graph[x][0]] = y;
        weight[x][y] = w;
        cin >> x >> y >> w;
    }
    DFS();
    invert();
    int start, end, index=0;
    cin >> start >> end;
    for(; index<count; index++) {
        if(sortedDAG[index] == start) {
            d[start] = 0;
            shortest(index, end);
            break;
        }
    }
    cout << d[end];
    return 0;
}
//for(int i=0; i<n; i++) {for(int j=0; j<n; j++) {cout << graph[i][j] << " ";}cout <<endl;}
