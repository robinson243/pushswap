/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 01:47:31 by romukena          #+#    #+#             */
/*   Updated: 2025/07/02 14:06:54 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int is_space(char c)
{
	if (c == 32 || c == '\f' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v')
		return (1);
	return (0);
}

void free_list(my_list **lst)
{
	my_list *current;
	my_list *data_next;

	current = *lst;
	if (!lst)
		return;
	while (current)
	{
		data_next = current->next;
		free(current);
		current = data_next;
	}
	*lst = NULL;
}

long ft_atoi_modif(char *str)
{
	int i;
	long int res;
	int minus;

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
		if ((minus == -1 && -res < INT_MIN) || (minus == 1 && res > INT_MAX))
			return (99999999999999);
	}
	if (str[i] != '\0')
		return (99999999999999);
	return ((int)(res * minus));
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

my_list *createnode(int value, int index_count)
{
	my_list *node;

	node = malloc(sizeof(my_list));
	node->value = value;
	node->index = index_count;
	node->next = NULL;
	return (node);
}

void addback(my_list **List, int value)
{
	my_list *node;
	my_list *current;

	current = *List;
	node = createnode(value, 0);
	if (*List == NULL)
	{
		*List = node;
		node->next = NULL;
		return;
	}
	while (current->next)
		current = current->next;
	current->next = node;
	node->next = NULL;
}

void put_in_struct(my_list **List, char **av)
{
	int i;
	int num;

	i = 0;
	if (!av || !av[0])
		return;
	while (av[i])
	{
		num = ft_atoi_modif(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return;
		addback(List, num);
		i++;
	}
}

void printlist(my_list *head)
{
	my_list *current;

	current = head;
	while (current)
	{
		printf("la valeur est %d \n", current->value);
		current = current->next;
	}
}

int check_duplicates(my_list *stack)
{
	my_list *cur;
	my_list *nextone;

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

int sorted_list(my_list *stack)
{
	my_list *current;
	my_list *nextone;

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
	int i;
	char **tab;
	my_list *head;
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
void	add_front(my_list **lst, my_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	add_back(my_list **lst, my_list *new)
{
	my_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

int	free_node(my_list *node)
{
	free(node);
	return (0);
}

void	swap(my_list **stack)
{
	my_list	*current;
	int	temp;
	current = *stack;
	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}
void	push(my_list **stack_a, my_list **stack_b)
{
	my_list	*node;
	my_list *tmp;

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
