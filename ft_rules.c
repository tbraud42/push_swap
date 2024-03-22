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

void	ft_sa(t_list *stack)
{
	t_list	*tmp;

	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list *stack)
{
	t_list	*tmp;

	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	write(1, "sb\n", 3);
}

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a->next;
	stack_a->next = tmp_a->next;
	tmp_a->next = stack_a;
	tmp_b = stack_b->next;
	stack_b->next = tmp_b->next;
	tmp_b->next = stack_b;
	write(1, "ss\n", 3);
}

void	ft_pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_b;
	stack_b = stack_b->next;
	tmp->next = stack_a;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_a;
	stack_a = stack_a->next;
	tmp->next = stack_b;
	write(1, "pb\n", 3);
}

void	ft_ra(t_list *stack)// je sais pas i on a encore le premier pointeur
{
	t_list	*save;

	save = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = save;
	save->next = NULL;
	write(1, "ra\n", 3);
}