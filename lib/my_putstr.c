/*
** EPITECH PROJECT, 2017
** my_pustr
** File description:
** prompt a string
*/

#include "my.h"

int	my_putstr(char const *str, int linefeed)
{
	for (int i = 0; str[i]; i++)
		write(1, &str[i], 1);
	if (linefeed == 1)
		write(1, "\n", 1);
	return (0);
}
