/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:33:27 by mberge            #+#    #+#             */
/*   Updated: 2025/02/17 17:20:13 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		;
	return (i);
}

char	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i++])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
	}
	return (1);
}

int	get_base_idx(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	minus_count;
	int	res;
	int	base_len;

	base_len = ft_strlen(base);
	if (!is_valid_base(base) || !*base)
		return (0);
	minus_count = 0;
	res = 0;
	while (*str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		minus_count += (*str++ == '-');
	while (*str)
	{
		res = res * base_len + get_base_idx(*str, base);
		str++;
	}
	if (minus_count % 2 != 0)
		return (-res);
	return (res);
}

// int	main(void)
// {
// 	printf("%i", ft_atoi_base("1000", "01"));
// }