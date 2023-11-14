/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:19:42 by gnickel           #+#    #+#             */
/*   Updated: 2023/11/14 16:08:08 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start = 0;
	size_t	end;
	size_t	n_len;
	char	*e_str;
	char	*t_str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (!s1[start])
	{
		e_str = (char *)malloc(1);
		if (e_str)
			e_str[0] = 0;
		return (e_str);
	}
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	n_len = end - start + 1;
	t_str = (char *)malloc(n_len + 1);
	if (!t_str)
		return (0);
	ft_memcpy(t_str, s1 + start, n_len);
	t_str[n_len] = 0;
	return (t_str);
}
