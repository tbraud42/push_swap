/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:53:55 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/09 07:16:13 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_r(t_list **stack)
{
	t_list	*save;
	t_list	*tmp;

	save = (*stack)->next;
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = save;
}

void	ft_r(t_list **s_a, t_list **s_b, int choice)
{
	if (choice == 1)
	{
		ft_make_r(s_a);
		write(1, "ra\n", 3);
	}
	if (choice == 2)
	{
		ft_make_r(s_b);
		write(1, "rb\n", 3);
	}
	else if (choice == 3)
	{
		ft_make_r(s_a);
		ft_make_r(s_b);
		write(1, "rr\n", 3);
	}
}

static void	ft_make_rr(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*stack);
	(*stack) = tmp->next;
	tmp->next = NULL;
}

void	ft_rr(t_list **s_a, t_list **s_b, int choice)
{
	if (choice == 1)
	{
		ft_make_rr(s_a);
		write(1, "rra\n", 4);
	}
	if (choice == 2)
	{
		ft_make_rr(s_b);
		write(1, "rrb\n", 4);
	}
	else if (choice == 3)
	{
		ft_make_rr(s_a);
		ft_make_rr(s_b);
		write(1, "rrr\n", 4);
	}
}
