#ifndef ORDER_H
#define ORDER_H

typedef struct node{
    struct node* nextPtr;
    int order_number;
    int qty;
}order;


typedef struct node* NodePtr;

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}QueueOrder;

void enqueue_order(QueueOrder* q, int ord,int qt){
    order *new_node=(order*) malloc(sizeof(order));
    if(new_node){ 
    new_node->order_number = ord;
    new_node->qty = qt;
    new_node->nextPtr = NULL;

    if(q->size==0) q->headPtr = new_node;
    else q->tailPtr->nextPtr = new_node;

    q->tailPtr = new_node;
    q->size++;
    }
}


void dequeue_order(QueueOrder *q){
   NodePtr t = q->headPtr;
   if(t){
   
    q->headPtr = t->nextPtr;
    if(q->size==0) q->tailPtr = NULL;

    free(t);
    q->size--;

   }
   else printf("The queue is empty queue\n");
}

int Order(QueueOrder* q,int customer_no)
{
    int order,amount,cost,price,total = 0;

    while(q->size!=0){
        order = q->headPtr->order_number;
        amount = q->headPtr->qty;
    
        if(order > 3 || order < 1 || amount<=0){
            printf("No Food\n");
            dequeue_order(q);
            continue;
        }
        printf("Customer No.%d\n",customer_no);
        printf("My order is : %d\n",order);
        printf("Quantity : %d\n",amount);

        switch(order){
            case 1 : price = 100; break;
            case 2 : price = 20; break;
            case 3 : price = 50; break;
            default : break;
        }
        cost = price*amount;
        total = total + cost;
        dequeue_order(q);
    }

    return total;
    
}

int Bill(int total){
    int pay;
    printf("You have to pay: %d\n",total);
    do{
        printf("Cash : ");
        scanf("%d",&pay);
        if(pay > total) printf("Change : %d\n",pay - total);
    }while(pay<total);
    printf("Thank you\n");
    printf("\n");
}

#endif
