#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  char *s = malloc(5);
  free(s);
}
