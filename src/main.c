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

void	pri(t_list **stack)
{
	t_list	*save;

	save = *stack;
	while (save->next)
	{
		printf("%d\n", save->value);
		save = save->next;
	}
	printf("%d\n", save->value);
	ft_free_list(stack);
}

int	main(int argc, char *argv[])
{
	t_list *stack_a;

	if (argc == 1)
		return (0);
	stack_a = ft_parse(argv, 1);
	ft_sort_three(&stack_a);
	//if (ft_len_list(&stack_a) == 2)
	//	ft_sort_two(&stack_a);
	//else if (ft_len_list(&stack_a) == 3)
	//	ft_sort_three(&stack_a);
	//else
	//	ft_sort(&stack_a);
	return (0);
}