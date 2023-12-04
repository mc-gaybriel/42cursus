/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:19:42 by gnickel           #+#    #+#             */
/*   Updated: 2023/12/04 23:26:42 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct strtrim_vars
{
	size_t	start;
	size_t	end;
	size_t	n_len;
	char	*e_str;
	char	*t_str;
}	t_strtrim_vars;

char	*ft_strtrim(const char *s1, const char *set)
{
	t_strtrim_vars	mc;

	if (!s1 || !set)
		return (0);
	mc.start = 0;
	while (s1[mc.start] && ft_strchr(set, s1[mc.start]))
		mc.start++;
	if (!s1[mc.start])
	{
		mc.e_str = (char *)malloc(1);
		if (mc.e_str)
			mc.e_str[0] = 0;
		return (mc.e_str);
	}
	mc.end = ft_strlen(s1) - 1;
	while (mc.end > mc.start && ft_strchr(set, s1[mc.end]))
		mc.end--;
	mc.n_len = mc.end - mc.start + 1;
	mc.t_str = (char *)malloc(mc.n_len + 1);
	if (!mc.t_str)
		return (0);
	ft_memcpy(mc.t_str, s1 + mc.start, mc.n_len);
	mc.t_str[mc.n_len] = 0;
	return (mc.t_str);
}
