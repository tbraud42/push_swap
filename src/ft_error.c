/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:46:31 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/07 15:57:43 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

void	ft_free_list(t_list **stack)
{
	t_list	*to_free;

	while ((*stack)->next)
	{
		to_free = (*stack);
		(*stack) = (*stack)->next;
		free(to_free);
	}
	free(*stack);
}

void	ft_error(int for_free, t_list *stack_A)
{
	if (for_free == 1)
		ft_free_list(&stack_A);
	stack_A = 0;
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}
