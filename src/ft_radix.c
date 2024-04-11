/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:21:28 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/09 06:46:47 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*save;
	int		max;
	int		max_bits;

	save = *stack;
	max = save->index;
	max_bits = 0;
	while (save)
	{
		if (save->index > max)
			max = save->index;
		save = save->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_list **s_a, t_list **s_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *s_a;
	size = ft_len_list(head_a);
	max_bits = get_max_bits(s_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *s_a;
			if (((head_a->index >> i) & 1) == 1)
				ft_r(s_a, NULL, 1);
			else
				ft_pb(s_a, s_b);
		}
		while (ft_len_list(*s_b) != 0)
			ft_pa(s_a, s_b);
		i++;
	}
}
