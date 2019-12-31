#ifndef PQ_H
#define PQ_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  int level;
  char l_name[100];
  struct Node * next;
  struct Node * prev;
}Node;

Node ** heads;
Node ** tails; 
Node * head;
Node * tail;
int size;

Node ** init(Node **, int);
void read_in(FILE * ptr);
void pop();
void push(int level, char * l_name);
Node * top();
int q_size();
void print();

#endif 
