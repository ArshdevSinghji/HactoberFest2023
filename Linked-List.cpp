#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};struct node *first=NULL;struct node *second=NULL;struct node *third=NULL;

void create1(int A[],int n){
	int i;
	struct node *t,*last;
	first=(struct node *)malloc(sizeof(struct node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
	
}
void create2(int A[],int n){
	int i;
	struct node *t,*last;
	second=(struct node *)malloc(sizeof(struct node));
	second->data=A[0];
	second->next=NULL;
	last=second;
	
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
	
}

void display(struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

int count(struct node *p){
	int c=0;
	while(p){
		c++;
		p=p->next;
	}
	return c;
}

int add(struct node *p){
	int sum=0;
	while(p){
		sum+=p->data;
		p=p->next;
	}
	return sum;
}

node* search(struct node *p,int key){
	while(p){
		if (p->data==key)
			return p;
		p=p->next;
	} return NULL;
}

void insert(struct node *p,int pos,int x){
	node *temp=new node;
	temp->data=x;
	if(pos==0){
		temp->next=first;
		first=temp;
	} else if(pos>0){
		p=first;
		for(int i=0;i<pos-1;i++){
			p=p->next;
		} 
		temp->next=p->next;
		p->next=temp;
	}
}

int Sinsert(struct node *p,int x){
	p=first;
	node *q=NULL;
	while(p && p->data<x){
		q=p;
		p=p->next;
	}
	node *t=new node;
	t->data=x;
	t->next=q->next;
	q->next=t;
}

int Delete(struct node *p,int pos){
	int x;
	node *q=NULL;
	for(int i=0;i<pos-1;i++){
		q=p;
		p=p->next;
	}
	q->next=p->next;
	x=p->data;
	delete p;
	
}

int sorted(struct node*p){
	int x=-65565;
	while(p){
		if(p->data<x)
			return 0;
		x=p->data;
		p=p->next;
	}return 1;
}
/*
int sorted(struct node*p){
	node *q=NULL;
	q=p
	p=p->next;
	while(p){
		if(q->data>p->data)
			return 0;
		q=p;
		p=p->next;
	}return 1;
}
*/

void duplicate(struct node *p){
	node *q=p->next;
	while(q){
		if (p->data!=q->data){
			p=q;
			q=q->next;
		}else{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}

void reverse(struct node *p){
	node *q=NULL;
	node *r=NULL;
	while(q){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

void concatenate(struct node *p,struct node *q){
	third=p;
	while(p->next!=NULL){
		p=p->next;
	}p->next=second;
	second=NULL;
}

void merge(struct node *first,struct node *second){
	node *last=NULL;
	
		if(first->data<second->data){
			third=last=first;
			first=first->next;
			third->next=NULL;
		}else{
			third=last=second;
			second=second->next;
			third->next=NULL;
		}
		
	while(first && second){
		if (first->data<second->data){
			last->next=first;
			last=first;
			first=first->next;
			last->next=NULL;
		} else{
			last->next=second;
			last=second;
			second=second->next;
			last->next=NULL;
		}
	}if(first)
		last->next=first;
	if(second)
		last->next=second;
	
}

int main(){
	int A[]={2,9,6,8};
	create1(A,4);
	int B[]={10,4,7};
	create2(B,3);
	//insert(first,3,8);
	//Sinsert(first,14);
	//concatenate(first,second);
	merge(first,second);
	//display(third);
	//printf("\n");
	//cout<<"Is sorted? "<<sorted(first)<<endl;
	//Delete(first,4);
	//duplicate(first);
	reverse(first);
	cout<<"New: ";
	display(first);
	//printf("\n");
	//cout<<"Length is "<<count(first)<<endl;
	//cout<<"Sum: "<<add(first)<<endl;
	//cout<<"Key is at: "<<search(first,10);
}
