/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:27:35 by mberge            #+#    #+#             */
/*   Updated: 2025/02/25 15:30:23 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base, size_t *baselen);
int	base2int(char *str, char *base, size_t baselen, int sign);

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	size_t	baselen;

	if (!str || !(*str) || !check_base(base, &baselen))
		return (0);
	sign = 1;
	--str;
	while (*(++str) == 32 || (9 <= *str && *str <= 13))
		;
	--str;
	while (*(++str) == '-' || *str == '+')
		if (*str == '-')
			sign *= -1;
	return (base2int(str, base, baselen, sign));
}

int	check_base(char *base, size_t *baselen)
{
	size_t			i;
	size_t			j;
	unsigned char	c;

	i = -1;
	while (base[++i])
		;
	*baselen = i;
	if (i < 2)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		c = (unsigned char)base[i];
		if (c == 32 || (9 <= c && c <= 13))
			return (0);
		if (c == '-' || c == '+')
			return (0);
		j = i;
		while (base[++j] != '\0')
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	base2int(char *str, char *base, size_t baselen, int sign)
{
	size_t	i;
	size_t	j;
	int		t;
	int		nbr;

	nbr = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		t = 0;
		j = -1;
		while (base[++j] != '\0')
		{
			if (str[i] == base[j])
			{
				nbr = (nbr * baselen) + j;
				t = 1;
				break ;
			}
		}
		if (t == 0)
			return (nbr * sign);
	}
	return (nbr * sign);
}

void	int2base(int nbr, char *base, size_t baselen)
{
	unsigned int	unbr;
	char	*nbr_str;

	nbr_str = (char *)malloc(sizeof(char) * 13);
	if (!nbr)
		return NULL;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		unbr = (unsigned int)(-((long)nbr));
		if (unbr >= baselen)
			wint2base(unbr / baselen, base, baselen);
		write(1, &(base[unbr % baselen]), 1);
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr)
	{
		wint2base((nbr / baselen), base, baselen);
		write(1, &(base[nbr % baselen]), 1);
	}
}
