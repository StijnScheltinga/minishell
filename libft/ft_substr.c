/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:10:27 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/12 13:52:20 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ret = ft_malloc(sizeof(char) * len + 1);
	while (s[i])
	{
		while (j < len && i >= start)
		{
			ret[j] = s[i];
			j++;
			i++;
		}
		if (j == len)
			break ;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

// int main()
// {
// 	printf("%s", ft_substr("hallohoi", 3, 2));
// }
