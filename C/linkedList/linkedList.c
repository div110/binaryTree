#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node{
  int value;
  struct node * nextNode;
};

void insert(struct node * currentNode, int64_t value){
  while(currentNode->nextNode != NULL){
    currentNode = currentNode->nextNode;
  }
  currentNode->nextNode = (struct node *)malloc(sizeof(struct node *));
  currentNode->nextNode->value = value;
}

void printList(struct node * head){
  printf("%i",head->value);
  if(head->nextNode!=NULL){
    printf("->");
    printList(head->nextNode);

}
}

int main(){
  struct node * head;
  head = (struct node *)malloc(sizeof(struct node));
  if (head == NULL){
    printf("failed to allocate memory\n");
  }
  insert(head,3);
  insert(head,54023);
  insert(head,123);
  insert(head,6);
  insert(head,9438520);
  insert(head,14325);
  insert(head,342);
  insert(head,0);
  insert(head,3425800);
  insert(head,431);
  insert(head,67);
  insert(head,23634);

  printList(head);
  printf("\n");
  return 0;
}
