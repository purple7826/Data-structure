#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define DEFAULT_HEAD_DATA 1111

struct std_list{
	int data;
	struct std_list *next;
	struct std_list *prev;
};

typedef struct std_list std_list_t;

void init(std_list_t *);
void add_obj_head(std_list_t *,int);
void add_obj_tail(std_list_t *,int);
void del_obj(std_list_t *,int);
bool check_obj(std_list_t *,int);
void modify_obj(std_list_t *,int,int);
int cal_size(std_list_t *);
void printf_from_head(std_list_t *);
void printf_from_tail(std_list_t *);
void free_all_node(std_list_t *);
std_list_t *move_to_tail(std_list_t *);
std_list_t *alloc_node();