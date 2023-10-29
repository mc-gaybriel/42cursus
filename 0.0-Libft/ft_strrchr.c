/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:48 by gnickel           #+#    #+#             */
/*   Updated: 2023/10/25 15:03:45 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lo;

	lo = 0;
	while (*s != 0)
	{
		if (*s == c)
			lo = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)lo);
}
