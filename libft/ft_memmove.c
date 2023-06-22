/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:23:39 by sschelti          #+#    #+#             */
/*   Updated: 2022/12/13 17:30:25 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void	*dest, const void	*src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *) dest;
	s = (char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (s > d)
	{
		while (i < (int) n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}

// int main()
// {
// 	char    str1[] = "CLibraryFunction";
// 	// char	str2[] = "ClibraryFunction";
// 	printf("mijne: %s \n", memmove(&str1[4], &str1[3], 8));
// 	// printf("echte: %s", memmove(&str2[0], &str2[7], 8));
// }
