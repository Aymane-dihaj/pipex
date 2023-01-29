/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:06:42 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/30 15:18:56 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)(s);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	if (c == 0)
		return (str + ft_strlen(str));
	return (0);
}

/*int main()
{
	char str[] = "aymayne";
	printf("%s", ft_strrchr(str,'y'));
	//printf("%s", strrchr(str,'y'));
	return 0;
}*/