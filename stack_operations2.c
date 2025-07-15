/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:09:50 by romukena          #+#    #+#             */
/*   Updated: 2025/07/15 16:26:14 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_mylist **a, t_mylist **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(1, "rr\n", 3);
}

void	rrr(t_mylist **a, t_mylist **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	write(1, "rrr\n", 4);
}

void	printlist(t_mylist *head)
{
	t_mylist	*current;

	current = head;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

void	rotate_times(t_mylist **stack, int *cost, char *rot_name,
					char *rev_name)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			rotate(stack, rot_name);
			(*cost)--;
		}
		else
		{
			reverse_rotate(stack, rev_name);
			(*cost)++;
		}
	}
}
