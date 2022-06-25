#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Process: Each process has a name and has an execution time.
 *          We keep track of how long the process still needs
 *          to run on the processor. "remaining_time" is the
 *          remaining execution time of the process.
 * Item: An item that is being enqueued to or dequeued from the queue
 *       It is a pointer to the process
 */
typedef struct {
	char *name;
	int remaining_time;
} Process, *Item;
/*
 *
 */
typedef struct Node {
	Item data;
	struct Node* next;
} Node;
/*
 *
 */
typedef struct {
	Node* head;
	Node* tail;
} Queue;
/*
 *
 */
void init(Queue *q) {
	q->head=NULL;
	q->tail=NULL;
}
/*
 *
 */
int isEmpty(Queue *q) {
	if(q->head==q->tail==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }

}
/*
 *
 */
Item dequeue(Queue *q) {
    if(!isEmpty(q))
    {
        Item item=q->head->data;
	//free head?
	q->head=q->head->next;
	printf("dequeue\n");
	return item;
    }
    else
    {
        q->head=NULL;
        q->tail=NULL;
    }

}
/*
 *
 */
void enqueue(Queue *q, Item val) {
	Node* newNode=malloc(sizeof(Node));
	printf("head=%x",q->head);
	printf("tail=%x\n",q->tail);
	if(q->head==NULL)
    {
        newNode->next==NULL;
        newNode->data=val;
        q->head=q->tail=newNode;
        printf("enqueue 1\n");

    }
    else
    {
        newNode->data=val;
        newNode->next=NULL;
        q->tail->next=newNode;
        q->tail=newNode;
        printf("enqueue 2\n");
    }
}
/*
 *
 */
void destroy(Queue *q) {
	free(q);
}
/*
 * RoundRobin Scheduling
 */
 void testQueue()
 {
    Queue *q;
	init(q);

 }
void RoundRobin(char* filename)
{
	Queue q;
	init(&q);

	Item item=malloc(sizeof(Process));
	item->name=malloc(sizeof(char));
	Item m=malloc(sizeof(Process));
    int realt=0;
    int arrival;


	FILE* f=fopen(filename,"r");
	while(!feof(f))
    {

      m->name=malloc(sizeof(char));
      fscanf(f,"%s %d %d",m->name,&arrival,&m->remaining_time);
        printf("Process Name: %s     Remaining time: %d\n",m->name,m->remaining_time);
      if(realt==arrival)
      {

        enqueue(&q,m);
        printf("Queue head=%s\n",q.head->data->name);
        printf("Queue tail=%s\n",q.tail->data->name);
      }
      else
      {
         while(arrival>=realt||!isEmpty(&q))
         {
             if(isEmpty(&q))
             {

                 printf("idle(%d-->%d)\n",realt++,realt);
                 if(arrival==realt)
                 {
                     enqueue(&q,m);
                     printf("Queue head=%s\n",q.head->data->name);
                        printf("Queue tail=%s\n",q.tail->data->name);
                 }
             }
             else
             {printf("ELSE");

                 item=dequeue(&q);
                 item->remaining_time--;
                 printf("%s(%d-->%d)\n",item->name,realt++,realt);
                 if(item->remaining_time==0)
                    printf("%s halts\n",item->name,realt++,realt);
                 else
                 {
                     if(arrival==realt)
                     {
                         enqueue(&q,m);
                         printf("Queue head=%s\n",q.head->data->name);
                        printf("Queue tail=%s\n",q.tail->data->name);
                     }
                     enqueue(&q,item);
                     printf("Queue head=%s\n",q.head->data->name);
                        printf("Queue tail=%s\n",q.tail->data->name);
                 }
             }
         }
      }
    }





}
/*
 *
 */
 int main()
 {
     RoundRobin("processes.txt");
     return 0;
 }
/*int main(int argc, char**argv) {
	if(argc!=2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}

	RoundRobin(argv[1]);

	return 0;
}*/
