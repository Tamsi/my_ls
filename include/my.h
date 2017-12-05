/*
** EPITECH PROJECT, 2017
** my
** File description:
** library header
*/

typedef struct args
{
	char **filename;
	char flags[30];
} args_t;

typedef struct command
{
	int verbose;
	int display_hidden;
	int recursive;
	int sorted;
	int reverse;
} command_t;

typedef struct file_infos
{
	int blocks;
	char *perm;
	int links;
	char *user;
	char *group;
	int size;
	int data;
	char *date;
	char *name;
	char *path;
	struct file_infos *next;
} files_t;

typedef struct infos
{
	int blocks;
	char *perm;
	int links;
	char *user;
	char *group;
	int size;
	int data;
	char *date;
	char *name;
	char *path;
} infos_t;

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <error.h>
#include <fcntl.h>

int	my_putstr(char const *, int);
int	my_strlen(char const *);
char	*my_strcpy(char *, char const *);
void    my_put_nbr(long);
void	l_flag(args_t *);
int	my_strcmp(char *, char *);
int	blocks_ls(char *);
char    *fperm(struct stat);
char    *get_date(struct stat);
files_t	*new_elem();
files_t *append(files_t *, files_t *);
void	display(files_t *, command_t, int);
void	sort_list(files_t *, int);
files_t  *push_in_list(files_t *, int);
char	*my_strcat(char *, char *);
command_t populate_commands(char *);
int	tab_length(char **);
