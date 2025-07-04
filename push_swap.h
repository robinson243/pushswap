/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:09:54 by romukena          #+#    #+#             */
/*   Updated: 2025/07/03 18:58:23 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct list
{
	int			value;
	int			index;
	struct list	*next;

}	t_mylist;

int		is_space(char c);

void	free_list(t_mylist **lst);

long	ft_atoi_modif(char *str);

void	free_tab(char **tab);

t_mylist	*createnode(int value, int index_count);

void	addback(t_mylist **List, int value);
void	put_in_struct(t_mylist **List, char **av);
void	printlist(t_mylist *head);
int		check_duplicates(t_mylist *stack);
int		sorted_list(t_mylist *stack);
void	add_front(t_mylist **lst, t_mylist *new);
int		free_node(t_mylist *node);
void	swap(t_mylist **stack);
void	push(t_mylist **stack_a, t_mylist **stack_b);
void	rotate(t_mylist **stack);
void	rr(t_mylist **a, t_mylist **b);
void	reverse_rotate(t_mylist **stack);

#endif