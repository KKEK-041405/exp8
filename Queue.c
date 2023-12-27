#include <stdlib.h>
#include <stdio.h>
#include<stdio.h>
struct node{
int data;
struct node *next;
};
struct node*front=NULL;
struct node*rear=NULL;
int l=0;
struct node *createlist() {
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
return n;
}
void enqueue(int x){
struct node *ptr;
ptr=createlist();
ptr->data=x;
ptr->next=NULL;
if(ptr==NULL) {
printf("Queue is overflow.\n");
l++;
}
else if(rear==NULL){
front=ptr;
rear=ptr;
l=1;
}
else {
rear->next=ptr;
rear=ptr;
l++;
}
printf("Successfully inserted.\n");
}
void dequeue() {
struct node *t;
if(front==NULL)
{
printf("Queue is underflow.\n");
}
else
{
t=front;
printf("Deleted element = %d\n",t->data);
front=front->next;
free(t);
l--;
if(front==NULL)
{
rear=NULL;
}
}
}

void display() {
struct node *t;
if(front==NULL)
{
printf("Queue is empty.\n");
}
else {
t=front;
printf("Elements in the queue : ");
while(t!=NULL)
{
printf("%d ",t->data);
t=t->next;
}
printf("\n");
}
}
void size() {
printf("Queue size : %d\n",l);
}
void isEmpty() {
if(front==NULL) {
printf("Queue is empty.\n");
}
else {
printf("Queue is not empty.\n");
}
}






int main() {
int op, x;
while(1) {
printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
printf("Enter your option : ");
scanf("%d",&op);
switch(op) {
case 1:
printf("Enter element : ");
scanf("%d",&x);
enqueue(x);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
isEmpty();
break;
case 5:
size();
break;
case 6: exit(0);
}
}
}
