/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:06:05 by sschelti          #+#    #+#             */
/*   Updated: 2022/10/21 13:47:38 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, char a, size_t len)
{
	unsigned int	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) str;
	while (i < len)
	{
		*p = a;
		p++;
		i++;
	}
	return (str);
}
