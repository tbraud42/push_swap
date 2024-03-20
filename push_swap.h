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

t_list			*ft_parse(char *argv[], int argc);
char			**ft_free_tab(char **tab);
void			ft_free_list(t_list *stack);
void			ft_error(int for_free, t_list *stack_A);
char			**ft_split(char const *s, char c);
long long		ft_atoi(const char *nptr);

#endif /* PUSH_SWAP_H */ 
