///DFS to do a topological sort
#include <vector>
#include <algorithm>
#include <stdio.h>

#define numNodes 20
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G(numNodes);
vi parent(numNodes,-1);
vi sortedDAG;
int N=0;

void DFS_Visit(int s) {
    ///for each edge on s
    for(vi::const_iterator v = G[s].begin(); v != G[s].end(); v++) {
        if(parent[*v]==-1) { ///if it hasn't been explored
            parent[*v] = s; ///set parent
            DFS_Visit(*v); ///explore vertex
        }
    }
    sortedDAG.push_back(s+1); ///when it finished, put it into the topological sort array in reverse order
}

void DFS() {
    ///explore every unexplored vertex
    for(int i=0; i<N; i++) {
        if(parent[i]==-1) {
            parent[i]=-2;
            DFS_Visit(i);
        }
    }
}

int main() {
    scanf("%d", &N);
    int x,y;
    scanf("%d %d", &x, &y);
    while(x!=0 && y!=0) {
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
        scanf("%d %d", &x, &y);
    }
    DFS();
    reverse(sortedDAG.begin(), sortedDAG.end()); ///reverse the topological sort to correct order
    for(int i=0; i<N; i++) {
        printf("%d ", sortedDAG[i]);
    }
    return 0;
}










///USING ARRAYS INSTEAD OF VECTORS
/*int graph[numNodes][numNodes], parent[numNodes];
void DFS_Visit(int s) {
    for(int i=1; i<=graph[s][0]; i++) {
        int v = graph[s][i];
        if(parent[v]==-1) {
            parent[v] = s;
            DFS_Visit(v);
        }
    }
}

void DFS() {
    for(int v=0; v<numNodes; v++) {
        if(parent[v]==-1) {
            parent[v] = -2;
            DFS_Visit(v);
        }
    }
}

int main() {
    int x,y;
    fill(parent, parent+numNodes, -1);
    cin >> x >> y;
    while(x!=-1 && y!=-1) {
        graph[x][0]++;
        graph[x][graph[x][0]]=y;
        graph[y][0]++;
        graph[y][graph[y][0]]=x;
        cin >> x >> y;
    }
    DFS();
    for(int i=0; i<numNodes; i++)
        cout << i << ": " << parent[i] << endl;
    return 0;
}
*/
