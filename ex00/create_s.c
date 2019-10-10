/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:54:54 by jbrigett          #+#    #+#             */
/*   Updated: 2019/08/11 21:24:54 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int		right_num(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] <= '1' && argv[i][j] >= '9'
				&& argv[i][j] != '.' && argv[i][j] != '\0')
				return (1);
			j++;
		}
		if (j != 9)
			return (1);
		i++;
	}
	return (0);
}

int		**create_sud(char **argv)
{
	int i;
	int j;
	int **sud;

	i = 1;
	sud = (int **)malloc(sizeof(int *) * 10);
	while (i < 10)
	{
		sud[i - 1] = (int *)malloc(sizeof(int) * 10);
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				sud[i - 1][j] = 0;
			else
				sud[i - 1][j] = argv[i][j] - '0';
			++j;
		}
		sud[i - 1][j] = '\0';
		++i;
	}
	return (sud);
}

void	free_mem(int **sud)
{
	int i;

	i = 0;
	while (i < 10)
	{
		free(sud[i]);
		i++;
	}
	free(sud);
}

void	print_sud(int **sud)
{
	int		i;
	int		j;
	char	s;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			s = '0' + sud[i][j];
			write(1, &s, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		++i;
	}
	free_mem(sud);
}

int		main(int argc, char **argv)
{
	int **sud;

	if (argc != 10 || right_num(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	sud = create_sud(argv);
	if (!ft_checker(sud))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (solve_sudoku(sud))
		print_sud(sud);
	else
		write(1, "Error\n", 6);
	return (0);
}
