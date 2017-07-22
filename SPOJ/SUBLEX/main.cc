#include <cstdio>
#include <cstring>

using namespace std;

constexpr int maxn = 180005;

char str[90005];
int len;
int fail[maxn], child[maxn][26], maxlen[maxn];
int samlast = 1, samnode = 1;
int lencnt[maxn], sorted[maxn], size[maxn];
int Q;

void extend(char c, int pos) {
    int p = samlast, np = samlast = ++samnode;
    maxlen[np] = pos + 1;
    while (p && !child[p][c])
        child[p][c] = np, p = fail[p];
    if (p) {
        int q = child[p][c];
        if (maxlen[p] + 1 != maxlen[q]) {
            int nq = ++samnode; maxlen[nq] = maxlen[p] + 1;
            memcpy(child[nq], child[q], sizeof *child);
            fail[nq] = fail[q]; fail[q] = fail[np] = nq;
            while (child[p][c] == q)
                child[p][c] = nq, p = fail[p];
        } else fail[np] = q;
    } else fail[np] = 1;
}

int main() {
    scanf("%s", str); len = strlen(str);
    for (int i = 0; i != len; ++i) extend(str[i] - 'a', i);
    for (int i = 1; i <= samnode; ++i) ++lencnt[maxlen[i]];
    for (int i = 1; i <= len; ++i) lencnt[i] += lencnt[i - 1];
    for (int i = 1; i <= samnode; ++i) sorted[--lencnt[maxlen[i]]] = i;
    for (int i = samnode - 1; ~i; --i) {
        size[sorted[i]] = 1;
        for (int j = 0; j != 26; ++j)
            size[sorted[i]] += size[child[sorted[i]][j]];
    }
    for (scanf("%d", &Q); Q; --Q) {
        int K, p = 1;
        for (scanf("%d", &K); K; ) {
            for (int c = 0; c != 26; ++c)
                if (child[p][c] && K <= size[child[p][c]]) {
                    putchar(c + 'a');
                    p = child[p][c];
                    --K;
                    break;
                } else K -= size[child[p][c]];
        }
        putchar('\n');
    }
    return 0;
}
