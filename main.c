/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"

static args_t	*sort_flags_and_files(int ac, char const * const *av)
{
	args_t *arguments = malloc(sizeof(args_t));
	int j = 0;
	int k = 0;

	arguments->filename = malloc((ac - 1) * sizeof(char *));
	for (int i = 1; av[i]; i++) {
		if (av[i][0] == '-')
			for (int l = 1; av[i][l]; l++)
				arguments->flags[j++] = av[i][l];
		else {
			arguments->filename[k] = malloc(my_strlen(av[i]) * sizeof(char) + 1);
			my_strcpy(arguments->filename[k], av[i]);
			k += 1;
		}
	}
	arguments->flags[j] = '\0';
	return (arguments);
}

static void get_elem(files_t *elem, char *filename, struct dirent *dir)
{
	struct stat buf;
	char *path = malloc(1000);

	elem->data = 0;
	my_strcpy(path, filename);
	my_strcat(path, "/");
	my_strcat(path, dir->d_name);
	stat(path, &buf);
	elem->perm = fperm(buf);
	elem->links = buf.st_nlink;
	elem->user = getpwuid(buf.st_uid)->pw_name;
	elem->group = getgrgid(buf.st_gid)->gr_name;
	elem->size = buf.st_size;
	elem->date = get_date(buf);
	elem->data = buf.st_mtime;
	elem->name = dir->d_name;
	elem->path = path;
}

static files_t	*my_ls(char **filenames, command_t commands, int i, int recur)
{
	DIR *d;
	struct dirent *dir;
	char **subdir = malloc(100000 * sizeof(char *));
	int j = 0;
	files_t *file_infos = NULL;
	files_t *elem = new_elem();
	char *path = malloc(1000);

	if ((d = opendir(filenames[i])) == NULL)
		perror(filenames[i]);
	elem->blocks = blocks_ls(filenames[i]);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (commands.recursive && dir->d_type == DT_DIR &&
				my_strcmp(dir->d_name, ".") != 0 && my_strcmp(dir->d_name, "..") != 0)
				if (dir->d_name[0] != '.' || commands.display_hidden) {
					my_strcpy(path, filenames[i]);
					my_strcat(path, "/");
					my_strcat(path, dir->d_name);
					subdir[j] = malloc(my_strlen(path) * sizeof(char) + 1);
					my_strcpy(subdir[j++], path);
				}
			get_elem(elem, filenames[i], dir);
			file_infos = append(file_infos, elem);
			elem = new_elem();
			elem->blocks = -1;
		}
		closedir(d);
	}
	subdir[j] = NULL;
	display(file_infos, commands, recur);
	for (int k = 0; subdir[k]; k++) {
		my_ls(subdir, commands, k, 1);
	}
	return (file_infos);
}

int	main(int ac, char const * const *av)
{
	args_t *arguments = sort_flags_and_files(ac, av);
	command_t commands = populate_commands(arguments->flags);

	if (arguments->filename[0] == NULL) {
		arguments->filename[0] = malloc(2 * sizeof(char));
		my_strcpy(arguments->filename[0], ".");
	}
	for (int i = 0; arguments->filename[i]; i++) {
		my_ls(arguments->filename, commands, i, 0);
	}
	return (0);
}
