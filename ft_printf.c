/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:27:04 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/01/04 03:51:40 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char lett)
{
	write (1, &lett, 1);
	return (1);
}

int	ft_flags(const char *string, int i, va_list args)
{
	int	count;

	count = 0;
	if (string[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (string[i] == 'c')
		count += ft_putchar(va_arg(args, char *));
	else if (string[i] == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (string[i] == 'i' || string[i] == 'd')
		count += ft_countnbr(va_arg(args, int));
	else if (string[i] == 'u')
		count += ft_countunbr(va_arg(args, unsigned int));
	else if (string[i] == 'x' || string[i] == 'X')
		count += ft_printhex(va_arg(args, unsigned int), string[i]);
	else if (string[i] == '%')
		count += ft_putstr("%");
	return (count);
}

int	ft_printf(const	char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_flags(str, i, args);
		}
		else
			count += ft_char(str[i]);
		i++;
	}
	return (count);
}

