/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:31:02 by gnickel           #+#    #+#             */
/*   Updated: 2023/10/28 20:56:17 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	i = 0;
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (0);
	while (i < len && start)
	{
		sub_s[i] = s[start];
		start++;
		i++;
	}
	sub_s[i] = 0;
	return (sub_s);
}
