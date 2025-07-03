/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 01:47:31 by romukena          #+#    #+#             */
/*   Updated: 2025/07/03 18:50:17 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	is_space(char c)
{
	if (c == 32 || c == '\f' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	free_list(t_mylist **lst)
{
	t_mylist	*current;
	t_mylist	*data_next;

	current = *lst;
	if (!lst)
		return ;
	while (current)
	{
		data_next = current->next;
		free(current);
		current = data_next;
	}
	*lst = NULL;
}

long	ft_atoi_modif(char *str)
{
	int			i;
	long int	res;
	int			minus;

	i = 0;
	res = 0;
	minus = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if ((minus == -1 && - res < INT_MIN) || (minus == 1 && res > INT_MAX))
			return (99999999999999);
	}
	if (str[i] != '\0')
		return (99999999999999);
	return ((int)(res * minus));
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

t_mylist	*createnode(int value, int index_count)
{
	t_mylist	*node;

	node = malloc(sizeof(t_mylist));
	node->value = value;
	node->index = index_count;
	node->next = NULL;
	return (node);
}

void	addback(t_mylist **List, int value)
{
	t_mylist	*node;
	t_mylist	*current;

	current = *List;
	node = createnode(value, 0);
	if (*List == NULL)
	{
		*List = node;
		node->next = NULL;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = node;
	node->next = NULL;
}

void	put_in_struct(t_mylist **List, char **av)
{
	int	i;
	int	num;

	i = 0;
	if (!av || !av[0])
		return ;
	while (av[i])
	{
		num = ft_atoi_modif(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return ;
		addback(List, num);
		i++;
	}
}

void	printlist(t_mylist *head)
{
	t_mylist	*current;

	current = head;
	while (current)
	{
		printf("la valeur est %d \n", current->value);
		current = current->next;
	}
}

int	check_duplicates(t_mylist *stack)
{
	t_mylist	*cur;
	t_mylist	*nextone;

	cur = stack;
	nextone = stack;
	if (!stack)
		return (0);
	while (cur)
	{
		nextone = cur->next;
		while (nextone)
		{
			if (cur->value == nextone->value)
				return (1);
			nextone = nextone->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	sorted_list(t_mylist *stack)
{
	t_mylist	*current;
	t_mylist	*nextone;

	current = stack;
	nextone = stack;
	if (!stack)
		return (1);
	if (!stack->next)
		return (1);
	while (current)
	{
		nextone = current->next;
		if (nextone && current->value > nextone->value)
			return (0);
		current = current->next;
	}
	return (1);
}
/*
int	main(int ac, char **av)
{
	int		i;
	char	**tab;
	t_mylist	*head;

	head = NULL;
	tab = NULL;
	i = 1;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
		{
			free_tab(tab);
		}
			return (0);
		put_in_struct(&head, tab);
		free(tab);
	}
	else if (ac > 2)
	{
		while (i < ac)
		{
			put_in_struct(&head, av[i]);
			i++;
		}
	}
	printList(head);
} */

void	add_front(t_mylist **lst, t_mylist *new)
{
	new->next = *lst;
	*lst = new;
}

int	free_node(t_mylist *node)
{
	free(node);
	return (0);
}

void	swap(t_mylist **stack)
{
	t_mylist	*current;
	int		temp;

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
	addback(stack, tmp);
}

void	rr(t_mylist **a, t_mylist **b)
{
	if (a && *a && (*a)->next)
		rotate(a);
	if (b && *b && (*b)->next)
		rotate(b);
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
