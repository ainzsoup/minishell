/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 07:22:22 by sgamraou          #+#    #+#             */
/*   Updated: 2022/07/24 18:06:02 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	between_dq(t_lexer *lexer)
{
	unsigned int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < lexer->i)
	{
		if (lexer->src[i] == '"')
			count++;
		i++;
	}
	return ((count % 2) != 0 ? 1 : 0);
}