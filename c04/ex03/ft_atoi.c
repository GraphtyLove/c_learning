/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:41 by mberge            #+#    #+#             */
/*   Updated: 2025/02/17 14:21:13 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	minus_count;
	int	res;

	minus_count = 0;
	res = 0;
	while (*str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		minus_count += (*str++ == '-');
	if (str && *str >= '0' && *str <= '9')
		res = *str++ - 48;
	while (str && *str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - 48);
	if (minus_count % 2 != 0)
		return (-res);
	return (res);
}

// int	main(void)
// {
// 	int res = ft_atoi("--+1234");
// 	printf("%i\n", res);
// }