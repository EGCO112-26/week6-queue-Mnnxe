#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Order.h"

int main(int argc, char** argv)
{
    NodePtr headPtr=NULL;
    NodePtr tailPtr=NULL;

    QueueOrder  q;
    q.headPtr=NULL;
    q.tailPtr=NULL;
    q.size=0;

    
    printf("\tMenu\n1.Ramen 100\n2.Somtum 20\n3.Fried Chicken 50\n");
    printf("\n");
        
    int i,j=1;
    int total,count=0,left;
    //main func
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0)
        {
            total = Order(&q,j);
            if(total != 0) Bill(total);
            j++;
        }
        else {
            enqueue_order(&q,atoi(argv[i]),atoi(argv[i+1]));
            i++;
        }
    }
    printf("===============================\n");
    //check queue
    for(i=argc-1;i>0;i--){
        if(strcmp(argv[i],"x")==0) break;
        else count++;
    }
    left = count / 2;
    if(left==0) printf("The queue is empty.\n");
    else printf("There are %d order left in the queue.\n",left);
    return 0;
}