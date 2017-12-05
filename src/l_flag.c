/*
** EPITECH PROJECT, 2017
** l_flag
** File description:
** handle -l on my_ls
*/

#include "my.h"

int    blocks_ls(char *filepath)
{
	unsigned int   result = 0;
	DIR *d;
	struct dirent *dir;
	struct stat buf;
	char *path = malloc(1000);

	if ((d = opendir(filepath)) == NULL)
		perror(filepath);
	if (d) {
		while ((dir = readdir(d)) != NULL)
			if (dir->d_name[0] != '.') {
				my_strcpy(path, filepath);
				my_strcat(path, "/");
				my_strcat(path, dir->d_name);
				lstat(path, &buf);
				result = result + buf.st_blocks;
			}
	}
	return (result / 2);
}

char    *fperm(struct stat buf)
{
	char *perm = malloc(10 * sizeof(char));

	perm[0] = (S_ISDIR(buf.st_mode)) ?  'd' : '-';
	perm[1] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (buf.st_mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (buf.st_mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (buf.st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (buf.st_mode & S_IXOTH) ? 'x' : '-';
	perm[10] = '\0';
	return (perm);
}

char    *get_date(struct stat buf)
{
	char *date;
	char *real_date = malloc(14 * sizeof(char));
	int j = 0;

	date = ctime(&buf.st_mtime);
	for (int i = 4; i < 16; i++)
		real_date[j++] = date[i];
	real_date[j] = '\0';
	return (real_date);
}
