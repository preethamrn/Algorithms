#include <vector>
#include <stdio.h>
#define numNodes 20
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G(numNodes);
vi parent(numNodes,-1);
vi level(numNodes,-1);
int N;

void BFS(int s) {
    int i=0;
    level[s] = i;
    vi next; next.push_back(s);
    while(!next.empty()) {
        i++; vi tempNext;
        for(vi::const_iterator u = next.begin(); u != next.end(); u++) { ///loop through each vertex in next
            for(vi::const_iterator v = G[*u].begin(); v != G[*u].end(); v++) { ///loop through each edge of current vertex
                if(level[*v]==-1) { ///if not explored
                    level[*v] = i; ///set level
                    parent[*v] = *u; ///sets parent
                    tempNext.push_back(*v); ///put into temporary next (stores values to be explored next)
                }
            }
        }
        next = tempNext; ///goes to next level
    }
}

int main() {
    scanf("%d ", &N);
    int x,y;
    scanf("%d %d", &x, &y);
    while(x!=0 && y!=0) {
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
        scanf("%d %d", &x, &y);
    }
    int start; scanf("%d", &start);
    BFS(start-1);
    for(int i=0; i<N; i++)
        cout << i+1 << ": " << level[i] << endl;
    return 0;
}








/*
int graph[numNodes][numNodes]={{0}}, level[numNodes], parent[numNodes];
void BFS(int s) {
    ///start from s, setting the level and putting it into next
    int i=0; level[s]=i;
    int next[21]; next[0]=1; next[1]=s;
    ///loop through all vertices till next is empty
    while(next[0]!=0) {
        i++;
        int numNextNodes = 0;
        for(int j=1; j<=next[0]; j++) { ///loop through each vertex
            int u = next[j]; ///current vertex
            for(int k=1; k<=graph[u][0]; k++) { ///loop through each edge on u
                int v = graph[u][k]; ///next vertex
                if(level[v]==-1) { ///if unvisited (ie, level not set)
                    numNextNodes++;
                    next[numNextNodes]=v; ///puts this node into next
                    level[v]=i; ///sets the current level
                    parent[v]=u; ///sets parent
                }
            }
        }
        next[0] = numNextNodes;
    }
}

int main() {
    int x,y;
    fill(level, level+numNodes, -1);
    fill(parent, parent+numNodes, -1);
    cin >> x >> y;
    while(x!=-1 && y!=-1) {
        ///both x and y have to be set for undirected graphs
        graph[x][0]++;
        graph[x][graph[x][0]] = y;
        graph[y][0]++;
        graph[y][graph[y][0]] = x;
        cin >> x >> y;
    }
    BFS(0);
    for(int i=0; i<numNodes; i++)
        cout << i << ": " << level[i] << endl;
    return 0;
}
*/
//0 1 0 2 2 3 2 6 3 6 3 4 4 5 -1 -1
