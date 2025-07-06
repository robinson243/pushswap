/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:13:02 by romukena          #+#    #+#             */
/*   Updated: 2025/07/06 13:07:24 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_three(t_mylist **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		swap(stack);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		rotate(stack);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		rotate(stack);
		swap(stack);
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value
		&& (*stack)->value < (*stack)->next->next->value)
	{
		reverse_rotate(stack);
		swap(stack);
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
		reverse_rotate(stack);
}
void	find_two_big(t_mylist **stack_a, t_mylist **stack_b)
{
	t_mylist	*cur;
	int			val;
	
	cur = *stack_a;
	val = cur->value;
	while (cur)
	{
		if (cur->next && val < cur->next->value)
			val = cur->next->value;
		cur = cur->next;
	}
}

void	sort_five(t_mylist **stack_a, t_mylist **stack_b)
{

}

void	test_three_sort(int a, int b, int c)
{
	t_mylist	*stack;

	stack = NULL;
	addback(&stack, a);
	addback(&stack, b);
	addback(&stack, c);
	printf("Before [%d %d %d]: ", a, b, c);
	printlist(stack);
	sort_three(&stack);
	printf("After : ");
	printlist(stack);
	printf("Sorted? %s\n\n", sorted_list(stack) ? "✓" : "✗");
	free_list(&stack);
}

int	main(void)
{
	printf("=== TESTING ALL 3-NUMBER CASES ===\n\n");

	// Toutes les permutations possibles de 3 nombres
	test_three_sort(0, 1, 2); // déjà trié
	test_three_sort(0, 2, 1);
	test_three_sort(1, 0, 2);
	test_three_sort(1, 2, 0);
	test_three_sort(2, 0, 1);
	test_three_sort(2, 1, 0); // ordre inverse

	return (0);
}