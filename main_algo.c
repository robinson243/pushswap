/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:19 by romukena          #+#    #+#             */
/*   Updated: 2025/07/08 13:27:13 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/* Principe de Quick Sort dans Push_swap

	Choisis un pivot (souvent la mÃ©diane ou un quartile).

	Pousse dans b tous les Ã©lÃ©ments infÃ©rieurs au pivot.

	Garde dans a les Ã©lÃ©ments supÃ©rieurs ou Ã©gaux.

	RÃ©pÃ¨te le processus rÃ©cursivement dans chaque pile.

	Ã€ la fin, remonte les Ã©lÃ©ments de b vers a en les triant (souvent les plus grands dâ€™abord).

*/

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

int partition(int *tab, int deb, int fin)
{
	int pivot = tab[fin];
	int i = deb;
	int j = deb;

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
	return i;
}


void	qsort(int *tab, int deb, int fin)
{
	int	p;
	if (deb < fin)
	{
		p = partition(tab, deb, fin);
		qsort(tab, deb, p-1);
		qsort(tab, p + 1, fin);
	}
	
}

int	*get_array(t_mylist *a, int	size)
{
	int	*tab;
	int	i;
	size = countlist(&a);
	tab = malloc(sizeof(int) * size);
	i = 0;
	while (a)
	{
		tab[i] = a->value;
		a = a->next;
	}
}