/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:31:40 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 17:32:05 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					i;
	int					a;
	unsigned long long	num;

	i = 0;
	num = 0;
	a = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = a * -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (num > __LONG_LONG_MAX__ || i >= 19)
			return (a == -1 ? 0 : -1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * a);
}
