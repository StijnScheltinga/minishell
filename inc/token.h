/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:42:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/23 15:32:46 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TRUE 1
# define FALSE 0

# include "../libft/libft.h"

typedef enum s_type {
	WORD,
	REDIRECT,
	PIPE,
}	t_type;

void	tokenize_string(char *input_string);
int		assign_token(char *str, unsigned int start);
void	create_token(t_type type, char *str);

int		ft_iswhitespace(char a);

#endif