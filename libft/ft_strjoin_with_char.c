/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:48:13 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/12 14:09:20 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_with_char(char const *s1, char const *s2, char c)
{
	int		i;
	int		j;
	size_t	total_len;
	char	*new_str;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_malloc(total_len * sizeof(char) + 2);
	if (!new_str)
		return (NULL);
	while (s1[i++])
		new_str[i - 1] = s1[i - 1];
	new_str[i - 1] = c;
	while (s2[j++])
		new_str[i++] = s2[j - 1];
	new_str[i] = '\0';
	return (new_str);
}
