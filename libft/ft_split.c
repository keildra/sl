/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:08:27 by ekarali           #+#    #+#             */
/*   Updated: 2022/01/14 21:14:10 by ekarali          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	mallocword(char *mals, const char *s, int i, int mlen)
{
	int	x;

	x = 0;
	while (mlen > 0)
	{
		mals[x] = s[i - mlen];
		x++;
		mlen--;
	}
	mals[x] = '\0';
}

static char	*splitwords(char **mals, char const *s, char c, int count)
{
	int	i;
	int	j;
	int	mlen;

	i = 0;
	j = 0;
	mlen = 0;
	while (j < count)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			mlen++;
		}
		mals[j] = (char *)malloc(sizeof(char) * (mlen + 1));
		if (!mals)
			return (0);
		mallocword(mals[j], s, i, mlen);
		j++;
		mlen = 0;
	}
	mals[j] = 0;
	return (mals[j]);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**mals;

	if (!s)
		return (0);
	count = countwords(s, c);
	mals = (char **)malloc((count + 1) * sizeof(char *));
	if (!mals)
		return (0);
	splitwords(mals, s, c, count);
	return (mals);
}
