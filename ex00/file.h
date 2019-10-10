/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:34:21 by cdoreah           #+#    #+#             */
/*   Updated: 2019/08/11 23:24:42 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdlib.h>
# include <unistd.h>

int		square(int **mas, int i, int j, int num);
int		check(int **mas, int i, int j, int num);
int		search_free(int **mas, int *i, int *j);
int		solve_sudoku(int **mas);
int		ft_checker(int **sud);
int		ft_check_str(int **mas, int i, int j, int num);

#endif
