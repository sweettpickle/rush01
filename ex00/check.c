/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:58:45 by cdoreah           #+#    #+#             */
/*   Updated: 2019/08/11 23:21:49 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_str(int **mas, int i, int j, int num)
{
	int c;

	c = 0;
	while (c < 9)
	{
		if ((mas[i][c] == num) && (j != c) && (num != 0))
			return (0);
		c++;
	}
	c = 0;
	while (c < 9)
	{
		if ((mas[c][j] == num) && (i != c) && (num != 0))
			return (0);
		c++;
	}
	return (1);
}

int		ft_checker(int **sud)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (ft_check_str(sud, i, j, sud[i][j]) == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
