/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:45:44 by sschelti          #+#    #+#             */
/*   Updated: 2022/10/18 13:33:54 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns amount of numbers not index
static	int	sizeint(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

//new function needs str, value, size, returns string
static char	*fillstring(char *str, unsigned int value, int size)
{
	if (value == 0)
	{
		str[size] = value + 48;
		size--;
	}
	while (value >= 1)
	{
		str[size] = (value % 10) + 48;
		value /= 10;
		size--;
	}
	if (size == 0)
		str[size] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	unsigned int	value;

	size = 0;
	if (n < 0)
	{
		size++;
		value = n * -1;
	}
	else
		value = n;
	size += sizeint(value);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (str);
	str[size] = '\0';
	size--;
	return (fillstring(str, value, size));
}

// int main()
// {
// 	int n = -5453467;
// 	printf("%s", ft_itoa(n));
// }
