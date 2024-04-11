/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:26:45 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/11 00:02:22 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*s_a;
	t_list	*s_b;
	int		len;

	if (argc == 1)
		return (0);
	s_a = ft_parse(argv, 1);
	s_b = NULL;
	ft_init_index(s_a);
	if (ft_already_sort(&s_a) == 0)
	{
		len = ft_len_list(s_a);
		if (len == 2)
			ft_sort_two(&s_a);
		else if (len == 3)
			ft_sort_three(&s_a);
		else if (len == 4)
			ft_sort_four(&s_a, &s_b, 0);
		else if (len == 5)
			ft_sort_five(&s_a, &s_b);
		else
			ft_radix_sort(&s_a, &s_b);
	}
	ft_free_list(&s_a);
	return (0);
}
