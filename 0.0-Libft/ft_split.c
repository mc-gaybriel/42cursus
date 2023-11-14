/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:52:35 by gnickel           #+#    #+#             */
/*   Updated: 2023/11/14 17:37:07 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c);
static void	fill_res(const char *s, char **res, char c);
void		free_split(char **split);

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
	int	word_i;
	int	word_len;
	int	in_word;

	word_i = 0;
	word_len = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word &&
				(res[word_i] = (char *)malloc((word_len + 1) * sizeof(char))))
				ft_strlcpy(res[word_i++], s - word_len, word_len + 1);
			in_word = 0;
			word_len = 0;
		}
		else if (++in_word)
			word_len++;
		s++;
	}
	if (in_word && (res[word_i] = (char *)malloc((word_len +1) * sizeof(char))))
	{
		ft_strlcpy(res[word_i++], s - word_len, word_len + 1);
		word_i++;
	}
	res[word_i] = 0;
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
