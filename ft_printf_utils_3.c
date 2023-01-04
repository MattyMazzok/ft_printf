/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:32:13 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/01/04 05:00:23 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

void	ft_putunbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	if (nbr <= 9)
		ft_write(48 + nbr);
}

int	ft_countunbr(unsigned int nbr)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = nbr;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	ft_putunbr(nbr);
	return (count);
}
