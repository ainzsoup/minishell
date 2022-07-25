/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:16:56 by sgamraou          #+#    #+#             */
/*   Updated: 2022/07/25 14:04:38 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(void)
{
	char *str;
	t_token *token;

	while (1)
	{
		str = readline("$> ");
		if (str == NULL)
			break;
		t_lexer *lex = init_lexer(str);
		token = lexer_next_token(lex);
		while (token->type != TOKEN_EOF)
		{
			printf("token value: %s\n", token->value);
			token = lexer_next_token(lex);
		}
	}
	return (0);
}