#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

void dump(void *ptr, int size, int gas) {
  char *p = (char *)ptr;
  for (int i = 0; i < size; i++) {
    if (i % 16 == 0) {
      if (!gas) {
        printf("\n%02x: ", i);
      } else {
        printf("\n.byte ");
      }
    }

    if (i % 16 == 15) {
      printf("0x%02x ", *(p + i) & 0xff);
    } else {
      printf("0x%02x, ", *(p + i) & 0xff);
    }
  }
  printf("\n");
}

int main() {
  fd_set *fds;
  struct timeval tv;

  fds = calloc(1, sizeof(fd_set));
  FD_SET(1, fds);
  dump(fds, sizeof(fd_set), 1);
  /*    00: 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */
  /*    70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  */

  tv.tv_sec = 0;
  tv.tv_usec = 10000;
  dump(&tv, sizeof(struct timeval), 1);
  // 00: 00 00 00 00 00 00 00 00 10 27 00 00 01 00 00 00

  // call select on FD=1 with timeout value (non blocking)
  int res = select(2, fds, 0, 0, &tv);

  char esc[] = {27, '['};
  char up[] = {'3', 'A'};
  write(1, esc, 2);
  write(1, up, 2);

  return 0;
}

