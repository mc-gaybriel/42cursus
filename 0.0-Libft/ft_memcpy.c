/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:49:20 by gnickel           #+#    #+#             */
/*   Updated: 2023/11/09 02:43:31 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	i = 0;
	if (!dst_ptr && !src_ptr)
		return (0);
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
