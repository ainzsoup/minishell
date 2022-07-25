/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:30 by sgamraou          #+#    #+#             */
/*   Updated: 2022/07/25 15:14:01 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *init_token(char *value, int type)
{
	t_token *token;
   
	token = (t_token *)malloc(sizeof(t_token));
	token->value = value;
	token->type = type;
	return (token);
}

t_token	*lexer_set_token_value(t_lexer *lexer, int type)
{
	char	*value;

	value = malloc(sizeof(char) * 2);
	value[0] = lexer->c;
	value[1] = '\0';
	lexer_advance(lexer);
	if (type == TOKEN_APPEND || type == TOKEN_DELIM)
	{
		value = realloc(value, sizeof(char) * 3);
		strlcat(value, (char []){lexer->c, 0}, 3);
		lexer_advance(lexer);
	}
	return (init_token(value, type));
}

t_token	*lexer_parse_id(t_lexer *lexer)
{
	char	*value;
	
	value = malloc(sizeof(char) * 2);
	while (istext(lexer->c))
	{
		if (lexer->c == '\"' || lexer->c == '\'')
			value = get_quoted_string(lexer, value);
		else
		{
			value = realloc(value, sizeof(char) * (strlen(value) + 2));
			strcat(value, (char[]){lexer->c, 0});
			lexer_advance(lexer);	
		}
	}
	return (init_token(value, TOKEN_ID));	
}

t_token *lexer_next_token(t_lexer *lexer)
{
	lexer_skip_whitespace(lexer);
	if (lexer->c == '|')
		return(lexer_set_token_value(lexer, TOKEN_PIPE));
	if (lexer->c == '>')
	{
		if (lexer_peek(lexer, 1) == '>')
			return(lexer_set_token_value(lexer, TOKEN_APPEND));
		return(lexer_set_token_value(lexer, TOKEN_RDOUT));
	}
	if (lexer->c == '<')
	{
		if (lexer_peek(lexer, 1) == '<')
			return (lexer_set_token_value(lexer, TOKEN_DELIM));
		return(lexer_set_token_value(lexer, TOKEN_RDIN));
	}
	if (lexer->c == '\0')
		return (lexer_set_token_value(lexer, TOKEN_EOF));
	return(lexer_parse_id(lexer));
	
}
