/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:43:33 by sgamraou          #+#    #+#             */
/*   Updated: 2022/07/25 12:42:29 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAC_LEXER_H
# define TAC_LEXER_H

#define MAX(a, b) a > b ? a : b

#define MIN(a, b) a < b ? a : b

typedef struct  s_lexer
{
	char	 		*src;
	size_t			src_size;
	char			c;
	unsigned int	i;
	int				error;
}	t_lexer;

t_lexer *init_lexer(char *src);
void	lexer_advance(t_lexer *lexer);
void	lexer_skip_whitespace(t_lexer *lexer);
char	lexer_peek(t_lexer *lexer, int offset);

#endif