/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:44:32 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/01/04 03:58:35 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char *c);
int				ft_putstr(const char *str);
int				ft_countnbr(int nbr);
int				ft_print_ptr(unsigned long long ptr);
int				ft_printhex(unsigned int nbr, const char str);
void			ft_write(char c);
void			ft_putunbr(unsigned int nbr);
int				ft_countunbr(unsigned int nbr);

#endif
