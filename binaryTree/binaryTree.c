#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct node {
  int32_t value;
  struct node * leftChild;
  struct node * rightChild;
};

void insert(int32_t newValue, struct node * rootNode){
  
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
void delete(int32_t deleteValue,struct * node rootNode){
  struct * node previousNode = NULL;
  struct * node currentNode = rootNode;
  
  if(currentNode->value == deleteValue){
    
    if(currentNode->leftChild!=NULL && currentNode->rightChild!=NULL){
      currentNo 
    }
    else if (currentNode->leftChild != NULL || currentNode->rightChild != NULL){

    }
    else if (currentNode->leftChild == NULL && currentNode->rightChild == NULL){
      if(previousNode->leftChild == currentNode){previousNode->leftChild = NULL;}
      else if(previousNode->rightChild == currentNode){previousNode->rightChild = NULL;}
      free(currentNode);
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
