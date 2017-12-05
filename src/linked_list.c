/*
** EPITECH PROJECT, 2017
** push_in_list
** File description:
** push element in list
*/

#include "my.h"

files_t	*new_elem()
{
	files_t *newElem = malloc(sizeof(files_t));

	newElem->next = NULL;
	return (newElem);
}

files_t *append(files_t *list, files_t *elem)
{
	files_t *tmp = list;

	if (list == NULL)
		return (elem);
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = elem;
	return (list);
}

files_t  *push_in_list(files_t *list, int nb)
{
	files_t  *tmp;

	if ((tmp = malloc(sizeof(files_t))) == NULL)
		return (NULL);
	tmp->data = nb;
	tmp->next = list;
	list = tmp;
	return (list);
}
