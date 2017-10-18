#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    int code = open("function.bin", O_RDONLY);
    int size = lseek(code, 0, SEEK_END);
    uint64_t (*func)() = mmap(NULL, size, PROT_EXEC, MAP_PRIVATE, code, 0);
    printf("%s\n", func());
    return 0;
}

