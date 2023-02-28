/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:34 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 06:11:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_matrix(int **mat, int n)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (i < n)
	{
		x = i;
		y = j;
		while (x < n)
			ft_swap(&mat[i][x++], &mat[y++][j]);
		i++;
		j++;
	}
}

void	print_matrix(int **permutation, int dim)
{
	int		i;
	int		j;
	int		*row;
	char	buf;

	i = 0;
	while (i < dim)
	{
		row = permutation[i];
		j = 0;
		while (j < dim)
		{
			buf = row[j] + '0';
			write(1, &buf, 1);
			if (j < dim - 1)
				write(1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}
