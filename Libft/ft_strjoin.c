/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:49:41 by gnickel           #+#    #+#             */
/*   Updated: 2023/10/29 15:17:02 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(total_size);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, total_size);
	ft_strlcat(ret, s2, total_size);
	return (ret);
}
