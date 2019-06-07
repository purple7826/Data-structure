#include "double_list.h"

int main(int argc,char *argv[]){
	std_list_t *list = alloc_node();
	init(list);


	printf("--------------- add head ---------------\n");
	add_obj_head(list,10);
	add_obj_head(list,11);
	add_obj_head(list,12);
	add_obj_head(list,13);
	add_obj_head(list,14);
	add_obj_head(list,15);


	printf("--------------- add tail ---------------\n");

	add_obj_tail(list,20);
	add_obj_tail(list,21);
	add_obj_tail(list,22);
	add_obj_tail(list,23);
	add_obj_tail(list,24);
	add_obj_tail(list,25);

	printf_from_head(list);

/*
	//printf("--------------- del obj ---------------\n");
	//del_obj(list,15);
	//printf_from_head(list);

	printf("--------------- check obj ---------------\n");
	printf("15 in list : %s\n",((check_obj(list,15) == true)? "Yes":"NO"));
	printf("25 in list : %s\n",((check_obj(list,25) == true)? "Yes":"NO"));
	printf("30 in list : %s\n",((check_obj(list,30) == true)? "Yes":"NO"));


	printf("--------------- modify obj ---------------\n");
	modify_obj(list,30,255);

	printf_from_head(list);

	printf("--------------- cal size ---------------\n");
	printf("list size is : %d.\n",cal_size(list));
*/

	printf_from_tail(list);

	free_all_node(list);
	return 0;
}