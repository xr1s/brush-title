#include <cstdio>
#include <cctype>
#include <type_traits>
#include <algorithm>

using namespace std;

template <typename T,
        typename = typename enable_if<is_integral<T>::value>::type>
T get() {
    char c; while (!isdigit(c = getchar()) && c != '-');
    bool neg = c == '-'; T r = neg ? 0 : c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return neg ? -r : r;
}

template <typename T,
        typename = typename enable_if<is_integral<T>::value>::type>
void putint(T x) {
    static char buf[sizeof(T) << 2];
    static int len = 0;
    if (x < 0) putchar('-'), x = -x;
    do buf[len++] = x % 10; while (x /= 10);
    while (--len) putchar(buf[len] + '0');
    putchar(*buf + '0');
}

int score[1000000];

int main() {
    for (int T = get<int>(); T; --T) {
        int n = get<int>();
        int now = get<int>(), maxi = now, ans = 1u << 31;
        for (int i = 1; i != n; ++i) {
            now = get<int>();
            ans = max(ans, maxi - now);
            maxi = max(maxi, now);
        }
        putint(ans); putchar('\n');
    }
    return 0;
}
