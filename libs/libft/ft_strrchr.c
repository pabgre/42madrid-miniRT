/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:22:28 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/07 16:49:35 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*out;

	i = 0;
	out = (void*)0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			out = &((char*)s)[i];
		i++;
	}
	if (c == '\0')
	{
		out = &((char*)s)[i];
	}
	return (out);
}