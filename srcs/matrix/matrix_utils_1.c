/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:01:51 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/17 14:01:55 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/matrix.h"
#include "../../includes/vector.h"

t_matrix mat(t_vector row_a, t_vector row_b, t_vector row_c)
{
	t_matrix matrix;

	matrix.row_a = row_a;
	matrix.row_b = row_b;
	matrix.row_c = row_c;

	return(matrix);
}

double det(t_matrix matrix)
{
	double result;

	result = matrix.row_a.x * matrix.row_b.y * matrix.row_c.z;
	result += matrix.row_a.y * matrix.row_b.z * matrix.row_c.x;
	result += matrix.row_a.z * matrix.row_b.x * matrix.row_c.y;

	result -= matrix.row_a.z * matrix.row_b.y * matrix.row_c.x;
	result -= matrix.row_a.y * matrix.row_b.x * matrix.row_c.z;
	result -= matrix.row_a.x * matrix.row_b.z * matrix.row_c.y;

	return (result);
}

t_matrix trasp(t_matrix matrix)
{
	t_matrix result;
	t_vector new_row_a;
	t_vector new_row_b;
	t_vector new_row_c;

	new_row_a = vec(matrix.row_a.x, matrix.row_b.x, matrix.row_c.x);
	new_row_b = vec(matrix.row_a.y, matrix.row_b.y, matrix.row_c.y);
	new_row_c = vec(matrix.row_a.z, matrix.row_b.z, matrix.row_c.z);

	result = mat(new_row_a, new_row_b, new_row_c);
	return (result);
}

t_matrix inverse(t_matrix matrix)
{
	t_matrix result;
	double m_det;

	m_det = det(matrix);

	result.row_a.x = result.row_a.x * (result.row_b.y * result.row_c.z - result.row_b.z * result.row_c.y);
	result.row_a.y = - result.row_a.y * (result.row_b.x * result.row_c.z - result.row_b.z * result.row_c.x);
	result.row_a.z = result.row_a.z * (result.row_b.y * result.row_c.x - result.row_b.y * result.row_c.x);

	result.row_b.x = - result.row_b.x * (result.row_a.y * result.row_c.z - result.row_a.z * result.row_c.y);
	result.row_b.y = result.row_b.y * (result.row_a.x * result.row_c.z - result.row_a.z * result.row_c.x);
	result.row_b.z = - result.row_b.z * (result.row_a.y * result.row_c.x - result.row_a.y * result.row_c.x);

	result.row_a.x = result.row_a.x * (result.row_a.y * result.row_b.z - result.row_a.z * result.row_b.y);
	result.row_a.y = - result.row_a.y * (result.row_a.x * result.row_b.z - result.row_a.z * result.row_b.x);
	result.row_a.z = result.row_a.z * (result.row_a.y * result.row_b.x - result.row_a.y * result.row_b.x);
	return (trasp(result));
}
