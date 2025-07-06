/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:09:54 by romukena          #+#    #+#             */
/*   Updated: 2025/07/06 11:26:15 by romukena         ###   ########.fr       */
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

/* list_utils.c */
void		free_list(t_mylist **lst);
t_mylist	*createnode(int value, int index_count);
void		addback(t_mylist **List, int value);
void		add_front(t_mylist **lst, t_mylist *new);
void		printlist(t_mylist *head);
/* input_validation.c */
int			is_space(char c);
long		ft_atoi_modif(char *str);
int			check_duplicates(t_mylist *stack);
int			sorted_list(t_mylist *stack);
int			put_in_struct(t_mylist **List, char **av);
/* memory_utils.c */
void		free_tableau(char **tab);
int			free_node(t_mylist *node);
int			check_tab(char **tab);
char		**get_args(int ac, char **av);
int			is_valid(int ac, char **av);
/* stack_operations.c */
void		swap(t_mylist **stack);
void		push(t_mylist **stack_a, t_mylist **stack_b);
void		rotate(t_mylist **stack);
void		reverse_rotate(t_mylist **stack);
void		rr(t_mylist **a, t_mylist **b);
/* stack_operations2.c */
void		rrr(t_mylist **a, t_mylist **b);
int			countlist(t_mylist *head);

#endif