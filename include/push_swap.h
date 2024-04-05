/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:27:39 by tbraud            #+#    #+#             */
/*   Updated: 2024/02/26 20:27:41 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

t_list		*ft_parse(char *argv[], int argc);
char		**ft_free_tab(char **tab);
void		ft_free_list(t_list **stack);
void		ft_error(int for_free, t_list *stack_A);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *nptr);
void		ft_sort(t_list **stack_a);
void		ft_sort_two(t_list **stack);
void		ft_sort_three(t_list **stack);
int			ft_is_empty(t_list **stack);
int			ft_len_list(t_list **stack);
void		ft_swap(int min[], int a, int b);
int			ft_choose_rules(t_list **stack, int	index[]);
int			*ft_find_min(t_list **stack, int min[], int index[]);
void		ft_s(t_list **stack_a, t_list **stack_b, int choice);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_r(t_list **stack_a, t_list **stack_b, int choice);
void		ft_rr(t_list **stack_a, t_list **stack_b, int choice);

#endif /* PUSH_SWAP_H */ 
