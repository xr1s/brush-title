#include <cstdio>
using namespace std;

int N, M;
int set[10000];

int find(int u) {
  if (set[u] != u)
    set[u] = find(set[u]);
  return set[u];
}

bool same(int u, int v) {
  return find(u) == find(v);
}

void unite(int u, int v) {
  set[find(v)] = find(u);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i != N; ++i) set[i] = i;
  if (N != M + 1) {
    puts("NO"); return 0;
  }
  while (M--) {
    int u, v; scanf("%d%d", &u, &v);
    --u, --v;
    if (same(u, v)) {
      puts("NO"); return 0;
    }
    unite(u, v);
  }
  puts("YES");
  return 0;
}
