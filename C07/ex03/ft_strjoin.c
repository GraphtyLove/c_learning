/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:27:31 by mberge            #+#    #+#             */
/*   Updated: 2025/02/23 13:13:31 by mberge           ###   ########.fr       */
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

void	append_to_str(char *src, char *dest, char *sep, int add_sep)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = -1;
	while (add_sep && sep[++j])
		dest[i++] = sep[j];
	j = -1;
	while (src[++j])
		dest[i++] = src[j];
	dest[i] = '\0';
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;
	int	j;
	int	sep_chars_count;

	total_len = 0;
	i = -1;
	sep_chars_count = ft_strlen(sep) - 1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			total_len++;
		if (i < size - 2)
			total_len += sep_chars_count;
	}
	return (total_len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		total_len;
	int		i;

	total_len = get_total_len(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * total_len);
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
		append_to_str(strs[i], dest, sep, (i != 0));
	return (dest);
}
