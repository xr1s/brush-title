#include <cstdio>
using namespace std;

int T, w, h;

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d", &w, &h);
        puts(w == h ? "Square" : "Rectangle");
    }
    return 0;
}
