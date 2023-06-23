/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:55:54 by sschelti          #+#    #+#             */
/*   Updated: 2022/10/21 13:41:59 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while ((i < len) && haystack[i])
	{
		while (haystack[i] == needle[j] && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i - j]);
			i++;
			j++;
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}

// int main()
// {
// const char arr1[] = "fhdshaakhallofkjhsfhallojksh";
// const char arr2[] = "halloj";
// printf("%s\n", ft_strnstr(arr1, arr2, 70));
// // printf("echte: %s", strnstr(arr1, arr2, -1));
// }
