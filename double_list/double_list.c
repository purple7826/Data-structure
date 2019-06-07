#include "double_list.h"

void init(std_list_t *list){
	list->data = DEFAULT_HEAD_DATA;
	list->prev = list->next = NULL;
}

void add_obj_head(std_list_t *list,int val){
	printf("%s\n", __FUNCTION__);
	std_list_t *node = alloc_node();
	if(node != NULL){
		node->data = val;

		node->next = list->next;
		node->prev = list;

		if(list->next != NULL){
			list->next->prev = node;
		}
		list->next = node;

	}
}

void add_obj_tail(std_list_t *list,int val){
	printf("%s\n", __FUNCTION__);

	std_list_t *node = alloc_node();
	if (node != NULL)
	{
		node->data = val;

		std_list_t *tail = move_to_tail(list);
		node->next = tail->next;
		node->prev = tail;

		tail->next = node;
	}
}

void del_obj(std_list_t *list,int val){
	printf("%s\n", __FUNCTION__);
	std_list_t *temp = list->next;
	while(temp != NULL){
		if(temp->data == val){
			temp->prev->next = temp->next;
			if(temp->next != NULL){
				temp->next->prev = temp->prev;
			}

			temp->next = temp->prev = NULL;
			free(temp);
			break;
		}else{
			temp = temp->next;
		}
	}
}


bool check_obj(std_list_t *list,int val){
	printf("%s\n", __FUNCTION__);
	std_list_t *temp = list->next;
	while(temp != NULL){
		if(temp->data == val){
			return true;
		}else{
			temp = temp->next;
		}
	}
	return false;
}


void modify_obj(std_list_t *list,int old_val,int new_val){
	printf("%s\n", __FUNCTION__);
	std_list_t *temp = list->next;
	if(check_obj(list,old_val) == false){
		printf("value : %d is not in list.\n",old_val);
		return;
	}

	while(temp != NULL){
		if(temp->data == old_val){
			temp->data = new_val;
			break;			
		}else{
			temp = temp->next;
		}
	}
}


int cal_size(std_list_t *list){
	printf("%s\n", __FUNCTION__);
	int size = 0;
	std_list_t *temp = list->next;
	while(temp != NULL){
		size++;
		temp = temp->next;
	}

	return size;
}


void printf_from_head(std_list_t *list){
	printf("%s\n", __FUNCTION__);
	std_list_t *temp = list->next;
	while(temp != NULL){
		printf("from head ,current data : %d.\n", temp->data);
		temp = temp->next;
	}
}

void printf_from_tail(std_list_t *list){
	printf("%s\n",__FUNCTION__);
	std_list_t *tail = move_to_tail(list);
	while(tail->data != DEFAULT_HEAD_DATA){
		printf("from tail , current data : %d.\n", tail->data);
		tail = tail->prev;
	}
}


void free_all_node(std_list_t *list){
	printf("%s start\n", __FUNCTION__);
	std_list_t *temp = list->next;
	while(temp != NULL){
		if(temp->next != NULL){
			list->next = temp->next;
			temp->next->prev = list;

			temp->next = temp->prev = NULL;
			printf("free node data :%d\n", temp->data);
			free(temp);
			temp = list->next;
		}else{
			printf("free last one node : %d.\n",temp->data);
			free(temp);
			temp = temp->next;
		}
	}

	free(list);
	printf("%s end.\n", __FUNCTION__);
}

std_list_t *move_to_tail(std_list_t *list){
	std_list_t *tail = list->next;
	while(tail->next != NULL){
		tail = tail->next;
	}

	printf("%s , tail datat : %d\n", __FUNCTION__,tail->data);
	return tail;
}

std_list_t *alloc_node(){
	std_list_t *node = (std_list_t *)malloc(sizeof(std_list_t));
	if (node == NULL)
	{
		printf("There is no enough memory.\n");
		return NULL;
	}

	memset(node,0,sizeof(std_list_t));
	return node;
}