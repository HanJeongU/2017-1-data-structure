#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;
	//��带 �������� �����ϴ� ���α׷�
	ListNode *create_node(element data, ListNode *link){
		ListNode *new_node;
		new_node = (ListNode *)malloc(sizeof(ListNode));
		
		//if(new_node==NULL){
		//	error("�޸� �Ҵ� ����");
		//}
		
		new_node->data=data;
		new_node->link=link;
		printf("%d, %d \n",new_node->data,new_node->link);
	//	printf("%u\n",new_node);
		return(new_node);
	}
	 
	//�ݺ����� �湮����
void display(ListNode *head){
	ListNode *p=head;
	while(p != NULL){
		printf("%d ->", p->data);
		p = p->link;
	}
	printf("\n");
}

//��� ���� 
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
	if(*phead == NULL){		//���鸮��Ʈ�� ��� 
		new_node->link = NULL;
		*phead = new_node;
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

int main(){
	ListNode *list=NULL;
	ListNode *temp;

	insert_node(&list,NULL,create_node(1,NULL)); 
	insert_node(&list,NULL,create_node(2,NULL));
	insert_node(&list,NULL,create_node(3,NULL));
	insert_node(&list,NULL,create_node(4,NULL));
	insert_node(&list,NULL,create_node(5,NULL));
	
	temp =list;
	while(temp != NULL){
	printf("%d->",temp->data);
		temp = temp->link;
	
	}
	//printf("%d->",temp->link=);
	
	
	
	
}
