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
	if (argc == 1)
		ft_error(0, 0);
	pri(ft_parse(argv, 1));
	//ft_push_swap(ft_parse(argc, argv));
}
