/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:19 by romukena          #+#    #+#             */
/*   Updated: 2025/07/12 17:14:44 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	*get_chunk_limits(int *sorted_tab, int size, int chunk_count)
{
	int	*tab;
	int	i;
	int	chunk_size;
	int	plus;
	int	index;

	i = 0;
	chunk_size = size / chunk_count;
	plus = 0;
	tab = malloc(sizeof(int) * chunk_count);
	if (!tab)
		return (NULL);
	while (i < chunk_count)
	{
		index = chunk_size - 1 + plus;
		if (i == chunk_count - 1 || index >= size)
			index = size - 1;
		tab[i] = sorted_tab[index];
		i++;
		plus += chunk_size;
	}
	return (tab);
}

int	has_chunk_value(t_mylist **stack, int nb)
{
	t_mylist	*cur;

	cur = *stack;
	while (cur)
	{
		if (cur->value <= nb)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	find_next_in_chunk(t_mylist *stack, int limit)
{
	int	i;

	i = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->value <= limit)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	get_median(t_mylist *b)
{
	int	*tab;
	int	size;
	int	median;

	size = countlist(b);
	tab = get_sorted_array(b, size);
	if (!tab)
		return (0);
	median = tab[size / 2];
	free(tab);
	return (median);
}

void	filter_by_chunks(t_mylist **a, t_mylist **b, int *sorted_tab, int size)
{
	int	n;
	int	i;
	int	*lim;
	int	median;

	if (size > 100)
		n = 13;
	else
		n = 5;
	lim = get_chunk_limits(sorted_tab, size, n);
	if (!lim)
		return ;
	median = sorted_tab[size / 2];
	i = 0;
	while (i < n)
	{
		while (has_chunk_value(a, lim[i]))
		{
			int idx = find_next_in_chunk(*a, lim[i]);
			move_to_top(a, idx, "ra", "rra");
			if (*b && (*a)->value < median)
				rotate(b, "rb");
			push(a, b, "pb");
		}
		i++;
	}
	free(lim);
}

/*
#include <stdio.h>
#include <stdlib.h>

// Prototypes des fonctions que tu as déjà
int		countlist(t_mylist *lst);
void	pushswap(t_mylist **a, t_mylist **b);
void	print_stack(t_mylist *stack);
void	free_stack(t_mylist **stack);
void	push_front(t_mylist **stack, int value);

// Implémentations simples pour test

void	push_front(t_mylist **stack, int value)
{
	t_mylist	*node;

	node = malloc(sizeof(t_mylist));
	if (!node)
		return ;
	node->value = value;
	node->next = *stack;
	*stack = node;
}

void	print_stack(t_mylist *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	free_stack(t_mylist **stack)
{
	t_mylist	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(void)
{
	t_mylist	*a;
	t_mylist	*b;

	a = NULL;
	b = NULL;
	// Remplir la pile a avec des valeurs non triées
	push_front(&a, 3);
	push_front(&a, 1);
	push_front(&a, 8);
	push_front(&a, 5);
	push_front(&a, 2);
	printf("Avant pushswap: ");
	print_stack(a);
	pushswap(&a, &b);
	printf("Après pushswap: ");
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
 */