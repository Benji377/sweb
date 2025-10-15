#include "stdio.h"
#include "pthread.h"

int main(int argc, char *argv[]) {
  printf("Threadcount: %d", get_thread_count());
  return 0;
}

// Userspace:
// - Added function declaration to userspace/libc/include/pthread.h
// - Added syscall invocation to userspace/libc/src/pthread.c
// Don't forget to add the includes at the top of pthread.c:
// #include "sys/syscall.h"
// #include "../../../common/include/kernel/syscall-definitions.h"

// Kernel space:
// - Added syscall definition to common/include/kernel/syscall-definitions.h
// - Added syscall to switch case in common/source/kernel/Syscall.cpp
// - Added function declaration to common/include/kernel/Syscall.h
// - Added function definition to common/source/kernel/Syscall.cpp
//      - Which calls the scheduler function
// - Added function declaration to common/include/kernel/Scheduler.h
// - Added function definition to common/source/kernel/Scheduler.cpp
//      - Which returns the size of the threads_ vector
