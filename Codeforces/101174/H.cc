#include <cctype>
#include <cstdio>
#include <type_traits>

template <typename T>
constexpr bool is_integral_v = std::is_integral<T>::value;

template <typename T, typename = std::enable_if_t<is_integral_v<T>>>
T get() {
    char c; while (!isdigit(c = getchar()) && c != '-');
    bool neg = c == '-'; T r = neg ? 0 : c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return neg ? -r : r;
}

template <typename T, typename = std::enable_if_t<is_integral_v<T>>>
void putint(T x) {
    static char buf[sizeof(T) << 2];
    static std::size_t len = 0;
    if (x < 0) putchar('-'), x = -x;
    do buf[len++] = x % 10; while (x /= 10);
    while (--len) putchar(buf[len] + '0');
    putchar(*buf + '0');
}

#include <cstdint>
#include <set>
using namespace std;

uint64_t D, N;
uint64_t C[35][35];
uint64_t stack[35], top = 1;
set<uint64_t> answer;

void dfs(uint64_t sum) {
    if (top == D) {
        uint64_t val = C[N][N - sum];
        for (uint64_t i = 1; i <= top; ++i)
            val *= C[sum][stack[i]], sum -= stack[i];
        answer.insert(val);
        return;
    }
    for (uint64_t i = stack[top - 1]; i + sum <= N; ++i)
        stack[top++] = i, dfs(sum + i), stack[--top] = 0;
}

int main() {
    for (uint64_t i = 0; i <= 32; ++i) C[i][0] = 1;
    for (uint64_t i = 1; i <= 32; ++i)
        for (uint64_t j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    D = get<uint64_t>(); N = get<uint64_t>() - 1;
    dfs(0);
    for (auto &val: answer)
        putint(val), putchar('\n');
    return 0;
}
