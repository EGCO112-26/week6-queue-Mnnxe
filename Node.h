//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2566 BE.
//
#ifndef Node_h
#define Node_h

struct node
{
    int data;
    struct node *nextPtr;
};

typedef struct node Node;
typedef struct node* NodePtr;


void enqueue(NodePtr * head, NodePtr* tail, int x){
  Node* new_node=(NodePtr) malloc(sizeof(Node));
if(new_node){
  /*Fill data*/
    new_node->data = x;
    new_node->nextPtr = NULL;
  /*Finish queue*/

  if((*head)==NULL){
    *head = new_node;
  }
  else{
    (*tail)->nextPtr = new_node;
  }
  *tail = new_node;
 }
}


int dequeue(NodePtr* head, NodePtr* tail){
  NodePtr t=*head;
   if(t){
   int value= t->data;
   //normal case
     *head = t->nextPtr;
    //last node
    if((*head)==NULL) *tail = NULL;

    free(t);

    /* Finish dequeue*/
   return value;
   }
   printf("Empty queue\n");
   return 0;
}



#endif
