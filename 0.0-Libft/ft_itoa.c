/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:41:47 by gnickel           #+#    #+#             */
/*   Updated: 2023/11/23 16:34:17 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_digits(int n);

typedef struct itoa_vars
{
	size_t	digits;
	char	*res;
	int		is_neg;
	int		i;
}	t_itoa_vars;

char	*ft_itoa(int n)
{
	t_itoa_vars	mc;

	mc.digits = get_digits(n);
	mc.res = (char *)malloc(mc.digits + 2);
	mc.is_neg = 0;
	if (!mc.res)
		return (0);
	if (n == INT_MIN)
    {
        mc.is_neg = 1;
        n = -(n + 1);
    }
	else if (n < 0)
	{
		mc.is_neg = 1;
		n = -n;
	}
	mc.i = mc.digits - 1;
	while (mc.i >= 0)
	{
		mc.res[mc.i] = '0' + (n % 10);
		n /= 10;
		mc.i--;
	}
	mc.res[mc.digits] = 0;
	if (mc.is_neg)
		mc.res[0] = '-';
	return (mc.res);
}

size_t	get_digits(int n)
{
	size_t	digits;

	digits = 1;
	if (n == INT_MIN)
		return (sizeof(int) * 8);
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	n /= 10;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
