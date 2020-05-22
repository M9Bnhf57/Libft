/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:45:53 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/15 20:42:18 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	isngtive(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int			i;
	char		*result;
	long int	input;

	i = 0;
	input = n;
	if (!(result = (char*)malloc((getlen(n) + isngtive(n) + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		input = input * (-1);
		result[0] = '-';
		i = getlen(n);
	}
	else
		i = getlen(n) - 1;
	result[i + 1] = '\0';
	while (i >= isngtive(n))
	{
		result[i] = input % 10 + '0';
		input = input / 10;
		i--;
	}
	return (result);
}
