#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

void display(ListNode *head){
	ListNode *p=head;
	while(p != NULL){
	
		printf("%d ->", p->data);
		p = p->link;
	

	}
	printf("\n");
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
	 
//��� ���� 
ListNode *node_which( ListNode *p, int num)     // ��� ��ġ Ž��

{
    int i;
    for( i=2; i<num; i++ ) {
        p = p->link;
    }
    return p;
}

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

void mid_node( ListNode **phead, ListNode *new_node, int num )    
{

//��� ���� ( ��� ������, ������ �� ���, ��� ������ ��ġ)

                       // �׿� ����
        ListNode *p = node_which( *phead, num);
        new_node->link = p->link;
        p->link = new_node;
    
}




int main(){
	ListNode *list=NULL;
	ListNode *temp;
 ListNode *temp2;
	insert_node(&list,NULL,create_node(1,NULL)); 
	insert_node(&list,NULL,create_node(2,NULL));
	insert_node(&list,NULL,create_node(3,NULL));
	insert_node(&list,NULL,create_node(4,NULL));
	insert_node(&list,NULL,create_node(5,NULL));
	mid_node(&list,create_node(6,NULL),5);
	temp =list;
  display(list);


	//printf("%d->",temp->link=);
	
temp=list;
temp=temp->link;
temp2=temp->link;

remove_node(&list,list->link,temp2);
   display(list);
  
	
	
	return 0;
}
