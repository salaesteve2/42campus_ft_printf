/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:10:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/02/23 11:00:06 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	x;

	x = 0;
	if (s)
	{
		while (s[x])
		{
			write(fd, &s[x], 1);
			x++;
		}
	}
	else
	{
		write(fd, "(null)", 6);
		x = x + 6;
	}
	return (x);
}
