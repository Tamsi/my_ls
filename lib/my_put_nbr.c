/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display numbers
*/

#include <unistd.h>

void write_char(char c)
{
	write(1, &c, 1);
}

void    my_put_nbr(long nb)
{
	long   nomb;

	nomb = 0;
	if (nb <= 9 && nb >= 0)
		write_char(nb + '0');
	if (nb < 0) {
		write_char('-');
		nb = nb * (- 1);
		if (nb <= 9 && nb >= 0)
			my_put_nbr(nb);
	}
	if (nb > 9) {
		nomb = nb % 10;
		my_put_nbr(nb / 10);
		write_char(nomb + '0');
	}
}
