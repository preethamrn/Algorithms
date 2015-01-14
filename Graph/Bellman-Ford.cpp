#include <stdio.h>
#include <vector>
#define numNodes 20
#define maxINT 1000000000
#define undefined -1000000000
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii G(numNodes);
vi parent(numNodes, -1);
vi D(numNodes, maxINT);
int N;

void BellmanFord(int s) {
    D[s] = 0;
    for(int i=0; i<N-1; i++) { ///N-1 passes over all edges
        for(int u=0; u<N; u++) { ///relax all edges
            for(vii::const_iterator it = G[u].begin(); it != G[u].end(); it++) {
                int v = it->first;
                int cost = it->second;
                if(D[v] > D[u] + cost) {
                    D[v] = D[u] + cost;
                    parent[v] = u;
                }
            }
        }
    }
    ///checks for negative cycles and if exists, sets the vertex with D[v] = undefined
    for(int u=0; u<N; u++) { ///relax all edges
        for(vii::const_iterator it = G[u].begin(); it != G[u].end(); it++) {
            int v = it->first;
            int cost = it->second;
            if(D[v] > D[u] + cost) {
                D[v] = undefined;
                parent[v] = u;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    int x,y,w;
    scanf("%d %d %d", &x, &y, &w);
    while(x!=0 && y!=0) {
        G[x-1].push_back(ii(y-1, w));
        scanf("%d %d %d", &x, &y, &w);
    }
    int start; scanf("%d", &start);
    BellmanFord(start-1);
    for(int i=0; i<N; i++) printf("%d: %d\n", i+1, D[i]);
    return 0;
}
