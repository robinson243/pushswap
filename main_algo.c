/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:19 by romukena          #+#    #+#             */
/*   Updated: 2025/07/07 21:55:17 by romukena         ###   ########.fr       */
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

int	partition(int *tab, int deb, int fin)
{
	int	pivot;
	int	indice;
	int	i;

	i = 0;
	pivot = tab[fin];
	indice = deb;
	while ((deb + i) < length_tab(tab))
	{
		if (tab[i] <= pivot)
		{
			ft_swap(tab[i], tab[indice]);
			indice++;
		}
		i++;
	}
	ft_swap(tab[indice], tab[fin]);
	return (indice);
	
}

void	ft_swap(int *a, int *b)
{
	int	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int	*qsort(int *tab, int deb, int fin)
{
	int	i;
	int	pivot;
	
	pivot = tab[length_tab(tab) - 1];
	while (tab[i])
	{
		if (tab[i] > pivot)
		{
			deb = i;
		}
		
		i++;
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