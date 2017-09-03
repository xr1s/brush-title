#include <cstdio>
#include <cctype>
#include <functional>
#include <type_traits>
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

template <typename T, typename Next>
T floyd(T s, Next f) {
    T t = s;
    T ans = s;
    do {
        ans = max(ans, s = f(s));
        ans = max(ans, t = f(t));
        ans = max(ans, t = f(t));
    } while (s != t);
    return ans;
}

int main() {
    for (int T = get<int>(); T; --T) {
        long n = get<long>(), k = get<long>();
        putint(floyd(k, [&n](long v) -> long {
            static char buf[20];
            int len = 0;
            for (v *= v; v; v /= 10)
                buf[len++] = v % 10;
            long result = 0;
            for (int i = 1; i <= n; ++i)
                (result *= 10) += buf[len - i];
            return result;
        }));
        putchar('\n');
    }
    return 0;
}
