/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:17:13 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/17 02:27:14 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_empty(t_list **stack)
{
	t_list	*save;

	save = (*stack);
	if (!save)
		return (1);
	return (0);
}

int	ft_already_sort(t_list **s_a)
{
	t_list	*save;

	if (!s_a || !*s_a)
		return (1);
	save = (*s_a);
	while (save && save->next && save->value < save->next->value)
		save = save->next;
	if (save->next == NULL)
		return (1);
	return (0);
}

int	ft_len_list(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_init_index(t_list *s_a)
{
	int		index;
	t_list	*i;
	t_list	*j;

	i = s_a;
	while (i)
	{
		index = 0;
		j = s_a;
		while (j)
		{
			if (i->value > j->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

int	ft_test_overflow(char *tab[])
{
	int	i;
	int	j;
	int	test;

	i = 0;
	while (tab[i])
	{
		j = 0;
		test = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j] && tab[i][j] == '0')
			j++;
		while (tab[i][j])
		{
			test++;
			j++;
		}
		if (test > 11)
			return (1);
		i++;
	}
	return (0);
}
