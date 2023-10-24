/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:40:17 by gnickel           #+#    #+#             */
/*   Updated: 2023/10/16 21:08:07 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	char		*dst_ptr;
	const char	*src_ptr;

	i = 0;
	dst_ptr = dst;
	src_ptr = src;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src_ptr[i] != 0)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
		dst_ptr[i] = 0;
	}
	while (src_ptr[i] != 0)
		i++;
	return (i);
}
