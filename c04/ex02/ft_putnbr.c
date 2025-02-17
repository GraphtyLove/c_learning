/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:00:41 by maxim             #+#    #+#             */
/*   Updated: 2025/02/17 13:28:50 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reverse_str(char *str, int n)
{
	int	start;
	int	end;
	int	tmp;

	start = 0;
	end = n - 1;
	while (start < n / 2)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

void	add_minus_to_str(char *str)
{
	char	prev;
	char	current;
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			prev = str[i];
			str[i] = '-';
		}
		else
		{
			current = str[i];
			str[i] = prev;
			prev = current;
		}
		i++;
	}
	str[i] = prev;
	str[i + 1] = '\0';
}

// 12 because max int is 2,147,483,647 (+1 for the -, +1 for /0)
void	ft_putnbr(int nb)
{
	char	chars[12];
	int		i;
	int		is_negative;

	if (nb == -2147483648)
		write(1, "-2147483648", 12);
	is_negative = (nb < 0);
	i = 0;
	if (is_negative)
		nb = -nb;
	while (nb > 9)
	{
		chars[i] = '0' + (nb % 10);
		nb /= 10;
		i++;
	}
	chars[i] = '0' + (nb % 10);
	reverse_str(chars, i + 1);
	chars[i + 1] = '\0';
	if (is_negative)
	{
		add_minus_to_str(chars);
		i++;
	}
	write(1, chars, i + 1);
}

// int	main(void)
// {
// 	ft_putnbr(-2147483648);
// }
