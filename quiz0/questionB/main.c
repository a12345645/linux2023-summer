#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {  /* power of two? */
        return sz + (~sz & mask) + 1;       
    }
    return (((sz + mask) / alignment) * alignment);
}

int main () {
    printf("%d %ld",121, align_up(121, 4));
}