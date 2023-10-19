/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:39:58 by sasalama          #+#    #+#             */
/*   Updated: 2022/02/23 12:37:21 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digits_hex(unsigned int long empty)
{
	int	digits;

	digits = 0;
	while (empty > 0)
	{
		empty = empty / 16;
		digits++;
	}
	if (digits == 0)
		digits++;
	return (digits);
}

int	ft_buff(unsigned int long x, unsigned int long empty, char *s, int mayus)
{
	int	a;

	a = 0;
	if (x == 1)
	{
		if (empty > 9)
		{
			s[0] = empty % 16 + '0';
			s[0] += 39;
			if (mayus == 1)
				s[0] -= 32;
			s[1] = '\0';
		}
		else
		{
			s[0] = empty + '0';
			s[1] = '\0';
		}
		a = 1;
	}
	return (a);
}

void	ft_buff2(unsigned int long x, unsigned int long empty, char *s, int *s2)
{
	unsigned int long	h;

	if (x >= 8 && s2[1] == 0)
		x = 8;
	h = x + 1;
	while (x > 0)
	{
		s[x - 1] = empty % 16 + '0';
		if (s[x] >= 58 && s[x] <= 63)
		{
			s[x] += 39;
			if (s2[0] == 1)
				s[x] -= 32;
		}
		empty = empty / 16;
		x--;
	}
	s[h - 1] = '\0';
	if (s[x] >= 58 && s[x] <= 63)
	{
		s[x] += 39;
		if (s2[0] == 1)
			s[x] -= 32;
	}
}

int	ft_print_hex2(unsigned int long empty, int mayus, int pointer)
{
	int					x;
	char				*s;
	int					a;
	int					s2[2];

	s2[0] = mayus;
	s2[1] = pointer;
	if ((empty == 0 || (long)empty == LONG_MIN) && pointer == 0)
		return (ft_putchar_fd('0', 1));
	x = ft_digits_hex(empty);
	s = malloc(x + 1);
	a = ft_buff(x, empty, s, mayus);
	if (a == 0)
		ft_buff2(x, empty, s, s2);
	x = ft_putstr_fd(s, 1);
	free(s);
	return (x);
}
