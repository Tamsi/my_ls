/*
** EPITECH PROJECT, 2017
** display
** File description:
** display ls
*/

#include "my.h"

command_t populate_commands(char *flags)
{
	command_t commands;

	commands.recursive = 0;
	commands.verbose = 0;
	commands.sorted = 0;
	commands.display_hidden = 0;
	commands.reverse = 0;
	for (int i = 0; flags[i]; i++) {
		if (flags[i] == 'l')
			commands.verbose = 1;
		if (flags[i] == 'R')
			commands.recursive = 1;
		if (flags[i] == 't')
			commands.sorted = 1;
		if (flags[i] == 'a')
			commands.display_hidden = 1;
		if (flags[i] == 'r')
			commands.reverse = 1;
	}
	return (commands);
}

static void verbosity(files_t *file_infos)
{
	my_putstr(file_infos->perm, 0);
	my_putstr("  ", 0);
	my_put_nbr(file_infos->links);
	my_putstr("\t", 0);
	my_putstr(file_infos->user, 0);
	my_putstr("\t", 0);
	my_putstr(file_infos->group, 0);
	my_putstr("\t", 0);
	my_put_nbr(file_infos->size);
	my_putstr("\t", 0);
	my_putstr(file_infos->date, 0);
	my_putstr("  ", 0);
}

static void disp_infos(files_t *file_infos, command_t commands)
{
	int disp_blocks = file_infos->blocks;
	int nb_blocks = file_infos->blocks;

	if (commands.recursive && file_infos->blocks >= 0) {
		for (int i = 0; file_infos->path[i + 2]; i++)
			write(1, &file_infos->path[i], 1);
		my_putstr(":", 1);
	}
	if (commands.verbose)
		if (disp_blocks >= 0) {
			disp_blocks = -1;
			my_putstr("total ", 0);
			my_put_nbr(nb_blocks);
			my_putstr("", 1);
		}
	if (file_infos->name[0] != '.' || commands.display_hidden) {
		if (commands.verbose)
			verbosity(file_infos);
		my_putstr(file_infos->name, 1);
	}
}

void display(files_t *file_infos, command_t commands, int recur)
{
	if ((commands.recursive && recur) || !recur) {
	 	if (commands.sorted) {
	 		sort_list(file_infos, commands.reverse);
	 	}
		while (file_infos) {
			disp_infos(file_infos, commands);
			file_infos = file_infos->next;
		}
		my_putstr("", 1);
	}
}
