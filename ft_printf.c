/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:21:17 by sasalama          #+#    #+#             */
/*   Updated: 2022/02/23 12:41:04 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_buff(const char *arg, int *x)
{
	ft_putchar_fd2(arg[x[2] + 1], 1, x);
	x[1]--;
}

static void	ft_buff2(const char *arg, va_list argumentos, int *x, char **s)
{
	if (arg[x[2] + 1] == 'c')
		ft_putchar_fd2(va_arg(argumentos, int), 1, x);
	else if (arg[x[2] + 1] == 's')
		x[3] += ft_putstr_fd(va_arg(argumentos, char *), 1);
	else if (arg[x[2] + 1] == 'p')
	{
		x[3] += ft_putstr_fd("0x", 1);
		x[3] += ft_print_hex2(va_arg(argumentos, unsigned int long), 0, 1);
	}
	else if (arg[x[2] + 1] == 'd' || arg[x[2] + 1] == 'i')
	{
		s[0] = ft_itoa(va_arg(argumentos, int));
		x[3] += ft_putstr_fd(s[0], 1);
		free(s[0]);
	}
	else if (arg[x[2] + 1] == 'u')
	{
		s[1] = ft_itoa2(va_arg(argumentos, unsigned int));
		x[3] += ft_putstr_fd(s[1], 1);
		free(s[1]);
	}
	else if (arg[x[2] + 1] == 'x' || arg[x[2] + 1] == 'X')
		x[3] += ft_print_hex2(va_arg(argumentos, unsigned int), x[4], 0);
	else
		ft_buff(arg, x);
}

static int	ft_conversion(const char *arg, va_list argumentos, int *x)
{
	char	**s;

	s = malloc(1);
	ft_buff2(arg, argumentos, x, s);
	x[2]++;
	free(s);
	return (x[2]);
}

static void	ft_inicializar(int *x, int a1, int a2, int a3)
{
	x[0] = a1;
	x[1] = a2;
	x[2] = a3;
	x[4] = 0;
}

int	ft_printf(const char *arg, ...)
{
	va_list		argumentos;
	int			contador;
	int			x[5];

	x[3] = 0;
	contador = 0;
	ft_inicializar(x, 0, 0, 0);
	va_start(argumentos, arg);
	while (arg[contador])
	{
		if (arg[contador] == '%')
		{
			ft_inicializar(x, x[1], x[1], contador);
			if (arg[x[2] + 1] == 'X')
				x[4]++;
			contador = ft_conversion(arg, argumentos, x);
			x[1]++;
			x[4] = 0;
		}
		else
			ft_putchar_fd2(arg[contador], 1, x);
		contador++;
	}
	va_end(argumentos);
	return (x[3]);
}
