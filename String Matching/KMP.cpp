#include <cstdio>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;


vi createKMPTable(string P) {
    int m = P.size();
    vi pi(m,0);
    int k=0; pi[0] = k;
    for(int i=1; i<m; i++) {
        while(k > 0 && P[k] != P[i])
            k = pi[k-1];
        if(P[k] == P[i])
            k++;
        pi[i] = k;
    }
    return pi;
}

vi KMP_Matching(string T, string P) {
    int n = T.size(), m = P.size();
    vi pi = createKMPTable(P);
    vi matchedIndices;
    int q = 0;
    for(int i=0; i<n; i++) {
        while(q > 0 && P[q] != T[i])
            q = pi[q-1];
        if(P[q] == T[i])
            q++;
        if(q == m) {
            matchedIndices.push_back(i-m+1);
            q = pi[q-1];
        }
    }
    return matchedIndices;
}

int main() {
    /*vi t = createKMPTable("bcabcbcabca");
    for(vi::const_iterator it = t.begin(); it != t.end(); it++) printf("%d\n", *it);*/
    string T, P;
    char t[100], p[100];
    scanf("%s\n", t); T = t;
    scanf("%s\n", p); P = p;
    vi matchedIndices = KMP_Matching(T, P);
    for(vi::const_iterator it = matchedIndices.begin(); it != matchedIndices.end(); it++) {
        printf("String located at %d\n", *it);
    }
    return 0;
}
