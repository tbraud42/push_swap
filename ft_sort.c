/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:36:35 by tbraud            #+#    #+#             */
/*   Updated: 2024/03/20 22:36:36 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list *stack)
{
	if (stack->value > stack->next->value)
	{
		if (stack->next->value > stack->next->next->value)
		{
			ft_sa(stack);
			ft_rra(stack);
		}
		else
			ft_ra(stack);
	}
	else
	{
		if (stack->next->value > stack->next->next->value)
		{

		}
	}
}

123
231
312
321
213
132

void	ft_sort_two(t_list *stack)
{
	t_list	*save;

	if (stack->value > stack->next->value)
	{
		save = stack;
		stack = stack->next;
		stack->next = save;
		save->next = NULL;
		write(1, "sa\n", 3);
	}
}

void	ft_swap(int a, int b)
{
	int	tmp;

	tmp = b;
	b = a;
	a = tmp;
}

void	ft_find_min(int min_a, int min_b, t_list *stack)
{
	if (min_a > min_b)
		ft_swap(&min_a, &min_b);
	while (stack->next)
	{
		if (stack->value < min_b)
			if (stack->value < min_a)
			{
				min_b = min_a;
				min_a = stack->value;
			}
			else
				min_b = stack->value;
		stack = stack->next;
	}
}

void	ft_putup(int min_a, int min_b, t_list *stack_a, t_list *stack_b)
{
	// ici c'est les calcule savant !
}

void	ft_sort(t_list *stack_a)
{
	t_list	*stack_b;
	int		min_a;
	int		min_b;

	while (ft_len_stack(stack_a) > 3)
	{
		min_a = stack_a->value;
		min_b = stack_a->next->value;
		ft_find_min(&min_a, &min_b, stack_a);
		ft_putup(min_a, min_b, stack_a, stack_b);
	}
	if (ft_len_stack(stack_a) == 3)
		ft_sort_three(stack_a);
	else
		ft_sort_two(stack_a);
	while (stack_b_is_empty())
		ft_pa(stack_a, stack_b);
}