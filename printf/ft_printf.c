/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:07:23 by ekarali           #+#    #+#             */
/*   Updated: 2022/02/10 20:38:04 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putarg(char cc, va_list args)
{
	if (cc == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (cc == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (cc == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	else if (cc == 'd' || cc == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (cc == 'u')
		return (ft_putunbr(va_arg(args, unsigned int), "0123456789"));
	else if (cc == 'x')
		return (ft_putunbr(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (cc == 'X')
		return (ft_putunbr(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (cc == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		retlen;
	va_list	args;
	int		i;

	va_start(args, s);
	retlen = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			retlen += ft_putarg(s[i + 1], args);
			i++;
		}
		else
			retlen += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (retlen);
}

/*int	main(void)
{
	char	*ptr;

	ptr = "pointer";
	ft_printf("string: %s\n", "this is a string");
	ft_printf("char: %c\n", 'x');
	ft_printf("pointer: %p\n", ptr);
	ft_printf("number: %d\n", -5);
	ft_printf("int: %i\n", 0xff);
	ft_printf("unsigned number: %u\n", -5);
	ft_printf("hexadecimal: %x\n", -54);
	return (0);
}*/
