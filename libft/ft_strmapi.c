/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:24:07 by ekarali           #+#    #+#             */
/*   Updated: 2022/01/11 18:39:04 by ekarali          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mal;
	unsigned int	index;
	int				len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	mal = malloc(sizeof(char) * (len + 1));
	if (!mal)
		return (NULL);
	index = 0;
	while (s[index])
	{
		mal[index] = f(index, s[index]);
		index++;
	}
	mal[index] = '\0';
	return (mal);
}
