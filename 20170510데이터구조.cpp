#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
	
}ListNode; 

void error(char *message){
	
}   
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
	if (*phead==NULL){//공백 리스트 일경우 
		new_node->link=NULL;// 왜? 선행노드가(공백리스트 ) 없으므로 link 값은 없음
		*phead=new_node; 
	}
	else if(p==NULL){
		new_node->link=*phead;
		*phead=new_node;
	}
	else{
		new_node->link=p->link;
		p->link=new_node;
		
	}
}

ListNode *create_node(element data, ListNode *link){
	ListNode *new_node;
	//new_node =(ListNode *)malloc(sizeof(ListNode));
	//if(new_node==NULL){
	//	error("메모리 할당 에러");
		
	//}
	new_node->data=data;
	new_node->link=link;

		printf("%u %u",new_node->data,new_node->link);	return(new_node);
}
int main(){
	ListNode *list1=NULL, *list2=NULL;
	//ListNode *tmp
	ListNode *p;
	create_node(10,NULL);
	
	
	
	
	
}
