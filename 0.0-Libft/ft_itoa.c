/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:41:47 by gnickel           #+#    #+#             */
/*   Updated: 2023/12/04 19:20:32 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_to_string(int n, size_t digits, int is_neg);
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

	if (n == INT_MIN)
	{
		mc.is_neg = 1;
		mc.res = ft_strdup("-2147483648");
		return (mc.res);
	}
	mc.digits = get_digits(n);
	mc.is_neg = 0;
	if (n < 0)
	{
		mc.is_neg = 1;
		n = -n;
	}
	mc.res = convert_to_string(n, mc.digits, mc.is_neg);
	return (mc.res);
}

char	*convert_to_string(int n, size_t digits, int is_neg)
{
	char	*res;
	int		i;

	res = (char *)malloc(digits + 1);
	if (!res)
		return (0);
	i = digits - 1;
	while (i >= 0)
	{
		res[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	res[digits] = '\0';
	if (is_neg)
		res[0] = '-';
	return (res);
}

size_t	get_digits(int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
