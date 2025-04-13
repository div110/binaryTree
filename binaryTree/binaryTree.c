#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct node {
  int32_t value;
  struct node * leftChild;
  struct node * rightChild;
};

void insert(int newValue, struct node * rootNode){
  
  bool end = false;
  struct node * currentNode=rootNode;
  
  while (end==false){
  
    if(newValue<=currentNode->value){

      if(currentNode->leftChild==NULL){
        struct node * newNode=(struct node *)malloc(sizeof(struct node));
        newNode->value=newValue;
        currentNode->leftChild=newNode;
        end=true;
      }
      else if(currentNode->leftChild!=NULL){currentNode=currentNode->leftChild;}
    }
    
    else {
    if(newValue>currentNode->value){
        if(currentNode->rightChild!=NULL){
          currentNode=currentNode->rightChild;
        }
        else if(currentNode->rightChild==NULL){
          struct node * newNode=(struct node *)malloc(sizeof(struct node));
          newNode->value=newValue;
          currentNode->rightChild=newNode;
          end=true;
        }
      }

    }
  }

}

int main(){
struct node * rootNode=(struct node *)malloc(sizeof(struct node));
//struct node rootNode;
  rootNode->value = 8;
  rootNode->leftChild=NULL;
  rootNode->rightChild=NULL;
  
  insert(0,rootNode);
  insert(5,rootNode);
  printf("%d\n",rootNode->value);
  printf("%d\n",rootNode->leftChild->value);
  printf("%d\n",rootNode->leftChild->rightChild->value);





  return 0;
}
