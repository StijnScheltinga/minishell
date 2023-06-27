/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/27 18:04:24 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/token.h"
#include <stdio.h>
#include <assert.h>

int	main(void)
{
	assert(ft_iswhitespace(' ') == true);
	assert(ft_iswhitespace('a') == false);
	tokenize_string("cat | ls > outfile");
	
}
