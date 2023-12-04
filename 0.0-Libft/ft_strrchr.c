/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:48 by gnickel           #+#    #+#             */
/*   Updated: 2023/12/04 20:24:24 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lo;

	lo = 0;
	while (*s != 0)
	{
		if (*s == (char)c)
			lo = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)lo);
}
