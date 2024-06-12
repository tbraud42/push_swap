/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:46:45 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/11 18:15:52 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_check_duplicates(t_list *stack, int value, char **tab)
{
	t_list	*save;

	save = stack;
	while (stack->next)
	{
		if (stack->value == value)
		{
			ft_free_tab(tab);
			ft_error(1, save);
		}
		stack = stack->next;
	}
}

static t_list	*ft_creat_chain(char **tab, int *j, t_list *save, t_list *stack)
{
	t_list		*new;
	long long	value;

	value = ft_atoi(tab[*j]);
	if (value > 2147483647 || value < -2147483648)
	{
		ft_free_tab(tab);
		ft_error(1, save);
	}
	new = malloc(sizeof(t_list));
	if (!new)
	{
		ft_free_tab(tab);
		ft_error(1, save);
	}
	stack->next = new;
	new->value = value;
	new->index = -1;
	new->next = NULL;
	ft_check_duplicates(save, value, tab);
	*j += 1;
	return (new);
}

static char	**ft_test_num(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab[i] || !tab[i][0] || ft_test_overflow(tab))
		return (ft_free_tab(tab));
	while (tab[i])
	{
		if (!tab[i] || !tab[i][0])
			return (ft_free_tab(tab));
		j = 0;
		if (tab[i][j] == '+' && (tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9'))
			j++;
		else if (tab[i][j] == '-' && (tab[i][j + 1] >= '0' && tab[i][j
				+ 1] <= '9'))
			j++;
		while (tab[i][j])
		{
			if ((tab[i][j] < '0' || tab[i][j] > '9'))
				return (ft_free_tab(tab));
			j++;
		}
		i++;
	}
	return (tab);
}

static t_list	*ft_init_list(char **tab)
{
	t_list		*s_a;
	long long	value;

	value = ft_atoi(tab[0]);
	if (value > 2147483647 || value < -2147483648)
	{
		ft_free_tab(tab);
		ft_error(0, 0);
	}
	s_a = malloc(sizeof(t_list));
	if (!s_a)
	{
		ft_free_tab(tab);
		ft_error(0, 0);
	}
	s_a->value = value;
	s_a->index = -1;
	s_a->next = NULL;
	return (s_a);
}

t_list	*ft_parse(char *argv[], int argc)
{
	t_list	*stack_a;
	t_list	*save_stack;
	char	**tab;
	int		j;

	while (argv[argc])
	{
		tab = ft_test_num(ft_split(argv[argc], ' '));
		if (tab == 0 && argc == 1)
			ft_error(0, 0);
		else if (tab == 0)
			ft_error(1, stack_a);
		j = 0;
		if (argc == 1)
		{
			stack_a = ft_init_list(tab);
			save_stack = stack_a;
			j = 1;
		}
		while (tab[j])
			save_stack = ft_creat_chain(tab, &j, stack_a, save_stack);
		ft_free_tab(tab);
		argc++;
	}
	return (stack_a);
}
