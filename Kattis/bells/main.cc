#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int p[10];
bool d[10];

void print(int perm[], int n) {
    for (int i = 0; i != n - 1; ++i)
        printf("%d ", perm[i]);
    printf("%d\n", perm[n - 1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        p[i] = i + 1, d[i] = false;
    print(p, n);
    while (true) {
        int maxi = -1, maxv = 0;
        for (int i = 1; i < n - 1; ++i)
            if (p[i] != 1)
                switch (d[i]) {
                  case 0:
                    if (p[i] > p[i - 1] && p[i] > maxv)
                        maxv = p[maxi = i];
                    break;
                  case 1:
                    if (p[i] > p[i + 1] && p[i] > maxv)
                        maxv = p[maxi = i];
                    break;
                }
        if (p[0] != 1 && d[0] && p[0] > maxv)
            maxv = p[maxi = 0];
        if (p[n - 1] != 1 && !d[n - 1] && p[n - 1] > maxv)
            maxv = p[maxi = n - 1];
        if (maxi == -1) break;
        switch (d[maxi]) {
          case 0:
              swap(p[maxi], p[maxi - 1]);
              swap(d[maxi], d[maxi - 1]);
              break;
          case 1:
              swap(p[maxi], p[maxi + 1]);
              swap(d[maxi], d[maxi + 1]);
              break;
        }
        for (int i = 0; i != n; ++i) if (p[i] > maxv) d[i] ^= 1;
        print(p, n);
    }
    return 0;
}
