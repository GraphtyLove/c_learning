/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberge <mberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:20:46 by mberge            #+#    #+#             */
/*   Updated: 2025/02/18 12:29:26 by mberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	(void)argc;
	str = argv[0];
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}
