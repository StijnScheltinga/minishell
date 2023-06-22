/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:46:57 by sschelti          #+#    #+#             */
/*   Updated: 2022/10/13 14:49:50 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	i = 0;
	while ((c1[i] || c2[i]) && i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	const char arr1[] = "abcd\0afsg";
// 	const char arr2[] = "abcd\0fsg";
// 	printf("mijne: %d\n", ft_strncmp(arr1, arr2, 10));
// 	printf("echte: %d", strncmp(arr1, arr2, 10));
// }