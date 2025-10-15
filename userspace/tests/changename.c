#include "nonstd.h"
#include "stdio.h"

int main() {
    char name[512] = "testname";
    char buffer[1024];
    changename(name);
    int result = currentprocess(buffer, 1024);
    if (result == 0) {
        printf("Process name: %s\n", buffer);
        return 0;
    }
}

// Userspace:
// - Added changename and currentprocess function declarations to userspace/libc/include/nonstd.h
// - Implemented changename and currentprocess functions in userspace/libc/src/nonstd.c

// Kernel:
// - Added changename and currentprocess syscall definitions to common/include/kernel/syscall-definitions.h
// - Declared changename and currentprocess functions in common/include/kernel/Syscall.h
// - Implemented changename and currentprocess functions in common/source/kernel/Syscall.cpp
// - Made name of Thread public instead of private in common/include/kernel/Thread.h
// - Updated Thread constructor initialization list in common/source/kernel/Thread.cpp