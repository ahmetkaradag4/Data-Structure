#include <stdio.h>
#include <stdlib.h>

// linked list

struct node{
	int data;
	struct node *next;
	
};

// Head & Tail
struct node *head = NULL;
struct node *tail = NULL;

// Add Node to TAIL
int addNode(int veri){
	if(head == NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = veri;
		temp->next = NULL;
		
		head = tail = temp;
	}
	else{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = veri;
		temp->next = NULL;
		
		tail->next = temp;		

		tail = temp;
	}
	

}


// Add Node to HEAD	
int addNodeHead(int veri){
	if(head == NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = veri;
		temp->next = NULL;
		
		head = tail = temp;
	}
	else{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		
		temp->data = veri;
		temp->next = head;
		
		head = temp;
	}
	

}
        
// EKRANA YAZDIR
int print(){
	struct node *index = head;
	while(index != NULL){
		printf("%d - ", index->data);
		index = index->next;
	}
	
	return 1;
}

// DELETE NODE
int deletee(int veri){
	
	struct node *prev = NULL;
	struct node *index = head;
	
	// Linked list is empty
	if(head == NULL){
		printf("Linked list is empty..");
		
		return 1;
	}
	
	// HEAD
	if(head->data == veri){
		struct node *t = head;
		head = head->next;
		free(t);
		return 1;
	}
	
	// 3. durum
	while(index != NULL && index->data != veri){
		prev = index;
		index = index->next;
	}
	if(index==NULL){
		printf("Data not found..");
		return 1;
	}
	
	prev->next = index->next;
	
	if(tail->data == veri){     // silnecek eleman tail ise (son eleman) ise tail prev'e esit olur.
		tail = prev;
	}
	
	
	return 1;
}


int main(){
	
	addNode(10);
	addNode(23);
	addNode(34);
	addNode(56);
	addNode(1000);
	
    addNodeHead(2222);	
	
	deletee(10);
	deletee(1000);
	deletee(2222);
	print();
	
	
	return 1;
}