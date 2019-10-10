/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:32:30 by cdoreah           #+#    #+#             */
/*   Updated: 2019/08/11 21:32:35 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		square(int **mas, int i, int j, int num)
{
	int a;
	int b;

	i = (i / 3) * 3;
	j = (j / 3) * 3;
	a = i;
	b = j;
	while (i < a + 3)
	{
		j = b;
		while (j < b + 3)
		{
			if (mas[i][j] == num)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check(int **mas, int i, int j, int num)
{
	int c;

	c = 0;
	while (c < 9)
	{
		if (mas[i][c] == num)
			return (0);
		c++;
	}
	c = 0;
	while (c < 9)
	{
		if (mas[c][j] == num)
			return (0);
		c++;
	}
	if (!square(mas, i, j, num))
		return (0);
	return (1);
}

int		search_free(int **mas, int *i, int *j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 9)
	{
		b = 0;
		while (b < 9)
		{
			if (mas[a][b] == 0)
			{
				*i = a;
				*j = b;
				return (1);
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		solve_sudoku(int **mas)
{
	int num;
	int i;
	int j;

	i = 0;
	j = 0;
	num = 1;
	if (search_free(mas, &i, &j) == 0)
		return (1);
	while (num < 10)
	{
		if (!check(mas, i, j, num))
		{
			num++;
			continue ;
		}
		mas[i][j] = num;
		if (solve_sudoku(mas))
			return (1);
		mas[i][j] = 0;
		num++;
	}
	return (0);
}
