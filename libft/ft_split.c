/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:26:04 by agpereir          #+#    #+#             */
/*   Updated: 2024/01/10 16:22:16 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates memory and returns an array of strings 
obtained by dividing 's' using the 'c' character 
as the delimiter. The array must end with a NULL pointer.*/
#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	c_words;
	int	i;

	i = 0;
	c_words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			c_words++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

static char	*worddup(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		j;
	int		i;

	i = 0;
	j = 0;
	words = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!words)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = worddup(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
/*int		main(void)
{

    char s[] = "      split       this for   me  !       ";
    char c = ' ';
    char *result = worddup(s, c);


    printf("Palavra encontrada(*worddupp): %s\n", result);
      

	printf("Qtd de Palavras(count_word): %d\n", count_word("agatha barros", ' '));

	int i = 0;
	char **tab;
		
	tab = ft_split("Agatha Barros", ' ');
	while (i < 2)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
}*/