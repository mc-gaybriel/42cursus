/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:50 by gnickel           #+#    #+#             */
/*   Updated: 2023/10/26 19:27:59 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_h;
	size_t	i_n;

	i_h = 0;
	i_n = 0;
	if (needle == 0)
		return ((char *)haystack);
	while (i_h < len && haystack[i_h] != 0)
	{
		while (i_h < len && haystack[i_h] != 0 && haystack[i_h] == needle[i_n])
		{
			i_h++;
			i_n++;
			if (needle[i_n] == 0)
				return ((char *)(haystack + i_h - i_n));
		}
	}
	return (0);
}