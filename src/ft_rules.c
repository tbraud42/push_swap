/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:50:36 by tbraud            #+#    #+#             */
/*   Updated: 2024/03/22 13:50:38 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_s(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	ft_s(t_list **stack_a, t_list **stack_b, int choice)
{
	if (choice == 1)
	{
		write(1, "sa\n", 3);
		ft_make_s(stack_a);
	}
	if (choice == 2)
	{
		write(1, "sb\n", 3);
		ft_make_s(stack_b);
	}
	else
	{
		write(1, "ss\n", 3);
		ft_make_s(stack_b);
		ft_make_s(stack_a);
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	write(1, "pb\n", 3);
}
