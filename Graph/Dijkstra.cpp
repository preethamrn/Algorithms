#include <vector>
#include <set>
#include <stdio.h>
#define maxINT 1000000000
#define numNodes 20
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii G(numNodes);
vi parent(numNodes, -1);
vi D(numNodes, maxINT);
int N;

void Dijkstra(int s) {
    ///initialize: set D[s] = 0, create Q, add s to Q
    D[s] = 0;
    set<ii> Q;
    Q.insert(ii(D[s], s));

    while(!Q.empty()) {
        ii top = *Q.begin(); ///get minimum distance node from Q
        Q.erase(Q.begin()); ///remove min dist node from Q
        int v = top.second; ///get the vertex
        for(vii::const_iterator it = G[v].begin(); it != G[v].end(); it++) { ///iterate through all edges on v
            int v2 = it->first; ///get next vertex on that edge
            int cost = it->second; ///get cost of path
            if(D[v2] > D[v] + cost) { ///if shorter path exists
                if(D[v2] != maxINT) Q.erase(Q.find(ii(D[v2],v2))); ///if v2 already in Q, remove it (and add again later)
                D[v2] = D[v] + cost; ///set new shortest distance
                parent[v2] = v; ///set parent
                Q.insert(ii(D[v2],v2)); ///add v2 to Q
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
        G[y-1].push_back(ii(x-1, w));
        scanf("%d %d %d", &x, &y, &w);
    }
    int start; scanf("%d", &start);
    Dijkstra(start-1);
    for(int i=0; i<N; i++) printf("%d: %d\n", i+1, D[i]);
    return 0;
}
