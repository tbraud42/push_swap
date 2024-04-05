/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:18:22 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/03 23:18:24 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((*stack)->next->value < (*stack)->next->next->value)
		{
			ft_s(stack, NULL, 1);
			ft_r(stack, NULL, 1);
		}
		else
			ft_rr(stack, NULL, 1);
	}
}
