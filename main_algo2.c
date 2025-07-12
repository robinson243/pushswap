/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:09:22 by romukena          #+#    #+#             */
/*   Updated: 2025/07/12 17:24:22 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_mylist *b)
{
	t_mylist	*cur;
	int			value;

	cur = b;
	value = cur->value;
	while (cur)
	{
		if (value < cur->value)
			value = cur->value;
		cur = cur->next;
	}
	return (value);
}

void	move_to_top(t_mylist **stack, int index, char *ra_cmd, char *rra_cmd)
{
	int	size;
	int	i;

	i = 0;
	size = countlist(*stack);
	if (index <= size / 2)
	{
		while (i++ < index)
			rotate(stack, ra_cmd);
	}
	else
	{
		while (i++ < size - index)
			reverse_rotate(stack, rra_cmd);
	}
}

int	get_index(t_mylist *b, int value)
{
	t_mylist	*cur;
	int			i;

	cur = b;
	i = 0;
	while (cur)
	{
		if (value == cur->value)
			return (i);
		cur = cur->next;
		i++;
	}
	return (i);
}

void	reinject_from_b(t_mylist **a, t_mylist **b)
{
	int	max;
	int	index;
	int	size_b;

	if (!b || !*b) 
		return ;
	max = find_max(*b);
	index = get_index(*b, max);
	size_b = countlist(*b);
	if (index <= size_b / 2)
	{
		while ((*b)->value != max)
			rotate(b, "rb");
	}
	else
	{
		while ((*b)->value != max)
			reverse_rotate(b, "rrb");
	}
	push(b, a, "pa");
}

int	find_min(t_mylist *a)
{
	t_mylist	*cur;
	int			min_val;

	if (!a)
		return (0);
	cur = a;
	min_val = cur->value;
	while (cur)
	{
		if (cur->value < min_val)
			min_val = cur->value;
		cur = cur->next;
	}
	return (min_val);
}

void	pushswap(t_mylist **a, t_mylist **b)
{
	int	*sorted_tab;
	int	size;

	size = countlist(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		sorted_tab = get_sorted_array(*a, size);
		filter_by_chunks(a, b, sorted_tab, size);
		
		// Vider complètement la pile B
		while (*b)
			reinject_from_b(a, b);
		
		// Corriger l'ordre final dans A
		int min_val = find_min(*a); // Ajouter cette fonction
		int min_index = get_index(*a, min_val);
		move_to_top(a, min_index, "ra", "rra");
		
		free(sorted_tab);
	}
}
