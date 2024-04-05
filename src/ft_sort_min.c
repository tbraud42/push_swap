/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:14:22 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/03 23:14:24 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_choose_rules(t_list **stack, int	index[])
{
	int	tmp_1;
	int tmp_2;

	tmp_1 = index[0];
	tmp_2 = index[0];
	if (tmp_1 > index[1])
		tmp_1 = index[1];
	if (tmp_1 > index[2])
		tmp_1 = index[2];
	if (tmp_2 < index[2])
		tmp_2 = index[2];
	if (tmp_1 >= ft_len_list(stack) - tmp_2)
		return (0);
	return (1);
}

static int	ft_sort_min(int value, int min[])
{
	int	tmp;

	if (value < min[0])
	{
		tmp = min[0];
		min[0] = value;
		value = min[1];
		min[1] = tmp;
		min[2] = value;
		return (0);
	}
	if (value < min[1])
	{
		tmp = min[1];
		min[1] = value;
		min[2] = tmp;
		return (1);
	}
	min[2] = value;
	return (2);
}

int	*ft_find_min(t_list **stack, int min[], int index[])
{
	t_list	*save;
	int		i;
	// int		index[3];
	int		tmp;

	save = (*stack)->next->next->next;
	i = 3;
	while (save->next)
	{
		if (save->value < min[2])
		{
			tmp = ft_sort_min(save->value, min);
			if (tmp == 0)
				index[0] = i;
			else if (tmp == 1)
				index[1] = i;
			else if (tmp == 2)
				index[2] = i;
		}
		save = save->next;
		i++;
	}
	return (index);
}