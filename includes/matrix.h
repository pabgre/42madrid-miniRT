/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:59:42 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/17 13:39:47 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "vector.h"
typedef struct s_matrix
{
    t_vector row_a;
    t_vector row_b;
    t_vector row_c;
}               t_matrix;

t_matrix mat(t_vector row_a, t_vector row_b, t_vector row_c);
double det(t_matrix matrix);
t_matrix trasp(t_matrix matrix);
t_matrix inverse(t_matrix matrix);
t_matrix m_add(t_matrix matrix_a, t_matrix matrix_b);
t_matrix m_x_m(t_matrix matrix_a, t_matrix matrix_b);
t_vector m_x_v(t_matrix matrix, t_vector v);

#endif
