/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:53:09 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 06:02:46 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_permutation(int **permutation, int dim);

int	digits_are_different(int d1, int d2, int d3, int d4)
{
	if (d1 == d2 || d1 == d3 || d1 == d4 || d2 == d3 || d2 == d4 || d3 == d4)
		return (0);
	return (1);
}

int	is_valid_matrix(int **mx)
{
	if (! digits_are_different(mx[0][0], mx[0][1], mx[0][2], mx[0][3]))
		return (0);
	if (! digits_are_different(mx[1][0], mx[1][1], mx[1][2], mx[1][3]))
		return (0);
	if (! digits_are_different(mx[2][0], mx[2][1], mx[2][2], mx[2][3]))
		return (0);
	if (! digits_are_different(mx[3][0], mx[3][1], mx[3][2], mx[3][3]))
		return (0);
	if (! digits_are_different(mx[0][0], mx[1][0], mx[2][0], mx[3][0]))
		return (0);
	if (! digits_are_different(mx[0][1], mx[1][1], mx[2][1], mx[3][1]))
		return (0);
	if (! digits_are_different(mx[0][2], mx[1][2], mx[2][2], mx[3][2]))
		return (0);
	if (! digits_are_different(mx[0][3], mx[1][3], mx[2][3], mx[3][3]))
		return (0);
	return (1);
}

int	update_rows(int *rows)
{
	if (rows[0] == 23 && rows[1] == 23 && rows[2] == 23 && rows[3] == 23)
	{
		return (0);
	}
	if (rows[3] < 23)
		rows[3]++;
	else if (rows[2] < 23)
	{
		rows[2]++;
		rows[3] = 0;
	}
	else if (rows[1] < 23)
	{
		rows[1]++;
		rows[2] = 0;
		rows[3] = 0;
	}
	else if (rows[0] < 23)
	{
		rows[0]++;
		rows[1] = 0;
		rows[2] = 0;
		rows[3] = 0;
	}
	return (1);
}

void	set_matrix(int **matrix, int **permutations, int *rows)
{
	matrix[0] = permutations[rows[0]];
	matrix[1] = permutations[rows[1]];
	matrix[2] = permutations[rows[2]];
	matrix[3] = permutations[rows[3]];
}

int	get_next_matrix(int **mx, int **permutations, int *rows)
{
	while (update_rows(rows))
	{
		set_matrix(mx, permutations, rows);
		if (is_valid_matrix(mx))
			return (1);
	}
	return (0);
}	
