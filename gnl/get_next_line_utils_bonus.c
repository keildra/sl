/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:42:52 by ekarali           #+#    #+#             */
/*   Updated: 2022/02/03 20:37:56 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cchar;

	cchar = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cchar)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nwl;
	int		n;
	int		i;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	nwl = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (nwl == 0)
		return (NULL);
	n = 0;
	i = 0;
	while (s1[i])
		nwl[n++] = s1[i++];
	i = 0;
	while (s2[i])
		nwl[n++] = s2[i++];
	nwl[n] = 0;
	return (nwl);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ml;
	size_t	strlen;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen || !len)
		return (ft_strdup(""));
	if (strlen > len)
		strlen = len;
	ml = (char *)malloc((strlen + 1) * sizeof(char));
	if (!ml)
		return (NULL);
	ml[strlen] = '\0';
	while (strlen--)
		ml[i++] = s[start++];
	return (ml);
}
