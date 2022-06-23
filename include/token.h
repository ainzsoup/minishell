/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:13:53 by sgamraou          #+#    #+#             */
/*   Updated: 2022/06/21 14:30:29 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAC_TOKEN_H
#define TAC_TOKEN_H

typedef struct  s_token
{
	char	*value;
	enum{
		TOKEN_ID,
		TOKEN_RDIN,
		TOKEN_RDOUT,
		TOKEN_PIPE,
		TOKEN_DQUOTES,
		TOKEN_SQUOTES,
		TOKEN_DELIM,
		TOKEN_APPEND,
		TOKEN_EOF,
	} type;
}	t_token;

t_token *init_token(char *value, int type);
t_token *lexer_next_token(t_lexer *lexer);
t_token	*lexer_set_token_value(t_lexer *lexer, int type)

#endif