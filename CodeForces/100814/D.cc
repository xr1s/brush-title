#include <cstdio>
#include <cstring>
#include <list>
#include <algorithm>

using namespace std;

long long T, N, Q, P[100005], C[100005];
list<long long> chld[100005];
long long fst[100005];
long long melt[100005];
long long leafmelt[100005], leafnum;
bool leaf[100005];

long long qu[100005], qt, qh;
void bfs(long long s) {
    for (qu[qh = qt = 0] = s; qh <= qt; ++qh)
        for (long long ch: chld[qu[qh]])
            melt[qu[++qt] = ch] = melt[qu[qh]] + C[ch];
}

int main() {
    for (scanf("%lld", &T); T; --T) {
        memset(leaf, true, sizeof leaf);
        memset(melt, 0, sizeof melt);
        memset(fst, 0, sizeof fst);
        leafnum = 0;
        for (long long i = 0; i <= N; ++i) chld[i].clear();
        scanf("%lld", &N);
        for (long long i = 2; i <= N; ++i) {
            scanf("%lld%lld", &P[i], &C[i]);
            if (leaf[P[i]]) fst[P[i]] = i, leaf[P[i]] = false;
            else if (C[fst[P[i]]] > C[i]) fst[P[i]] = i;
            chld[P[i]].push_back(i);
        }
        for (long long i = 2; i <= N; ++i)
            C[i] = C[i] * 2 - C[fst[P[i]]];
        bfs(1);
        for (long long i = 1; i <= N; ++i)
            if (leaf[i]) leafmelt[leafnum++] = melt[i];
        sort(leafmelt, leafmelt + leafnum);
        for (scanf("%lld", &Q); Q; --Q) {
            long long qt; scanf("%lld", &qt);
            printf("%li\n", upper_bound(leafmelt, leafmelt + leafnum, qt) - leafmelt);
        }
    }
    return 0;
}
