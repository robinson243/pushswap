/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:09:22 by romukena          #+#    #+#             */
/*   Updated: 2025/07/10 13:11:35 by romukena         ###   ########.fr       */
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

void	rotate_to_top(t_mylist **b, int index)
{
	int	size;
	int	i;

	size = countlist(*b);
	i = 0;
	if ((size / 2) < index)
	{
		while (index + i < size)
		{
			reverse_rotate(b, "rb");
			i++;
		}
	}
	else if ((size / 2) >= index)
	{
		while (index - i > 0)
		{
			rotate(b, "rb");
			i++;
		}
	}
}

void	reinject_from_b(t_mylist **a, t_mylist **b)
{
	int	max;
	int	index;

	while (*b)
	{
		max = find_max(*b);
		index = get_index(*b, max);
		rotate_to_top(b, index);
		push(b, a, "pa");
	}
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
		if (!sorted_tab)
			return ;
		filter_by_chunks(a, b, sorted_tab, size);
		reinject_from_b(a, b);
		free(sorted_tab);
	}
}
