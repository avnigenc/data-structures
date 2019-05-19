#include <stdlib.h>
#include <stdio.h>

struct QNode
{
	int key;
	struct QNode *next;
};

struct Queue
{
	struct QNode *front, *rear;
};

struct QNode* newNode(int k)
{
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void enQueue(struct Queue *q, int k)
{
	struct QNode *temp = newNode(k);

	// If queue is empty, then new node is front and rear both
	if (q -> rear == NULL){
		q -> front = q -> rear = temp;
		printf("%d eklendi \n", temp -> key);

		return;
	}
	printf("%d eklendi \n", temp -> key);

	// Add the new node at the end of queue and change rear
	q -> rear -> next = temp;
	q -> rear = temp;

}

struct QNode *deQueue(struct Queue *q)
{
	// If queue is empty, return NULL.
	if (q->front == NULL)
		return NULL;


	// Store previous front and move front one node ahead
	struct QNode *temp = q->front;

	q->front = q->front->next;

	// If front becomes NULL, then change rear also as NULL
	if (q->front == NULL)
		q->rear = NULL;

	printf("%d çıkartıldı\n", temp -> key);
	return temp;
}

/*
int main()
{
	struct Queue *q = createQueue();

	enQueue(q, 20);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);

	deQueue(q);
	deQueue(q);
	deQueue(q);

	return 0;
}
*/
