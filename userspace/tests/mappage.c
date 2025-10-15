#include "nonstd.h"
#include "stdio.h"
#include "string.h"

const char src[] = "LosOktoberfest";

int main() {
    unsigned long vpn = 123;
    mapPage(vpn);
    unsigned long addr = vpn * 4096;
    char *str = (char*) addr;
    *str = 123;
    mapPage(124);
    str[4097] = 21;

    printf("String: %d, %d\n", *str, str[4097]);
    return 0;
}

// Userspace:
// - Added function declaration to userspace/libc/include/nonstd.h
// - Added function definition to userspace/libc/src/nonstd.c

// Kernel:
// - Added syscall number to common/include/kernel/syscall-definitions.h
// - Added vpn attribute to Loader class in common/include/kernel/Loader.h
// - Added mappage method to Syscall class in common/include/kernel/Syscall.h
// - Implemented Syscall::mapPage in common/source/kernel/Syscall.cpp
// - Added syscall handler in common/source/kernel/Syscall.cpp
// - Implemented page mapping in common/source/mm/PageFaultHandler.cpp
// -> Modified the PageFaultHandler::handlePageFault (line 46) function to handle page mapping