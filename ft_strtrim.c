/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:57:45 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/19 18:49:11 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_partofset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int		gets(char const *s1, char const *set)
{
	int		start;

	start = 0;
	while (s1[start] != '\0' && is_partofset(s1[start], set))
	{
		start++;
	}
	return (start);
}

static int		gete(char const *s1, char const *set)
{
	int		end;

	end = ft_strlen(s1) - 1;
	while (end > 0 && is_partofset(s1[end], set))
	{
		end--;
	}
	if (end > 0)
		return (end + 1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (gete(s1, set) <= gets(s1, set))
	{
		if (!(result = (char*)malloc(sizeof(char))))
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = (char*)malloc((gete(s1, set) - gets(s1, set) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (gets(s1, set) + i < gete(s1, set))
	{
		result[i] = s1[gets(s1, set) + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
