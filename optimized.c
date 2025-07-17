/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:13:40 by romukena          #+#    #+#             */
/*   Updated: 2025/07/16 12:26:08 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_mylist **a, t_mylist **b)
{
    int size = countlist(*a);
    int max_bits = 0;
    int max_index = size - 1;
    while ((max_index >> max_bits) != 0)
        max_bits++;
    for (int i = 0; i < max_bits; i++)
    {
        int j = 0;
        int n = countlist(*a);
        while (j++ < n)
        {
            if ((((*a)->index >> i) & 1) == 0)
            {
                push(a, b, "pb");
                // Option : pour optimiser (500) :
                // if ((*b)->index < size / 2)
                //     rotate(b, "rb");
            }
            else
                rotate(a, "ra");
        }
        while (*b)
            push(b, a, "pa");
    }
}








