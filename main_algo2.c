/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:09:22 by romukena          #+#    #+#             */
/*   Updated: 2025/07/15 16:25:53 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_mylist	*find_cheapest_move(t_mylist *b)
{
	t_mylist	*cur;
	t_mylist	*best;
	int			best_cost;
	int			cost;

	cur = b;
	best = b;
	best_cost = ft_abs(b->cost_a) + ft_abs(b->cost_b);
	while (cur)
	{
		cost = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = cur;
		}
		cur = cur->next;
	}
	return (best);
}

void	execute_move(t_mylist **a, t_mylist **b, t_mylist *move)
{
	int	cost_a;
	int	cost_b;

	cost_b = move->cost_b;
	cost_a = move->cost_a;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	rotate_times(a, &cost_a, "ra", "rra");
	rotate_times(b, &cost_b, "rb", "rrb");
	push(b, a, "pa");
}

void	align_stack_a(t_mylist **a)
{
	int			size;
	int			pos;
	t_mylist	*cur;

	size = countlist(*a);
	pos = 0;
	cur = *a;
	while (cur && cur->index != 0)
	{
		cur = cur->next;
		pos++;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate(a, "ra");
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate(a, "rra");
	}
}

void	push_swap(t_mylist **a, t_mylist **b)
{
	int			size;
	int			*sorted;
	t_mylist	*move;

	if (!a || !*a || countlist(*a) <= 1 || sorted_list(*a))
		return ;
	size = countlist(*a);
	sorted = get_sorted_array(*a, size);
	if (!sorted)
		return ;
	get_index_for_list(sorted, *a, size);
	free(sorted);
	if (size <= 5)
		return (small_sort(a, b));
	while (countlist(*a) > 3)
		push_to_b(a, b);
	sort_three(a);
	while (*b)
	{
		calculate_move_cost(*a, *b);
		move = find_cheapest_move(*b);
		execute_move(a, b, move);
	}
	align_stack_a(a);
}

/* void push_swap(t_mylist **a, t_mylist **b)
{
	int			size;
	int			*sorted;
	int			loop;
	t_mylist	*move;

	loop = 0;
	int max_loops = 10000; // sécurité anti-boucle infinie
	size = countlist(*a);
	sorted = get_sorted_array(*a, size);
	get_index_for_list(sorted, *a, size);
	free(sorted);
	if (sorted_list(*a))
		return ;
	if (size <= 5)
		small_sort(a, b);
	else
	{
		while (countlist(*a) > 3)
			push_to_b(a, b);
		sort_three(a);
		while (*b && loop < max_loops)
		{
			printf("Avant calculate_move_cost:\n");
			print_stack(*a, "stack_a");
			print_stack(*b, "stack_b");
			calculate_move_cost(*a, *b);
			move = find_cheapest_move(*a);
			if (!move)
				break ;
			execute_move(a, b, move);
			printf("Après execute_move:\n");
			print_stack(*a, "stack_a");
			print_stack(*b, "stack_b");
			printf("\n");
			loop++;
		}
		if (loop == max_loops)
			printf("Attention : boucle maximale atteinte !\n");
		align_stack_a(a);
	}
}

 */