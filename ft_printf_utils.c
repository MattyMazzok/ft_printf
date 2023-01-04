/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:26:05 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/01/04 02:37:47 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10);
		ft_write('8');
	}
	else if (nbr < 0)
	{
		ft_write('-');
		ft_putnbr(-nbr);
	}
	else
	{
		if (nbr > 9)
		{
			ft_putnbr(nbr / 10);
		}
		ft_write(48 + nbr % 10);
	}
}

int	ft_countnbr(int nbr)
{
	int	count;
	int	n;

	count = 0;
	n = nbr;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = n / 10;
			count++;
		}
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	ft_putnbr(nbr);
	return (count);
}

int	ft_counthex(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 16;
	}
	return (count);
}

void	ft_puthex(unsigned int nbr, const char str)
{
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, str);
		ft_puthex(nbr % 16, str);
	}
	else
	{
		if (nbr <= 9)
			ft_write((nbr + '0'));
		else
		{
			if (str == 'x')
				ft_write((nbr - 10 + 'a'));
			if (str == 'X')
				ft_write((nbr - 10 + 'A'));
		}
	}
}

int	ft_printhex(unsigned int nbr, const char str)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nbr, str);
	return (ft_counthex(nbr));
}
