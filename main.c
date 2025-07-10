/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:32:18 by romukena          #+#    #+#             */
/*   Updated: 2025/07/10 13:50:02 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_mylist	*stack_a;
	t_mylist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || !is_valid(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (put_in_struct(&stack_a, get_args(ac, av)))
	{
		free_list(&stack_a);
		return (1);
	}
	pushswap(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
