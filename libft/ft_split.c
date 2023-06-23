/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:40:36 by sschelti          #+#    #+#             */
/*   Updated: 2022/10/20 19:43:58 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(char const *s, char c)
{
	int	i;
	int	sw;
	int	word;

	i = 0;
	sw = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && sw == 0)
		{
			word++;
			sw = 1;
		}
		if (s[i] == c)
			sw = 0;
		i++;
	}
	return (word);
}

static	int	ft_len(char const *s, char c, int i)
{
	int	a;

	a = 0;
	while (s[i] != c && s[i])
	{
		i++;
		a++;
	}
	return (a);
}

static void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!ptr || !s)
		return (ptr);
	while (j < word_count(s, c))
	{
		while (s[i] == c)
			i++;
		ptr[j] = ft_substr(s, i, ft_len(s, c, i));
		if (!ptr[j])
		{
			ft_free(ptr);
			return (NULL);
		}
		i += ft_len(s, c, i);
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

// int main()
// {
// 	// printf("%d", ft_split("  hallo hallo  hallo", ' '));
// 	// printf("%d", word_count("hallo hallo  hallo  f aiffdjshf  ", ' '));
// 	ft_split("  hallo dofd dsofjdsfoj sdf ", ' ');
// }