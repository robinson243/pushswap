/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:19 by romukena          #+#    #+#             */
/*   Updated: 2025/07/15 16:28:02 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	get_index_for_list(int *tab, t_mylist *head, int size)
{
	t_mylist	*cur;
	int			i;

	if (!tab || !head || size <= 0)
		return ;
	i = 0;
	while (i < size)
	{
		cur = head;
		while (cur)
		{
			if (cur->value == tab[i])
			{
				cur->index = i;
				break ;
			}
			cur = cur->next;
		}
		i++;
	}
}

int	get_position_of_min(t_mylist *a)
{
	int			pos;
	int			min_index;
	int			i;
	t_mylist	*cur;

	if (!a)
		return (0);
	cur = a;
	min_index = cur->index;
	pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->index < min_index)
		{
			min_index = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

int	get_insert_position(t_mylist *a, int index_b)
{
	int			i;
	t_mylist	*cur;

	if (!a)
		return (0);
	i = 0;
	cur = a;
	while (cur && cur->next)
	{
		if (cur->index < index_b && cur->next->index > index_b)
			return (i + 1);
		cur = cur->next;
		i++;
	}
	if (index_b < a->index)
		return (0);
	return (i + 1);
}

int	get_target_position_in_a(t_mylist *a, int index_b)
{
	int	pos;

	pos = get_insert_position(a, index_b);
	if (pos != -1)
		return (pos);
	return (get_position_of_min(a));
}

void	calculate_move_cost(t_mylist *a, t_mylist *b)
{
	int			size_a;
	int			size_b;
	t_mylist	*cur;
	int			pos_b;
	int			target_a;

	size_a = countlist(a);
	size_b = countlist(b);
	cur = b;
	while (cur)
	{
		pos_b = get_position(b, cur->index);
		target_a = get_target_position_in_a(a, cur->index);
		if (pos_b <= size_b / 2)
			cur->cost_b = pos_b;
		else
			cur->cost_b = pos_b - size_b;
		if (target_a <= size_a / 2)
			cur->cost_a = target_a;
		else
			cur->cost_a = target_a - size_a;
		cur = cur->next;
	}
}

/* int	get_position(t_mylist *stack, int index_to_find)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index_to_find)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
} */

/* // main_algo.c
int	get_target_position_in_b(t_mylist *b, int index_from_a)
{
	t_mylist	*cur;
	int			i;
	int			index_min;
	int			min_position;

	if (!b)
		return (0);
	cur = b;
	i = 0;
	index_min = cur->index;
	min_position = 0;
	while (cur)
	{
		if (index_min > cur->index)
		{
			index_min = cur->index;
			min_position = i;
		}
		if (cur->next && cur->index > index_from_a
			&& cur->next->index < index_from_a)
			return (i + 1);
		cur = cur->next;
		i++;
	}
	return (min_position + 1);
} */
