/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:09:54 by romukena          #+#    #+#             */
/*   Updated: 2025/07/12 17:24:45 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structure de données */
typedef struct s_mylist
{
	int				value;
	int				index;
	struct s_mylist	*next;
}					t_mylist;

/*----------------------------------------------------------------------------*/
/*                                  list_utils.c                              */
/*----------------------------------------------------------------------------*/
void				free_list(t_mylist **lst);
t_mylist			*createnode(int value, int index_count);
void				addback(t_mylist **List, int value);
void				add_front(t_mylist **lst, t_mylist *new);
int					countlist(t_mylist *head);

/*----------------------------------------------------------------------------*/
/*                              input_validation.c                            */
/*----------------------------------------------------------------------------*/
int					is_space(char c);
long				ft_atoi_modif(char *str);
int					check_duplicates(t_mylist *stack);
int					sorted_list(t_mylist *stack);
int					put_in_struct(t_mylist **List, char **av);

/*----------------------------------------------------------------------------*/
/*                               memory_utils.c                               */
/*----------------------------------------------------------------------------*/
void				free_tableau(char **tab);
int					free_node(t_mylist *node);
int					check_tab(char **tab);
char				**get_args(int ac, char **av);
int					is_valid(int ac, char **av);

/*----------------------------------------------------------------------------*/
/*                              stack_operations.c                            */
/*----------------------------------------------------------------------------*/
void				swap(t_mylist **stack, char *name);
void				push(t_mylist **stack_a, t_mylist **stack_b, char *name);
void				rotate(t_mylist **stack, char *name);
void				reverse_rotate(t_mylist **stack, char *name);
void				printlist(t_mylist *head);

/*----------------------------------------------------------------------------*/
/*                              sort_operations.c                             */
/*----------------------------------------------------------------------------*/
void				sort_two(t_mylist **stack);
void				sort_three(t_mylist **stack);
void				sort_five(t_mylist **stack_a, t_mylist **stack_b);
int					find_smallest(t_mylist **stack_a);
void				push_to_b(t_mylist **stack_a, t_mylist **stack_b);

/*----------------------------------------------------------------------------*/
/*                                quicksort.c                                 */
/*----------------------------------------------------------------------------*/
void				quicksort(int *tab, int deb, int fin);
int					partition(int *tab, int deb, int fin);
void				ft_swap(int *a, int *b);

/*----------------------------------------------------------------------------*/
/*                                main_algo.c                                 */
/*----------------------------------------------------------------------------*/
int					*get_sorted_array(t_mylist *a, int size);
int					*get_chunk_limits(int *sorted_tab, int size,
						int chunk_count);
int					has_chunk_value(t_mylist **stack, int nb);
void				filter_by_chunks(t_mylist **stack_a, t_mylist **stack_b,
						int *sorted_tab, int size);

/*----------------------------------------------------------------------------*/
/*                                main_algo2.c                                */
/*----------------------------------------------------------------------------*/
int					find_max(t_mylist *b);
int					get_index(t_mylist *b, int value);
void				move_to_top(t_mylist **stack, int index,
					char *ra_cmd, char *rra_cmd);
void				reinject_from_b(t_mylist **a, t_mylist **b);
void				pushswap(t_mylist **a, t_mylist **b);
int					find_min(t_mylist *a);

#endif