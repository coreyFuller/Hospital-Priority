#include "pq.h"

int main(int argc , char * argv[])
{
  head = NULL;
  tail = NULL;
  heads = init(heads, 5);
  tails = init(tails, 5);
  FILE * ptr = fopen("input.txt", "r");
  if(ptr == NULL)
  {
    printf("Error opening file.\n");
    return -1;
  }
  read_in(ptr);
  push(5, "Jones");
  print();
  pop();
  pop();
  pop();
  pop();
  pop();
  print();
  pop();
  pop();
  pop();
  pop();
  print();
  pop();
  pop();
  pop();
  pop();
  print();
  return 0;
}
