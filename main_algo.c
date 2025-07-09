/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:19 by romukena          #+#    #+#             */
/*   Updated: 2025/07/10 01:11:27 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	*get_sorted_array(t_mylist *a, int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (a)
	{
		tab[i] = a->value;
		a = a->next;
		i++;
	}
	return (tab);
}

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
	int			value;

	cur = *stack;
	while (cur)
	{
		if (cur->value <= nb)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	filter_by_chunks(t_mylist **stack_a, t_mylist **stack_b,
		int *sorted_tab, int size)
{
	int	numberchunks;
	int	i;
	int	*chunk_limits;

	if (size <= 10)
		numberchunks = 4;
	else
		numberchunks = 10;
	chunk_limits = get_chunk_limits(sorted_tab, size, numberchunks);
	if (!chunk_limits)
		return ;
	i = 0;
	while (i < numberchunks)
	{
		while (has_chunk_value(stack_a, chunk_limits[i]))
		{
			if ((*stack_a)->value <= chunk_limits[i])
				push(stack_a, stack_b);
			else
				rotate(stack_a);
		}
		i++;
	}
	free(chunk_limits);
}

/* 
#include <stdio.h>
#include <stdlib.h>

// Prototypes des fonctions que tu as déjà
int countlist(t_mylist *lst);
void pushswap(t_mylist **a, t_mylist **b);
void print_stack(t_mylist *stack);
void free_stack(t_mylist **stack);
void push_front(t_mylist **stack, int value);

// Implémentations simples pour test

void push_front(t_mylist **stack, int value)
{
    t_mylist *node = malloc(sizeof(t_mylist));
    if (!node)
        return;
    node->value = value;
    node->next = *stack;
    *stack = node;
}

void print_stack(t_mylist *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void free_stack(t_mylist **stack)
{
    t_mylist *tmp;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int main(void)
{
    t_mylist *a = NULL;
    t_mylist *b = NULL;

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

    return 0;
}
 */