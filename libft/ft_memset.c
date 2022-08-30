/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:03:40 by ekarali           #+#    #+#             */
/*   Updated: 2022/01/08 15:05:23 by ekarali          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc;
	size_t			i;

	i = 0;
	uc = (unsigned char *)b;
	while (len != 0)
	{
		uc[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
