/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:32:18 by romukena          #+#    #+#             */
/*   Updated: 2025/07/12 18:41:20 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_mylist *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_mylist	*stack_a;
	t_mylist	*stack_b;
	char		**args;

	stack_a = NULL;
	stack_b = NULL;
	args = get_args(ac, av);
	if (!args || ac < 2 || !is_valid(ac, av))
	{
		if (args)
			free_tableau(args);
		write(2, "Error\n", 6);
		return (1);
	}
	if (put_in_struct(&stack_a, args))
	{
		free_tableau(args);
		free_list(&stack_a);
		return (1);
	}
	free_tableau(args);
	pushswap(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
