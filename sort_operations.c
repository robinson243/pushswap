/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:13:02 by romukena          #+#    #+#             */
/*   Updated: 2025/07/08 14:23:24 by romukena         ###   ########.fr       */
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

int	find_smallest(t_mylist **stack_a)
{
	t_mylist	*cur;
	int			val;
	int			i;

	cur = *stack_a;
	i = 0;
	val = cur->value;
	while (cur)
	{
		if (cur && val > cur->value)
			val = cur->value;
		cur = cur->next;
	}
	cur = *stack_a;
	while (cur)
	{
		if (cur && val == cur->value)
			return (i);
		cur = cur->next;
		i++;
	}
	return (i);
}

void	push_to_b(t_mylist **stack_a, t_mylist **stack_b)
{
	int	size;
	int	pos;

	size = countlist(*stack_a);
	pos = find_smallest(stack_a);
	if ((size / 2) >= pos)
	{
		while (pos > 0)
		{
			rotate(stack_a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate(stack_a);
			pos++;
		}
	}
	push(stack_a, stack_b);
}

void	sort_five(t_mylist **stack_a, t_mylist **stack_b)
{
	push_to_b(stack_a, stack_b);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
}
/* #include "push_swap.h"

static void	test_five(const int arr[5])
{
	t_mylist	*a;
	t_mylist	*b;

	a = NULL;
	b = NULL;
	printf("\nTesting: ");
	for (int i = 0; i < 5; i++)
	{
		addback(&a, arr[i]);
		printf("%d ", arr[i]);
	}
	sort_five(&a, &b);
	printf("\nResult:  ");
	printlist(a);
	printf("Sorted: %s | ops: ", sorted_list(a) ? "✓" : "✗");
	// Ici vous pourriez ajouter un compteur d'opérations
}

int	main(void)
{
	printf("=== 5-NUMBER SORT TESTER ===\n");

	// Permutations uniques (sans doublons)
	test_five((int[]){1, 2, 3, 4, 5}); // Déjà trié
	test_five((int[]){5, 4, 3, 2, 1}); // Inverse
	test_five((int[]){2, 4, 1, 5, 3}); // Mélangé aléatoire
	test_five((int[]){3, 1, 5, 2, 4}); // Autre permutation
	test_five((int[]){4, 2, 5, 1, 3}); // Encore différent

	return (0);
}
int main(void)
{
	t_mylist *a = NULL;
	t_mylist *b = NULL;
	addback(&a, 200);
	addback(&a, 878);
	addback(&a, 6);
	addback(&a, 5656);
	addback(&a, 56);
	push_to_b(&a, &b);
	push(&a, &b);
	push_to_b(&a, &b);
	push(&a, &b);
	printlist(a);
} */ 