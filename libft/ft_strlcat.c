/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:20:35 by sschelti          #+#    #+#             */
/*   Updated: 2022/10/18 15:34:00 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	d_len;
	unsigned long	s_len;
	unsigned long	dst_i;
	unsigned long	src_i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	src_i = 0;
	dst_i = d_len;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (src[src_i])
	{
		if (src_i == dstsize - d_len - 1)
			break ;
		dst[dst_i] = src[src_i];
		src_i++;
		dst_i++;
	}
	if (dstsize > d_len)
		dst[dst_i] = '\0';
	return (d_len + s_len);
}

// int main()
// {
// 	printf("%lu", ft_strlcat("hallo", "hoi", 5));
// }