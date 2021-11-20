#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
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
	while(p != NULL){
	
		printf("%d ->", p->data);
		p = p->link;
	

	
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
int main(){
 ListNode *list=NULL;
 ListNode *temp;//head������
 ListNode *temp2;
  
 	insert_node(&list,NULL,create_node(10,NULL));
	insert_node(&list,NULL,create_node(20,NULL)); 
	insert_node(&list,NULL,create_node(30,NULL)); 
	insert_node(&list,NULL,create_node(40,NULL)); 
	insert_node(&list,NULL,create_node(50,NULL));  
	insert_node(&list,NULL,create_node(60,NULL));
	
	
display(list);

temp=list;
temp=temp->link;
temp2=temp->link->link;

remove_node(&list,list->link,temp2);
  
  
 display(list);
	return 0;
}

