/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:19 by romukena          #+#    #+#             */
/*   Updated: 2025/07/08 15:54:40 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	length_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *tab, int deb, int fin)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[fin];
	i = deb;
	j = deb;
	while (j < fin)
	{
		if (tab[j] < pivot)
		{
			ft_swap(&tab[i], &tab[j]);
			i++;
		}
		j++;
	}
	ft_swap(&tab[i], &tab[fin]);
	return (i);
}

void	quicksort(int *tab, int deb, int fin)
{
	int	p;

	if (deb < fin)
	{
		p = partition(tab, deb, fin);
		quicksort(tab, deb, p - 1);
		quicksort(tab, p + 1, fin);
	}
}

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

	i = 0;
	chunk_size = (size / chunk_count);
	plus = 0;
	tab = malloc(sizeof(int) * chunk_count);
	if (!tab)
		return (0);
	while (i < chunk_count)
	{
		tab[i] = sorted_tab[chunk_size - 1 + plus];
		i++;
		plus += chunk_size;
	}
	return (tab);
}

int	main(void)
{
	int	sorted_tab[] = {2, 4, 8, 11, 13, 15, 18, 23, 27, 30};
	int	size = sizeof(sorted_tab) / sizeof(int);
	int	chunk_count = 5;
	int	*chunk_limits = get_chunk_limits(sorted_tab, size, chunk_count);

	if (!chunk_limits)
		return (1);

	printf("Chunk limits:\n");
	for (int i = 0; i < chunk_count; i++)
		printf("chunk %d max: %d\n", i + 1, chunk_limits[i]);

	free(chunk_limits);
	return (0);
}