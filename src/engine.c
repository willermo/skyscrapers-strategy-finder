/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:34 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 06:08:13 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	**get_permutations(void);
int	get_next_matrix(int **mx, int **permutations, int *rows);
int	is_correct(int **permutation, int *rules);

void init_puzzle(int dim, int ***permutations, int **rows, int ***matrix)
{
	*permutations = get_permutations();
	*rows = (int *) calloc(dim, sizeof(int));
	*matrix = (int **) malloc(dim * sizeof(int *));
}

void	quit_puzzle(int dim, int *rules, int **permutations, int *rows, int **matrix)
{
	free(rules);
	for(int i = 0; i < dim; i++)
		free(permutations[i]);
	free(permutations);
	if (matrix)
		free(matrix);
	free(rows);
}

int	**find_solution(int **matrix, int **permutations, int *rows, int *rules)
{
	while(get_next_matrix(matrix, permutations, rows)) 
		if (is_correct(matrix, rules))
			return (matrix);
	free(matrix);
	return (0);
}
