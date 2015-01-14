///Uses Floyd-Warshall to find all-pairs shortest path. Computes the longest shorted path from that.
#include <vector>
#include <stdio.h>
#define numNodes 20
#define maxINT 1000000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii G(numNodes);
int A[numNodes][numNodes];
int next[numNodes][numNodes];
int N;

///k is the intermediate vertex
///for each k, go to the k(th) row and column and check if the sum of i,k and k,j is less than i,j current value.
///if it is, set vertex distance and set the next pointer as same as the shortest path from i,k
void FloydWarshall() {
    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

vi reconstructPath(int u, int v) {
    vi path;
    if(next[u][v] == -1) return path;
    path.push_back(u);
    while(u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i != j) A[i][j] = maxINT;
            else A[i][j] = 0;
            next[i][j] = -1;
        }
    }

    int x,y,w;
    scanf("%d %d %d", &x, &y, &w);
    while(x!=0 && y!=0) {
        G[x-1].push_back(ii(y-1, w));
        A[x-1][y-1] = w;
        next[x-1][y-1] = y-1;
        scanf("%d %d %d", &x, &y, &w);
    }
    FloydWarshall();
    int max=0; ii maxPair(-1, -1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(A[i][j] > max) {
                max = A[i][j];
                maxPair = ii(i, j);
            }
            printf("%d, %d: %d\n", i+1, j+1, A[i][j]);
        }
    }
    printf("Max pair is - %d, %d: %d\n", maxPair.first+1, maxPair.second+1, max);
    printf("PATH: ");
    vi path = reconstructPath(maxPair.second, maxPair.first);
    for(vi::const_iterator it = path.begin(); it != path.end(); it++) {
        printf("%d ", *it+1);
    }
}
