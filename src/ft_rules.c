/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:50:36 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/08 00:52:12 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_s(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_s(t_list **s_a, t_list **s_b, int choice)
{
	if (choice == 1)
	{
		ft_make_s(s_a);
		write(1, "sa\n", 3);
	}
	if (choice == 2)
	{
		ft_make_s(s_b);
		write(1, "sb\n", 3);
	}
	else if (choice == 3)
	{
		ft_make_s(s_a);
		ft_make_s(s_b);
		write(1, "ss\n", 3);
	}
}

void	ft_pa(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;

	tmp = (*s_b);
	(*s_b) = (*s_b)->next;
	tmp->next = (*s_a);
	(*s_a) = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;

	tmp = (*s_a);
	(*s_a) = (*s_a)->next;
	tmp->next = (*s_b);
	(*s_b) = tmp;
	write(1, "pb\n", 3);
}
