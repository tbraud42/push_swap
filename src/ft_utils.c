/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:17:13 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/03 23:17:17 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_empty(t_list **stack)
{
	t_list	*save;

	save = (*stack);
	if (!save)
		return (1);
	return (0);
}

void	ft_sort_two(t_list **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		ft_s(stack, NULL, 1);
}

int	ft_len_list(t_list **stack)
{
	int		i;
	t_list	*save;

	i = 0;
	save = (*stack);
	while (save->next)
	{
		save = save->next;
		i++;
	}
	return (i);
}

void	ft_swap(int min[], int a, int b)
{
	int	tmp;

	tmp = min[a];
	min[a] = min[b];
	min[b] = tmp;
}