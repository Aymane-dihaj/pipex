/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:43:26 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/30 14:59:44 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char a, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check(s1[start], set))
		start++;
	while (end > start && ft_check(s1[end - 1], set))
		end--;
	len = end - start + 1;
	new = (char *)(malloc(sizeof(char) * len));
	if (!new)
		return (NULL);
	while (start < end)
	{
		new[i++] = s1[start++];
	}
	new[i] = '\0';
	return (new);
}

// int main()
// {
//       char *string = ft_strtrim("      "," ");      
//       printf("%s", string);
// }
