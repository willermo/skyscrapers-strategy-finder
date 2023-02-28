/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:56:01 by doriani           #+#    #+#             */
/*   Updated: 2023/02/26 20:04:49 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	has_digit(int *permutation, int digit)
{
	if (permutation[0] == digit || permutation[1] == digit \
	|| permutation[2] == digit || permutation[3] == digit)
		return (1);
	return (0);
}

int	is_valid_permutation(int *p)
{
	if (has_digit(p, 1))
		if (has_digit(p, 2))
			if (has_digit(p, 3))
				if (has_digit(p, 4))
					return (1);
	return (0);
}

void	add_permutation(int **address, int *perm)
{
	int	i;
	int	*p;

	i = 0;
	p = (int *) malloc(4 * sizeof(int));
	while (i < 4)
	{
		p[i] = perm[i];
		i++;
	}
	*address = p;
}

void	update_p(int *p)
{
	if (p[3] < 4)
		p[3]++;
	else if (p[2] < 4)
	{
		p[2]++;
		p[3] = 1;
	}
	else if (p[1] < 4)
	{
		p[1]++;
		p[2] = 1;
		p[3] = 1;
	}
	else if (p[0] < 4)
	{
		p[0]++;
		p[1] = 1;
		p[2] = 1;
		p[3] = 1;
	}
}

int	**get_permutations(void)
{
	int	**permutations;
	int	p[4];
	int	i;

	i = 0;
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	permutations = (int **) malloc(24 * sizeof(int *));
	while (i < 24)
	{
		if (is_valid_permutation(p))
			add_permutation(&permutations[i++], p);
		update_p(p);
	}
	return (permutations);
}
