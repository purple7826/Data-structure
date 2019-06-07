#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

int main(int argc,char *argv[]){
	struct std_list *list;
	list = allocNode();
	init(list);

	add_obj_head(list,11);
	add_obj_head(list,12);
	add_obj_head(list,13);
	add_obj_head(list,14);
	add_obj_head(list,15);
	add_obj_head(list,16);
	add_obj_head(list,17);
	add_obj_head(list,18);
	add_obj_head(list,19);

	add_obj_tail(list,20);
	add_obj_tail(list,21);
	add_obj_tail(list,22);
	add_obj_tail(list,23);
	add_obj_tail(list,24);
	add_obj_tail(list,25);
	add_obj_tail(list,26);

	printf_list_from_head(list);
	//delete obj 23
	//del_obj(list,23);
	//printf_list_from_head(list);

	//check if 25 in list
	printf("------- >  25 is in list ? %s\n",((check_obj(list,25) == 1)? "Yes":"No"));

	//change 25 to 255
	modify_obj(list,25,255);


	//printf("\n=============================================================\n");
	printf("Current list size is %d.\n",cal_list_size(list));




	freeAllNode(list);
	return 0;
}