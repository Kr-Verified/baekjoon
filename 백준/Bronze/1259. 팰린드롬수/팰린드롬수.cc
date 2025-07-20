#include <stdio.h>
#include <string.h>

int main(void) {
  char nums[7];
  int answer, len=0;
  while (1) {
    scanf("%s", nums);
    if (strcmp(nums, "0") == 0) break;
    len = 0;
    while (nums[len] != '\0') len++;

    int check = 0;
    for (int i = 0; i < len/2; i++) {
      if (nums[i] != nums[len-i-1]) check = 1;
    }

    if (check == 0) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}