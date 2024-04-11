/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:27:39 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/11 16:23:11 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

//|------error------|
char				**ft_free_tab(char **tab);
void				ft_free_list(t_list **stack);
void				ft_error(int for_free, t_list *stack_A);

//|------parsing------|
t_list				*ft_parse(char *argv[], int argc);
char				**ft_split(char const *s, char c);
long long			ft_atoi(const char *nptr);

//|------utils------|
int					ft_len_list(t_list *stack);
void				ft_swap(int min[], int a, int b);
int					ft_already_sort(t_list **s_a);
void				ft_init_index(t_list *s_a);
int					ft_test_overflow(char *tab[]);

//|------sort------|
void				ft_sort_two(t_list **stack);
void				ft_sort_three(t_list **stack);
void				ft_sort_four(t_list **s_a, t_list **s_b, int index);
void				ft_sort_five(t_list **s_a, t_list **s_b);
int					ft_is_empty(t_list **stack);
void				ft_radix_sort(t_list **s_a, t_list **s_b);

//|------rules------|
void				ft_s(t_list **s_a, t_list **s_b, int choice);
void				ft_pa(t_list **s_a, t_list **s_b);
void				ft_pb(t_list **s_a, t_list **s_b);
void				ft_r(t_list **s_a, t_list **s_b, int choice);
void				ft_rr(t_list **s_a, t_list **s_b, int choice);

#endif /* PUSH_SWAP_H */
