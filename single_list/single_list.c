#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "single_list.h"

void init(struct std_list *list){
	list->data = LIST_HEAD_DATA;
	list->next = NULL;
}


void add_obj_head(struct std_list *list,int val){
	printf("%s\n",__FUNCTION__);
	struct std_list *obj = allocNode();
	obj->data = val;
	obj->next = list->next;
	list->next = obj;
}

void add_obj_tail(struct std_list *list,int val){
	printf("%s\n",__FUNCTION__);
	struct std_list *temp = move_to_tail(list);	
	struct std_list *obj = allocNode();
	obj->data = val;
	obj->next = NULL;

	temp->next = obj;
}



void del_obj(struct std_list* list,int val){
	printf("%s : val : %d\n",__FUNCTION__,val);
	struct std_list *temp = list->next;
	struct std_list *prev_temp = list;
	
	while(val != temp->data){
		prev_temp = temp;
		temp = temp->next;
	}

	prev_temp->next = temp->next;
	free(temp);
	temp = prev_temp = NULL;
}


bool check_obj(struct std_list* list,int val){
	printf("%s : val : %d\n",__FUNCTION__,val);
	struct std_list *temp = list->next;
	
	while((temp != NULL) && (val != temp->data)) {
		temp = temp->next;
	}

	if((temp != NULL) && (val == temp->data)){
		return true;
	}

	return false;
}


void modify_obj(struct std_list* list,int old_val,int new_val){
	printf("%s :  new_val : %d , old_val : %d.\n",__FUNCTION__,new_val,old_val);
	struct std_list *temp = list->next;
	
	while((temp != NULL) && (old_val != temp->data)) {
		temp = temp->next;
	}

	if((temp != NULL) && (old_val == temp->data)){
		temp->data = new_val;
	}
}


void printf_list_from_head(struct std_list* list){
	printf("%s start.\n",__FUNCTION__);
	struct std_list *node = list->next;
	while(node != NULL){
		printf("current node : %d\n",node->data);
		node = node->next;
	}
	printf("%s end.\n",__FUNCTION__);
}



struct std_list * move_to_tail(struct std_list *list){
	printf("%s\n",__FUNCTION__);
	struct std_list *tail = list;
	while(tail->next != NULL){
		tail = tail->next;
	}

	return tail;
}


struct std_list *allocNode(){
	struct std_list *obj= (struct std_list *)malloc(sizeof(struct std_list));
	memset(obj,0,sizeof(struct std_list));
	return obj;
}

void freeAllNode(struct std_list *list){
	printf("%s start.\n",__FUNCTION__);
	struct std_list *node = list->next;
	while(node != NULL){
		if(node->next != NULL){
			list->next = node->next;
			printf("%s : 1 free data : %d.\n",__FUNCTION__,node->data);
			free(node);
			node = list->next;
		}else{
			printf("%s : 2 free data : %d.\n",__FUNCTION__,node->data);
			free(node);
			node = NULL;
			list->next = NULL;
		}
	}
	free(list);
	printf("%s end.\n",__FUNCTION__);
}

int cal_list_size(struct std_list *list){
	int size = 0;
	struct std_list *node = list->next;
	while(node != NULL){
		size++;
		node = node->next;
	}
	return size;
}