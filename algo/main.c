#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *tab, int deb, int fin)
{
	int	pivot = tab[fin];
	int i = deb;
	int j = deb;

	while (j < fin)
	{
		if (tab[j] < pivot)
		{
			ft_swap(&tab[i], tab[j]);
			i++;
		}
		j++;
	}
	ft_swap(&tab[i], &tab[fin]);
	return (i);
}