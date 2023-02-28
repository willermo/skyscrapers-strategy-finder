/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:39:11 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 04:36:20 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_matrix(int **mat, int n);

int	visible_left_boxes(int *row)
{
	int	visibles;
	int	max;
	int	i;

	visibles = 1;
	i = 0;
	max = row[i++];
	while (i < 4)
	{
		if (row[i] > max)
		{
			max = row[i];
			visibles++;
		}
		i++;
	}
	return (visibles);
}

int	visible_right_boxes(int *row)
{
	int	visibles;
	int	max;
	int	i;

	visibles = 1;
	i = 3;
	max = row[i--];
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			visibles++;
		}
		i--;
	}
	return (visibles);
}

int	row_is_valid(int *row, int left, int right)
{
	if (left != visible_left_boxes(row))
		return (0);
	if (right != visible_right_boxes(row))
		return (0);
	return (1);
}

int	is_correct(int **permutation, int *rules)
{
	int	*row;
	int	row_n;

	row_n = 0;
	while (row_n < 4)
	{
		row = permutation[row_n];
		if (! row_is_valid(row, rules[8 + row_n], rules[12 + row_n]))
			return (0);
		row_n++;
	}
	ft_swap_matrix(permutation, 4);
	row_n = 0;
	while (row_n < 4)
	{
		row = permutation[row_n];
		if (! row_is_valid(row, rules[0 + row_n], rules[4 + row_n]))
		{
			ft_swap_matrix(permutation, 4);
			return (0);
		}
		row_n++;
	}
	ft_swap_matrix(permutation, 4);
	return (1);
}
