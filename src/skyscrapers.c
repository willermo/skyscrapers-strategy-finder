/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:34 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 19:55:29 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validate(char *str);
int		*get_rules(int dim, char *str);
void	init_puzzle(int dim, int ***perms, int **rows, int ***matrix);
void	quit_puzzle(int dim, int *rules, int **perms, int *rows, int **matrix);
int		**find_solution(int dim, int **matrix, int **perms, int *rows, int *rules);
void	print_matrix(int **matrix, int dim);
void	putstr(char *str);

int	print_usage_and_exit(void)
{
    putstr("Usage: skyscrapers \"col1up col2up ... colnup col1down ...");
	putstr(" colndown row1left  ... rownleft row1right ... rownright\"\n");
    return (1);
}

int	main(int argc, char **argv)
{
	int	**perms;
	int	*rows;
	int	**matrix;
	int	*rules;
	int dim;

	//dim = 4; //hardcode still needed
	if (argc != 2 || !(dim = validate(argv[1]) / 4))
        return (print_usage_and_exit());
	rules = get_rules(dim, argv[1]);
	init_puzzle(dim, &perms, &rows, &matrix);
	(matrix = find_solution(dim, matrix, perms, rows, rules))
		? print_matrix(matrix, dim)
		: putstr("No solutions found\n");
	quit_puzzle(dim, rules, perms, rows, matrix);
	return (0);
}
