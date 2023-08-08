#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {     /* power of two? */
        return sz + (-sz & mask);  // MMMM
    }
    return (((sz + mask) / alignment) * alignment);
}

int main()
{
    printf("%d %ld\n", 123, align_up(123, 4));
    printf("%d %ld\n", 122, align_up(122, 4));
    printf("%d %ld\n", 121, align_up(121, 4));
    printf("%d %ld\n", 120, align_up(120, 4));
}