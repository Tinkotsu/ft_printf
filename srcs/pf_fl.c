#include "ft_printf.h"

static size_t	count_len(long double n)
{
	size_t	len;

	len = 0;
	while (n > 0.0)
	{
		n -= (long double)(int)(n * 10.0); 
		++len;
	}
	return (len);
}

static char 	*pf_fl_fr(long double n)
{
	char	*arr;
	size_t	len;
	int		i;

	len = count_len(n);
	arr = ft_strnew(len);
	while (len--)
	{
		i = (int)(n * 10.0);
		*arr++ = '0' + (int)(n * 10.0);
		n -= (long double)i; 
	}
	return (arr);
}

char 		*pf_fl(t_pf *s, long double n)
{
	char *res;
	char *fl_int;
	char *fl_fr;

	fl_int = pf_fl_int(s, n);
	fl_fr = pf_fl_fr(n);
	n = s->fl_temp; // получаем дробную часть с целой частью = 0
	char *res = ft_strjoin(fl_int, ".");
	char *res = ft_strjoin(res, fl_fr);
	ft_strdel(&fl_int);
	ft_strdel(&fl_fr);
	return (res);
}