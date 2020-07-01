#include "../../includes/minirt.h"

size_t		declen(double d)
{
	int			integer;
	size_t		len;
	int			i;

	integer = d;
	len = nbrlen(integer) + 1;
	i = 0;
	while (d - integer)
	{
		d = d * 10;
		integer = d;
		i++;
	}
	len = (d < 0)? len + 1 : len;
	len += (i == 0)? 2 : i;
	return (len);
}
long double ft_atod(const char *str)
{
	int				i;
	long double		intg;
	long double		dec;
	int				sign;
	int				z_len;

	i = 0;
	dec = 0;
	sign = 1;
	z_len = 0;
	while(!(ft_isdigit(str[i])))
	{
		sign = (str[i] == '-') ? sign * -1: sign;
		i++;
	}
	intg = ft_atoi(str + i);
	i += nbrlen(intg);
	if (str[i] == '.')
	{
		i++;		
		dec = ft_atoi(str + i);
		while (str[i] == '0')
		{
			z_len++;
			i++;
		}
	}
	return (intg * sign + (dec / pow(10, nbrlen(dec) + z_len)) * sign);
}