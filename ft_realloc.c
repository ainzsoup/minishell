/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:08:29 by sgamraou          #+#    #+#             */
/*   Updated: 2022/06/23 12:12:03 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_realloc(void	*src, size_t size)
{
	char	*dest;

	dest = malloc(sizeof(char) * size);
	dest = memcpy(dest, src, strlen((const char *)src +1));
	free(src);
	return(dest);
}
