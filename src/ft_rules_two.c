/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:53:55 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/05 04:53:56 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_r(t_list **stack)
{
	t_list	*save;
	t_list	*tmp;

	save = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = save;
}

void	ft_r(t_list **stack_a, t_list **stack_b, int choice)
{
	if (choice == 1)
	{
		write(1, "ra\n", 3);
		ft_make_r(stack_a);
	}
	if (choice == 2)
	{
		write(1, "rb\n", 3);
		ft_make_r(stack_b);
	}
	else
	{
		write(1, "rr\n", 3);
		ft_make_r(stack_b);
		ft_make_r(stack_a);
	}
}

static void	ft_make_rr(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	if (ft_len_list(stack) == 1)
		ft_error(1, *stack);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*stack);
	(*stack) = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int choice)
{
	if (choice == 1)
	{
		write(1, "rra\n", 4);
		ft_make_rr(stack_a);
	}
	if (choice == 2)
	{
		write(1, "rrb\n", 4);
		ft_make_rr(stack_b);
	}
	else
	{
		write(1, "rrr\n", 4);
		ft_make_rr(stack_b);
		ft_make_rr(stack_a);
	}
}