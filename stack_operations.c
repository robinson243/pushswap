/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:49:35 by romukena          #+#    #+#             */
/*   Updated: 2025/07/04 22:04:05 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap(t_mylist **stack)
{
	t_mylist	*current;
	int			temp;

	current = *stack;
	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}

void	push(t_mylist **stack_a, t_mylist **stack_b)
{
	t_mylist	*node;
	t_mylist	*tmp;

	if (!stack_a || !stack_b)
		return ;
	if (!(*stack_a))
		return ;
	node = createnode((*stack_a)->value, (*stack_a)->index);
	if (!node)
		return ;
	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	add_front(stack_b, node);
	free(tmp);
}

void	rotate(t_mylist **stack)
{
	t_mylist	*tmp;

	if (!(*stack) || !stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	addback(stack, tmp->value);
}

void	reverse_rotate(t_mylist **stack)
{
	t_mylist	*tmp;
	t_mylist	*current;

	current = *stack;
	if (!(*stack) || !stack || (*stack)->next == NULL)
		return ;
	while (current->next && current->next->next)
		current = current->next;
	tmp = current->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	current->next = NULL;
}

void	rr(t_mylist **a, t_mylist **b)
{
	if (a && *a && (*a)->next)
		rotate(a);
	if (b && *b && (*b)->next)
		rotate(b);
}
