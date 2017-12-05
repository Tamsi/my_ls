/*
** EPITECH PROJECT, 2017
** my_swap_functions
** File description:
** functions for the sort algorithm
*/

#include "my.h"

static void assign_values(infos_t *info, files_t *temp)
{
	temp->date = info->date;
	temp->links = info->links;
	temp->name = info->name;
	temp->size = info->size;
	temp->perm = info->perm;
	temp->group = info->group;
	temp->user = info->user;
	temp->path = info->path;
}

static void assign_values_files(files_t *temp1, files_t *temp2)
{
	temp2->data = temp1->data;
	temp2->date = temp1->date;
	temp2->links = temp1->links;
	temp2->name = temp1->name;
	temp2->size = temp1->size;
	temp2->perm = temp1->perm;
	temp2->group = temp1->group;
	temp2->user = temp1->user;
	temp2->path = temp1->path;
}

static void assign_values_info(files_t *temp, infos_t *info)
{
	info->date = temp->date;
	info->links = temp->links;
	info->name = temp->name;
	info->size = temp->size;
	info->perm = temp->perm;
	info->group = temp->group;
	info->user = temp->user;
	info->path = temp->path;
}

int get_cond(int reverse, int min, int data)
{
	int cond;

	if (reverse)
 		cond = (min > data);
 	else
 		cond = (min < data);
 	return (cond);
}

void sort_list(files_t *la, int reverse)
{
	files_t *temp;
	files_t *temp1;
	files_t *temp3;
	infos_t *info = malloc(sizeof(infos_t));
	int min;

	for(temp=la ; temp!=NULL ; temp=temp->next) {
		temp3 = temp;
		min = temp->data;
		assign_values_info(temp, info);
		for(temp1 = temp->next; temp1 != NULL; temp1 = temp1->next)
			if (get_cond(reverse, min, temp1->data)) {
				temp3 = temp1;
				min = temp3->data;
				assign_values_info(temp3, info);
			}
		assign_values_files(temp, temp3);
		temp->data = min;
		assign_values(info, temp);
	}
}
