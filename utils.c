/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 01:47:31 by romukena          #+#    #+#             */
/*   Updated: 2025/07/04 20:55:44 by romukena         ###   ########.fr       */
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
	long int	res;
	int			minus;

	res = 0;
	minus = 1;
	if (!str || *str == '\0')
		return (99999999999999);
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
		if ((minus == -1 && res > -(long)INT_MIN) || (minus == 1 && res > INT_MAX))
			return (99999999999999);
	}
	if (*str != '\0')
		return (99999999999999);
	return ((res * minus));
}

void	free_tableau(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
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

int	put_in_struct(t_mylist **List, char **av)
{
	int	i;
	int	num;

	i = 0;
	if (!av || !av[0])
		return (1);
	while (av[i])
	{
		num = ft_atoi_modif(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		addback(List, num);
		i++;
	}
	return (0);
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
	addback(stack, tmp->value);
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

void	rrr(t_mylist **a, t_mylist **b)
{
	if (a && *a && (*a)->next)
		reverse_rotate(a);
	if (b && *b && (*b)->next)
		reverse_rotate(b);
}

int	check_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi_modif(tab[i]) > INT_MAX || ft_atoi_modif(tab[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

char **get_args(int ac, char **av)
{
	int		i;
	char	**args;

	i = 0;
	if (ac <= 1)
		return (NULL);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (NULL);
		return (args);
	}
	else 
	{
		args = malloc(sizeof(char *) * ac);
		if (!args)
			return (NULL);
		while (i < (ac - 1))
		{
			args[i] = ft_strdup(av[i + 1]);
			if (!args[i])
				return (free_tableau(args), NULL);
			i++;
		}
		args[i] = NULL;
	}
	return (args);
}

int	is_valid(int ac, char **av)
{
	char **tab;
	t_mylist *head;

	head = NULL;
	tab = get_args(ac, av);
	if (!tab)
		return (0);
	if (check_tab(tab))
		return (free_tableau(tab), 0);
	if (put_in_struct(&head, tab))
	{
		free_tableau(tab);
		free_list(&head);
		return (0);
	}
	if (check_duplicates(head))
	{
		free_tableau(tab);
		free_list(&head);
		return (0);
	}
	free_list(&head);
	free_tableau(tab);
	return (1);
}
#include <stdio.h>
#include "push_swap.h"

void test_case(int ac, char **av, char *description)
{
    printf("=== Test: %s ===\n", description);
    printf("Arguments: ");
    for (int i = 1; i < ac; i++)
        printf("\"%s\" ", av[i]);
    printf("\n");

    int result = is_valid(ac, av);
    printf("Result: %s\n\n", result ? "VALID" : "INVALID");
}
#include "push_swap.h"
#include <stdio.h>

void run_test(int ac, char **av, char *test_name) {
    printf("🔹 \033[1;34m%s\033[0m\n", test_name);
    printf("Arguments : ");
    for (int i = 1; i < ac; i++) 
        printf("\"%s\" ", av[i]);
    printf("\n");

    int result = is_valid(ac, av);
    printf("Résultat : %s\n", 
           result ? "\033[1;32mVALID\033[0m" : "\033[1;31mINVALID\033[0m");

    // Test Valgrind intégré
    printf("Valgrind : ");
    fflush(stdout);
    char cmd[512];
    snprintf(cmd, sizeof(cmd), 
             "valgrind --leak-check=full --quiet ./push_swap %s 2>&1 | grep -E 'ERROR SUMMARY|LEAK SUMMARY'", 
             av[1] ? av[1] : "");
    system(cmd);
    printf("\n────────────────────\n");
}

int main(void) {
    // 1. Cas normal
    char *normal[] = {"./push_swap", "1", "2", "3"};
    run_test(4, normal, "Cas standard (valide)");

    // 2. Doublons
    char *dupes[] = {"./push_swap", "1", "1", "2"};
    run_test(4, dupes, "Doublons (invalide)");

    // 3. Overflow
    char *overflow[] = {"./push_swap", "2147483648"};
    run_test(2, overflow, "Overflow INT_MAX");

    // 4. Caractère invalide
    char *invalid[] = {"./push_swap", "1", "a", "3"};
    run_test(4, invalid, "Caractère non-numérique");

    // 5. Chaîne vide
    char *empty[] = {"./push_swap", ""};
    run_test(2, empty, "Chaîne vide");

    return 0;
}