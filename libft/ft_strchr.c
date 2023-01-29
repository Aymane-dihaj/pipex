/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:12:10 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/30 14:37:37 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	m;

	i = 0;
	m = (char)c;
	while (s[i])
	{
		if (s[i] == m)
			return ((char *)s + i);
		i++;
	}
	if (!m && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*int main()
{
	char str[] = "aymane";
	printf("%s", ft_strchr(str,'y'));
	return 0;
}*/