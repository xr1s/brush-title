#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char raw[1024]; fgets(raw, sizeof raw, stdin);
    const size_t len = strlen(raw);
    int sum = 0;
    for (size_t i = 0; i != len; ++i)
        if (raw[i] == 'x') {
            raw[i] = '\x00';
            for (int back = 0; back != 3; )
                if (raw[--i] != '\x00') ++back;
        } else if (isdigit(raw[i])) sum += raw[i] - '0';
    printf("%d\n", sum);
    return 0;
}
