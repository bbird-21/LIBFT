/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:15:03 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/05 12:17:12 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	nb_words(char const *s, char c)
{
	int	nb_words;
	int	check_word;
	int	i;

	i = 0;
	check_word = 1;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] != c && check_word)
		{
			nb_words++;
			check_word = 0;
		}
		else if (s[i] == c)
			check_word = 1;
		i++;
	}
	return (nb_words);
}

char	*ft_initword(char *src, size_t endWord, size_t nbchar, char c)
{
	size_t	i;
	int		begin;
	char	*word;

	begin = (endWord - nbchar);
	i = 0;
	word = malloc(sizeof(char) * (nbchar + 1));
	if (!word)
		return (NULL);
	if (src[begin] == c || begin < 0)
		begin ++;
	while (src[begin] && i < nbchar)
		word[i++] = src[begin++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		nbchar;
	int		index;

	index = 0;
	nbchar = 0;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (nb_words(s, c) + 1));
	if (!s || !split)
		return (NULL);
	while (i < ft_strlen((char *)s))
	{
		if (s[i] != c)
			nbchar++;
		if ((s[i] == c || i == ft_strlen((char *)s) - 1) && nbchar > 0)
		{
			split[index++] = ft_initword((char *)s, i, nbchar, c);
			nbchar = 0;
		}
		i++;
	}
	split[index] = NULL;
	return (split);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	if (argc != 3)
// 	{
// 		printf("nombre d'arguments invalides\n");
// 		return (EXIT_FAILURE);
// 	}

// 	char	**str;
// 	str = ft_split(argv[1], argv[2][0]);
// 	while (str[i])
// 		printf("%s\n", str[i++]);

// 	i = 0;
// 	free(str[0]);
// 	free(str[1]);
// 	free(str);
// }