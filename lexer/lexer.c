/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:42:26 by sgamraou          #+#    #+#             */
/*   Updated: 2022/06/23 11:31:59 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer *init_lexer(char *src) {
	t_lexer *lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	lexer->src = src;
	lexer->src_size = strlen(src);
	lexer->c = src[lexer->i];
	lexer->i = 0;
	return (lexer);
}

void 	lexer_advance(t_lexer *lexer) {
	if (lexer->i < lexer->src_size && lexer->c != '\0') 
	{
		lexer->i++;
		lexer->c = lexer->src[lexer->i];
	}
}

void	lexer_skip_whitespace(t_lexer *lexer) {
	while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n' || lexer->c == '\r')
		lexer_advance(lexer);
}

char	lexer_peek(t_lexer *lexer, int offset) {
	return (lexer->src[MIN(lexer->i + offset, lexer->src_size)]);
}
