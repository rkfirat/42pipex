/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:06:06 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:46:14 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
	return (NULL);
}

static int	ft_count_words(const char *str, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_putword(const char *s, int start, int len)
{
	char	*word;
	int		j;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

static char	**fill_words(const char *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	start;
	int	word_len;

	i = 0;
	word = 0;
	while (word < num_words)
	{
		while (s[i] == c)
			i++;
		start = i;
		word_len = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = ft_putword(s, start, word_len);
		if (!s2[word])
			return (free_array(s2, word));
		word++;
	}
	return (s2);
}

char	**ft_split(const char *s, char c)
{
	char	**s2;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (NULL);
	s2[num_words] = NULL;
	if (!fill_words(s, c, s2, num_words))
		return (NULL);
	return (s2);
}
