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

static int	ft_test_b(t_list **s_a, t_list **s_b, int min[], int order[])
{
	if (order[0] == -1 || order[1] == -1)
		return (0);
	if ((order[0] == 2 && order[1] == 1) || (order[0] == 2 && order[1] == 0) 
	|| (order[0] == 1 && order[1] == 0) || (order[0] == 0 && order[1] == 2))
		ft_s(0, s_b, 2);
	if ((order[0] == 2 && order[1] == 1) || (order[0] == 2 && order[1] == 0))
	{
		if (((*s_a)->value == min[0]) || ((*s_a)->value == min[1]))
			ft_r(s_a, s_b, 3);
		else
			ft_r(0, s_b, 2);
	}
	while (((*s_a)->value != min[0]) && ((*s_a)->value != min[1]) 
	&& ((*s_a)->value != min[2]))
		ft_r(s_a, s_b, 1);
	ft_pb(s_a, s_b);
	if ((order[0] == 2 && order[1] == 1) || (order[0] == 2 && order[1] == 0) 
	|| (order[0] == 1 && order[1] == 2))
		ft_s(0, s_b, 2);
	if ((order[0] == 2 && order[1] == 1) || (order[0] == 1 && order[1] == 2))
		ft_rr(0, s_b, 2);
	return (1);
}

static void	ft_sort_b_rr(t_list **s_a, t_list **s_b, int min[])
{
	int	j;
	int	order[3];

	j = 0;
	order[0] = -1;
	order[1] = -1;
	order[2] = -1;
	while (j != 3)
	{
		if ((*s_a)->value == min[0] || (*s_a)->value == min[1]
		 || (*s_a)->value == min[2])
		{
			if ((*s_a)->value == min[0])
				order[j] = 0;
			if ((*s_a)->value == min[1])
				order[j] = 1;
			if ((*s_a)->value == min[2])
				order[j] = 2;
			j++;
			if ( j != 3)
				ft_pb(s_a, s_b);
		}
		if (ft_test_b(s_a, s_b, min, order) == 0)
			ft_rr(0, s_b, 2);
	}
}

static void	ft_sort_b_r(t_list **s_a, t_list **s_b, int min[])
{
	int	j;
	int	order[3];

	j = 0;
	order[0] = -1;
	order[1] = -1;
	order[2] = -1;
	while (j != 3)
	{
		if ((*s_a)->value == min[0] || (*s_a)->value == min[1]
		 || (*s_a)->value == min[2])
		{
			if ((*s_a)->value == min[0])
				order[j] = 0;
			if ((*s_a)->value == min[1])
				order[j] = 1;
			if ((*s_a)->value == min[2])
				order[j] = 2;
			j++;
			if ( j != 3)
				ft_pb(s_a, s_b);
		}
		if (ft_test_b(s_a, s_b, min, order) == 0)
			ft_r(0, s_b, 2);
	}
}

static void	ft_put_min(t_list **stack_a, t_list **stack_b)
{
	int	min[3];
	int	index[3];

	min[0] = (*stack_a)->value;
	index[0] = 0;
	min[1] = (*stack_a)->next->value;
	index[1] = 1;
	min[2] = (*stack_a)->next->next->value;
	index[1] = 2;
	if (min[1] > min[2])
		ft_swap(min, 1 , 2);
	if (min[0] > min[1])
		ft_swap(min, 0, 1);
	if (min[0] > min[2])
		ft_swap(min, 0, 2);
	if (min[1] > min[2])
		ft_swap(min, 1, 2);
	ft_find_min(stack_a, min, index);
	if (ft_choose_rules(stack_a, index) == 0)
		ft_sort_b_r(stack_a, stack_b, min);
	else
		ft_sort_b_rr(stack_a, stack_b, min);
}

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;	
	while (ft_len_list(stack_a) > 3)
		ft_put_min(stack_a, &stack_b);
	if (ft_len_list(stack_a) == 3)
		ft_sort_three(stack_a);
	if (ft_len_list(stack_a) == 2)
		ft_sort_two(stack_a);
	while (ft_is_empty(&stack_b))
		ft_pa(stack_a, &stack_b);
}

/*if (a first et c second)
	push a, c, b et sb
if (c first et b second)
	push c, b, sb rb , push a, sb et rrb 
if (c first et a second)
	push c, a, sb push b et sb
if (b first et c second)
	push b, c, rb push a sa rrb
if (b first et a second)
	push b, a, sb push c*/
/*int	ft_sort_b_rrr(t_list **s_a, t_list **s_b)
{
	if ((*s_b)->value < (*s_b)->next->value)c a b | b a c | a b c
	{
		if ((*s_b)->value > (*s_a)->value)a b c
		{
			ft_s(0, s_b, 2);
			ft_r(0, s_b, 2);
			ft_pa(s_a, s_b);
		}
		else
		{
			if ((*s_b)->next->value > (*s_a)->value)b a c
			else c a b
		}
	}
	else c b a | b c a | a c b
	{
		if ((*s_b)->next->value > (*s_a)->value) a c b
		{

		}
		if ((*s_a)->value > (*s_b)->value) c b a
			ft_pb(s_a, s_b);
		else b c a
		{
			ft_pb(s_a, s_b);
			ft_s(0, s_b, 2);
		}
	}
}*/
/*if (a first et c second)o
	push a, c, b et sb
if (c first et b second)
	push c, b, sb rb , push a, sb et rrb 
if (c first et a second)
	push c, a, sb push b et sb
if (b first et c second)
	push b, c, rb push a sa rrb
if (b first et a second)
	push b, a, sb push c*/
/*int	ft_make_rra(t_list **s_a, t_list **s_b, int *min[])
{
	int	i;

	i = 0;
	while (min[0] != 0 && min[1] != 0 && min[2] != 0)
	{
		if ((*s_a)->value == min[0] || (*s_a)->value == min[1]
		 || (*s_a)->value == min[2])
		{
			i++;
			if (i != 3)
				ft_pd(s_a, s_b);
		}
		if (i == 3)
		{
			ft_sort_b_rrr(s_a, s_b);
			break;
		}
	}
	return (1);
}*/
/*int	ft_make_ra(t_list **s_a, t_list **s_b, int *min[], int index)
{
	int	i;

	i = 0;
	while (min[0] != 0 && min[1] != 0 && min[2] != 0)
	{
		if ((*s_a)->value == min[0])
		{
			ft_pd(s_a, s_b);
			min[0] = 0;
			i++;
		}
		else if ((*s_a)->value == min[1])
		{
			ft_pd(s_a, s_b);
			min[1] = 0;
			i++;
		}
		else if ((*s_a)->value == min[2])
		{
			ft_pd(s_a, s_b);
			min[2] = 0;
			i++;
		}
		if (ft_sort_b(index, i) == 1)
			ft_r(s_a);
		else
			ft_rr(s_a, s_b);
		i = i % 3;
	}

	return (1);
}*/
