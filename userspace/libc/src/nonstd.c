#include "nonstd.h"
#include "sys/syscall.h"
#include "../../../common/include/kernel/syscall-definitions.h"

int createprocess(const char* path, int sleep)
{
  return __syscall(sc_createprocess, (long) path, sleep, 0x00, 0x00, 0x00);
}

extern int main();

void _start()
{
  exit(main());
}


int mapPage(unsigned long int vpn) {
  return __syscall(sc_mappage, (size_t)vpn, 0x00, 0x00, 0x00, 0x00);
}

int currentprocess(char *buffer, size_t size) {
  return __syscall(sc_currentprocess, (size_t)buffer, size, 0x00, 0x00, 0x00);
}

int changename(const char *name) {
  return __syscall(sc_changename, (size_t)name, 0x00, 0x00, 0x00, 0x00);
}