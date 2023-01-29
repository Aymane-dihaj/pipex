/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:20:13 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/31 14:40:41 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;
	int		j;

	new = (char *)(malloc(sizeof(char) * ft_strlen(s1) + 1));
	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	while (s1[j])
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

// int main()
// {
// 	char *s = NULL;
// 	//printf("%s", ft_strdup(s));
// 	printf("%s", strdup(s));
// }
