/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:35:46 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/17 14:02:54 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/matrix.h"
#include "../../includes/vector.h"

t_matrix m_add(t_matrix matrix_a, t_matrix matrix_b)
{
    t_matrix result;

    result.row_a = add(matrix_a.row_a, matrix_b.row_a);
    result.row_b = add(matrix_a.row_b, matrix_b.row_b);
    result.row_c = add(matrix_a.row_c, matrix_b.row_c);

	return (result);
}

t_matrix m_x_m(t_matrix matrix_a, t_matrix matrix_b)
{
    t_matrix result;


    matrix_b = trasp(matrix_b);

    result.row_a.x = dot_prod(matrix_a.row_a, matrix_b.row_a);
    result.row_a.y = dot_prod(matrix_a.row_a, matrix_b.row_b);
    result.row_a.z = dot_prod(matrix_a.row_a, matrix_b.row_c);

    result.row_b.x = dot_prod(matrix_a.row_b, matrix_b.row_a);
    result.row_b.y = dot_prod(matrix_a.row_b, matrix_b.row_b);
    result.row_b.z = dot_prod(matrix_a.row_b, matrix_b.row_c);

    result.row_c.x = dot_prod(matrix_a.row_c, matrix_b.row_a);
    result.row_c.y = dot_prod(matrix_a.row_c, matrix_b.row_b);
    result.row_c.z = dot_prod(matrix_a.row_c, matrix_b.row_c);

    return (result);
}

t_vector m_x_v(t_matrix matrix, t_vector v)
{
    t_vector result;

    result.x = dot_prod(matrix.row_a, v);
    result.y = dot_prod(matrix.row_b, v);
    result.z = dot_prod(matrix.row_c, v);

    return (result);
}
