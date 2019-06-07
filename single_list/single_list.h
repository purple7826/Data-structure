#include<stdbool.h>

#define MAX_NAME_LEN 20
#define LIST_HEAD_DATA -520


struct std_list{
	int data;
	struct std_list *next;
};

void init();
void add_obj_head(struct std_list*,int);
void add_obj_tail(struct std_list *,int);
void del_obj(struct std_list*,int);
bool check_obj(struct std_list*,int);
int cal_list_size(struct std_list *);
void modify_obj(struct std_list*,int,int);
void printf_list_from_head(struct std_list*);
struct std_list * move_to_tail(struct std_list *);
struct std_list * allocNode();
void freeAllNode(struct std_list *);