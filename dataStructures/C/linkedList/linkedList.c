#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node{
  int32_t value;
  struct node * nextNode;
};

void insert(struct node * currentNode, int32_t value){
  while(currentNode->nextNode != NULL){
    currentNode = currentNode->nextNode;
  }
  currentNode->nextNode = (struct node *)malloc(sizeof(struct node *));
  currentNode->nextNode->value = value;
}

void printList(struct node * currentNode){
  printf("%d",currentNode->value);
  if(currentNode->nextNode!=NULL){
    printf("->");
    printList(currentNode->nextNode);

}
}

void deleteValue(struct node * currentNode,int32_t valueDelete){
  if(currentNode->nextNode->value == valueDelete){
    struct node * deleteNode = currentNode->nextNode;
    currentNode->nextNode = currentNode->nextNode->nextNode;
    free(deleteNode);
  }
  else{
    deleteValue(currentNode->nextNode,valueDelete);
  }
}
void deleteNode(struct node * currentNode, int32_t numberOfNode){
  struct node * previousNode = currentNode;
  currentNode = currentNode->nextNode;
  
  if(numberOfNode == 0){
    previousNode->nextNode = currentNode->nextNode;
    free(currentNode);
  }
  else{deleteNode(currentNode, numberOfNode-1);}
}

int main(){
  struct node * headNode;
  headNode = (struct node *)malloc(sizeof(struct node));
  if (headNode == NULL){
    printf("failed to allocate memory\n");
  }
  insert(headNode,3);
  insert(headNode,54023);
  insert(headNode,123);
  insert(headNode,6);
  insert(headNode,9438520);
  insert(headNode,14325);
  insert(headNode,342);
  insert(headNode,0);
  insert(headNode,3425800);
  insert(headNode,431);
  insert(headNode,67);
  insert(headNode,23634);


  printList(headNode);
  printf("\n");
  printf("beg\n");
  deleteValue(headNode,6);
  printf("end\n");
  printList(headNode);
  printf("\n");

  deleteValue(headNode,0);
  printList(headNode);

  return 0;
}
