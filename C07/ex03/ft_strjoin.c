/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:27:31 by mberge            #+#    #+#             */
/*   Updated: 2025/02/18 14:59:39 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		a;
	int		i;
	int		j;
	int		k;
	int		total_len;
	char	*res;

	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen(strs[i]);
	i = 0;
	k = 0;
	res = (char *)malloc(sizeof(char) * (total_len + (ft_strlen(sep) * (size
						- 1))));
	while (i < size)
	{
		a = 0;
		while (strs[i][a])
		{
			res[k] = strs[i][a];
			k++;
			a++;
		}
		if (i + 1 < size)
		{
			j = 0;
			while (sep[j])
			{
				res[k] = sep[j];
				k++;
				j++;
			}
		}
		i++;
	}
	res[i] = '\0';
	return (res);
}
