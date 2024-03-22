/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:26:45 by tbraud            #+#    #+#             */
/*   Updated: 2024/02/26 20:26:46 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pri(t_list *stack)
{
	t_list	*save;

	save = stack;
	while (stack->next)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("%d\n", stack->value);
	ft_free_list(save);
}

int	main(int argc, char *argv[])
{
	t_list *stack_a;

	if (argc == 1)
		ft_error(0, 0);
	stack_a = ft_parse(argv, 1);
	/*if (ft_len_list(stack_a) == 2)
		ft_sort_two(&stack_a);*/
	if (ft_len_list(stack_a) == 3)
		ft_sort_three(&stack_a);
	pri(stack_a);
	/*else
		ft_sort(&stack_a, ft_strlen_list(stack_a));*/
	ft_free_list(stack_a);
	return (0);
}

/*if (a first et c second)
	push a, c, b et sa
if (c first et b second)
	push c, b, sa ra , push a, sa et rra 
if (c first et a second)
	push c, a, sa push b et sa
if (b first et c second)
	push b, c, ra push a sa rra
if (b first et a second)
	push b, a, sa push c*/