/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:49:39 by romukena          #+#    #+#             */
/*   Updated: 2025/07/06 11:25:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrr(t_mylist **a, t_mylist **b)
{
	if (a && *a && (*a)->next)
		reverse_rotate(a);
	if (b && *b && (*b)->next)
		reverse_rotate(b);
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
