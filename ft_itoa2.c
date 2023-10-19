/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:26:01 by sasalama          #+#    #+#             */
/*   Updated: 2022/02/23 12:23:52 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rev_char_tab(char *tab, unsigned int long size)
{
	unsigned int long		i;
	char					swap;

	i = 0;
	while (i < size - 1)
	{
		swap = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = swap;
		i++;
		size--;
	}
}

char	*ft_tab(char *s, unsigned int long n, unsigned int long number)
{
	if (!s)
		return (0);
	number = n;
	n = 0;
	if (number == 0)
		s[n++] = 0 + '0';
	while (number > 0)
	{
		s[n++] = number % 10 + '0';
		number = number / 10;
	}
	s[n] = '\0';
	ft_rev_char_tab(s, n);
	return (s);
}

static int long	ft_digits(unsigned int long number, unsigned int long digits)
{
	while (number > 0)
	{
		digits++;
		number = number / 10;
	}
	return (digits);
}

char	*ft_itoa2(unsigned int long n)
{
	char				*s;
	unsigned int long	number;
	unsigned int long	digits;

	digits = 1;
	number = n;
	digits = ft_digits(number, digits);
	s = malloc(digits + 1);
	s = ft_tab(s, n, number);
	return (s);
}
