/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:52:35 by gnickel           #+#    #+#             */
/*   Updated: 2023/12/04 20:13:34 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c);
static void	fill_res(const char *s, char **res, char c);
static void	copy_word(char **res, const char *s, int *word_i, int word_len);
void		free_split(char **split);

typedef struct split_vars
{
	int	w_i;
	int	w_len;
	int	in_word;
}	t_split_vars;

char	**ft_split(const char *s, char c)
{
	int		num_words;
	char	**res;

	if (!s)
		return (0);
	num_words = count_words(s, c);
	res = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!res)
		return (0);
	fill_res(s, res, c);
	return (res);
}

static int	count_words(const char *s, char c)
{
	int	ctr;
	int	in_word;

	ctr = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0 && ++ctr)
			in_word = 1;
		s++;
	}
	return (ctr);
}

static void	fill_res(const char *s, char **res, char c)
{
	t_split_vars	mc;

	mc.w_i = 0;
	mc.w_len = 0;
	mc.in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (mc.in_word)
				copy_word(res, s, &mc.w_i, mc.w_len);
			mc.in_word = 0;
			mc.w_len = 0;
		}
		else
		{
			mc.in_word = 1;
			if (mc.in_word)
				mc.w_len++;
		}
		s++;
	}
	if (mc.in_word)
		copy_word(res, s, &mc.w_i, mc.w_len);
	res[mc.w_i] = 0;
}

static void	copy_word(char **res, const char *s, int *word_i, int word_len)
{
	res[*word_i] = (char *)malloc((word_len + 1) * sizeof(char));
	if (res[*word_i])
		ft_strlcpy(res[(*word_i)++], s - word_len, word_len + 1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
