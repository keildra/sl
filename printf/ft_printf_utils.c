/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:14:05 by ekarali           #+#    #+#             */
/*   Updated: 2022/02/10 20:37:54 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(int num)
{
	int	rtn;

	rtn = 0;
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (num < 0)
	{
		num = -1 * num;
		rtn += ft_putchar('-');
	}
	if (num > 9)
		rtn += ft_putnbr(num / 10);
	rtn += ft_putchar(num % 10 + 48);
	return (rtn);
}

int	ft_putunbr(unsigned int nbr, char *base)
{
	int				rtn;
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	rtn = 0;
	if (nbr > (len - 1))
		rtn += ft_putunbr(nbr / len, base);
	rtn += ft_putchar(base[nbr % len]);
	return (rtn);
}

int	ft_putptr(void *ptr)
{
	int				rtn;
	unsigned long	p;

	rtn = 0;
	p = (unsigned long)ptr;
	if (p > 15)
		rtn += ft_putptr((void *)(p / 16));
	rtn += ft_putchar("0123456789abcdef"[p % 16]);
	return (rtn);
}
