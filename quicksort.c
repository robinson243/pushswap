/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:10:50 by romukena          #+#    #+#             */
/*   Updated: 2025/07/10 01:11:05 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
