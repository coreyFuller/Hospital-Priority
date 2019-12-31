#include "pq.h"

void read_in(FILE * ptr)
{
  size = 0;
  char * l_name = (char*)malloc(sizeof(char) * 100); 
  int level = 0;
  while(fscanf(ptr, "%s\n" , l_name) == 1)
  {
    fscanf(ptr, "%d", &level);
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->level = level;
    newNode->next = newNode->prev = NULL;
    strcpy(newNode->l_name, l_name);
    if(heads[level -1] == NULL){
    newNode->next = heads[level -1];
    heads[level - 1] = newNode;
    tails[level -1]  = newNode;
    size++;
    continue;
    }   
    else {
      newNode->prev = tails[level-1];
      tails[level -1] = newNode;
      newNode->prev->next = newNode;
      size++;
    }
  }
}

void push(int level, char *l_name)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->level = level;
  newNode->next = newNode->prev = NULL;
  strcpy(newNode->l_name, l_name);

  if(heads[level -1] == NULL){
  newNode->next = heads[level-1];
  heads[level -1] = newNode;
  tails[level -1] = newNode;
  size++;
  return;
  }
  else {
     newNode->prev = tails[level-1];
      tails[level -1] = newNode;
      newNode->prev->next = newNode;
      size++;
      return;
    }
  }

void pop()
{
  if(heads[0] == NULL) {
    printf("All lists are empty. No patients left to serve.\n");
    return;
  }
  int index = 4;
  while(index >= 0){
    if(heads[index] != NULL){
    if(heads[index]->next == NULL){
      Node * temp = heads[index];
      heads[index] = heads[index]->next;
      tails[index] = heads[index];
      free(temp);
      size--;
      return;
    }
    else {
      Node * temp = heads[index];
      heads[index] = heads[index]->next;
      free(temp);
      size--;
      return;
    }
   }
    else{index--;}
  }
}

Node * top(Node * head)
{
  if(head == NULL) return NULL;
  else return head;
}

int q_size(){return size;}

void print()
{
  printf("Size of the queue: %d\n", q_size());
  for(int i = 0 ; i < 5; i++){
  if(heads[i] != NULL){
  for(Node * temp = heads[i]; temp != NULL; temp = temp->next){
    printf("%s %d\n" , temp->l_name, temp->level);
  }
  }
  printf("\n");
  }
  printf("\n");
}

Node ** init(Node ** ptr, int size)
{
  ptr = (Node**)malloc(sizeof(Node*) * size);
  for(int i = 0 ; i < size; i++) {
    ptr[i] = NULL;
  }
  return ptr;
}
