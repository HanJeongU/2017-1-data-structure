#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;


void error(char *message){
	fprintf(stderr,"%s\n", message);
	exit(1);
}



void display(ListNode *head){
	ListNode *p=head;
	int i=1;
//	printf("%d���� ",i);
	while(p != NULL){
		
		printf("%d ->",p->data);
		p = p->link;
		i++;
	

	}
	printf("\n");
} 

ListNode *create_node(element data, ListNode *link){
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if(new_node == NULL){
		error("�޸� �Ҵ� ����");
	}
	new_node->data = data;
	new_node->link = link;
	//printf("%d, %d",new_node->data, new_node->link );
	return(new_node);
} 
//���� ����


void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
	if(*phead == NULL){		//���鸮��Ʈ�� ��� 
		new_node->link = NULL;
		*phead = new_node;
	//	printf("%d\n", phead);
	//	printf("%d\n", new_node);
	}
	else if(p == NULL){		//p�� NULL�̸� ù ��° ���� ���� 
		new_node->link = *phead;
		*phead = new_node;
	}
	else{					//p���� ���� 
		new_node->link = p->link;
		p->link =new_node;
	}
}


void remove_node(ListNode **phead, ListNode *p, ListNode *removed){
	if(p == NULL){
		*phead = (*phead)->link;
	}
	else{
	p->link = removed->link;
	}	
	free(removed);
}
ListNode *which(ListNode *temp){
	while(temp->link!=NULL){
		temp=temp->link;
	}
	return temp;
	
}
void change_node(ListNode **phead,ListNode *p, ListNode *changed){


	*phead=p->link;
	changed->link=p;
    p->link=NULL;
	


	
}

int main(){
 ListNode *list=NULL;
 ListNode *temp;//head������
 ListNode *temp2;
  int i;
 	insert_node(&list,NULL,create_node(10,NULL));
	insert_node(&list,NULL,create_node(20,NULL)); 
	insert_node(&list,NULL,create_node(30,NULL)); 
	insert_node(&list,NULL,create_node(40,NULL)); 
	insert_node(&list,NULL,create_node(50,NULL));  
	insert_node(&list,NULL,create_node(60,NULL));
	
	
display(list);
printf("\n\n\n\n\n");
	for(i=1; i<9; i++){
	printf("%d����",i);
	change_node(&list,list,which(list));
	display(list);
}
//temp2=temp->link;


//remove_node(&list,list->link,temp2);
return 0;
}
