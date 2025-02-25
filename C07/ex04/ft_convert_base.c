/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:27:35 by mberge            #+#    #+#             */
/*   Updated: 2025/02/25 15:26:09 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base, size_t *baselen);
int	base2int(char *str, char *base, size_t baselen, int sign);

int strlen(char *str)
{
    int i;

    i = -1;
    while(str[++i])
        ;
    return (i);
}


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int nbr_int;
    int base_from_len;
    int base_to_len;

    base_from_len = strlen(base_from);
    base_to_len = strlen(base_to);
    nbr_int = base2int(nbr, base_from, base_from_len, 1);
    
}