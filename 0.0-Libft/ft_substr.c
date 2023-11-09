/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:31:02 by gnickel           #+#    #+#             */
/*   Updated: 2023/11/07 16:14:34 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*empty_string(void)
{
	char	*e_str;

	e_str = (char *)malloc(1);
	if (e_str)
		e_str[0] = 0;
	return (e_str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	i_len;

	i = 0;
	i_len = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= i_len)
		return (empty_string());
	if (start + len > i_len)
		len = i_len - start;
	sub_s = (char *)malloc(len + 1);
	if (!sub_s)
		return (0);
	while (i < len && s[start])
	{
		sub_s[i] = s[start];
		start++;
		i++;
	}
	sub_s[i] = 0;
	return (sub_s);
}
