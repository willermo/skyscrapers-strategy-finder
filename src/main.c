/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:34 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 06:04:39 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*get_rules(char *str);
void	init_puzzle(int dim, int ***perms, int **rows, int ***matrix);
void	quit_puzzle(int dim, int *rules, int **perms, int *rows, int **matrix);
int		**find_solution(int **matrix, int **perms, int *rows, int *rules);
void	print_matrix(int **matrix, int dim);
void	putstr(char *str);

int	print_usage_and_exit(void)
{
    putstr("Usage: rush-01 \"col1up col2up col3up col4up col1down");
	putstr(" col2down col3down col4down row1left  row2left row3left");
	putstr(" row4left row1right row2right row3right row4right\"\n");
    return (1);
}

int	main(int argc, char **argv)
{
	int	**perms;
	int	*rows;
	int	**matrix;
	int	*rules;
	int dim;

	dim = 4; //hardcode still needed
	if (argc != 2 || !(rules = get_rules(argv[1])))
        return (print_usage_and_exit());
	init_puzzle(dim, &perms, &rows, &matrix);
	(matrix = find_solution(matrix, perms, rows, rules))
		? print_matrix(matrix, dim)
		: putstr("No solutions found\n");
	quit_puzzle(4, rules, perms, rows, matrix);
	return (0);
}
