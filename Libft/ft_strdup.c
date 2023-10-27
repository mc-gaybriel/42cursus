/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:07 by gnickel           #+#    #+#             */
/*   Updated: 2023/10/27 17:21:13 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*dest0;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	dest0 = dest;
	if (dest)
	{
		while (*s1)
			*dest++ = *s1++;
		*dest = 0;
	}
	return (dest0);
}
