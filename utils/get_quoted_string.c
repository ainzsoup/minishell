/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quoted_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:54:52 by sgamraou          #+#    #+#             */
/*   Updated: 2022/07/25 14:29:04 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_quoted_string(t_lexer *lexer, char *value)
{
	char k = lexer->c;
	value = realloc(value, sizeof(char) * (strlen(value) + 2));
	strcat(value, (char[]){lexer->c, 0});
	lexer_advance(lexer);
	while (lexer->c != k)
	{
		if (lexer->c == 0)
			lexer->error = 1;
		value = realloc(value, sizeof(char) * (strlen(value) + 2));
		strcat(value, (char[]){lexer->c, 0});
		lexer_advance(lexer);
	}
	value = realloc(value, sizeof(char) * (strlen(value) + 2));
	strcat(value, (char[]){lexer->c, 0});
	lexer_advance(lexer);
	return (value);
}