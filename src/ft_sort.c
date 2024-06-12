/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:18:22 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/17 02:33:00 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_list **s_a, t_list **s_b)
{
	if ((*s_a)->next->next->index == 0)
		ft_r(s_a, NULL, 1);
	if ((*s_a)->next->index == 0)
		ft_r(s_a, NULL, 1);
	if ((*s_a)->next->next->next->index == 0)
		ft_rr(s_a, NULL, 1);
	if ((*s_a)->next->next->next->next->index == 0)
		ft_rr(s_a, NULL, 1);
	if (ft_already_sort(s_a) == 0)
	{
		ft_pb(s_a, s_b);
		ft_sort_four(s_a, s_b, 1);
		ft_pa(s_a, s_b);
	}
}

void	ft_sort_four(t_list **s_a, t_list **s_b, int index)
{
	if ((*s_a)->next->next->index == index)
		ft_r(s_a, NULL, 1);
	if ((*s_a)->next->index == index)
		ft_r(s_a, NULL, 1);
	if ((*s_a)->next->next->next->index == index)
		ft_rr(s_a, NULL, 1);
	if (ft_already_sort(s_a) == 0)
	{
		ft_pb(s_a, s_b);
		ft_sort_three(s_a);
		ft_pa(s_a, s_b);
	}
}

void	ft_sort_three(t_list **stack)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		if ((*stack)->next->value > (*stack)->next->next->value)
		{
			ft_s(stack, NULL, 1);
			ft_rr(stack, NULL, 1);
		}
		else
		{
			if ((*stack)->value > (*stack)->next->next->value)
				ft_r(stack, NULL, 1);
			else
				ft_s(stack, NULL, 1);
		}
	}
	else
	{
		if ((*stack)->next->value > (*stack)->next->next->value)
			ft_rr(stack, NULL, 1);
		if ((*stack)->value > (*stack)->next->value)
			ft_s(stack, NULL, 1);
	}
}

void	ft_sort_two(t_list **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		ft_s(stack, NULL, 1);
}
