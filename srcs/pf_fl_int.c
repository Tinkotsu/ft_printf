#include "ft_printf.h"

static size_t		count_len(long double n)
{
	size_t len;

	len = 1;
	while (n >= 10.0)
	{
		n /= 10.0;
		++len;
	}
	return (len);
}

static long double	make_temp(size_t len)
{
	long double temp;

	temp = 1.0;
	while (len--)
		temp *= 10.0;
	return (temp);
}

static void push_arr(t_pf *s, char *arr, size_t len, long double n)
{
	int					i;
	long double			temp;
	char				*u_arr;
	unsigned long long	u;

	while (len < 19)
	{
		temp = make_temp(len);
		i = (int)(n / temp);
		*arr = '0' + i;
		n -= temp * (long double)i; 
		++arr;
		--len;
	}
	n = pf_fl_round(s, n); // обработаем округление и вернем оттуда дробную часть с целой частью = 0
	u = (unsigned long long)n; 
	//это число можно использовать для проверки четности для дальнейшенго округления (можно занести в структуру)
	s->fl_u = u; // нужно сделать эту ячейку в структуре
	s->fl_temp = n; //занести 0.дробная часть в структуру (нужно сделать эту ячейку)
	//разумнее сохранить дробную часть в pf_fl_round
	u_arr = pf_u(&u);
	arr = ft_strcat(arr, u_arr);
	ft_strdel(&u_arr);
	return (n);
}

char 				*pf_fl_int(t_pf *s, long double n)
{
	char				*arr;
	size_t				len;

	len = count_len(n);
	arr = ft_strnew(len + d1.d_parts.sign); // нужно сделать юнион в хедере
	if (d1.d_parts.sign)
	{
		n *= -1.0; //сделать костыль для минимального лонг дабла?
		*arr++ = '-';
	}
	push_arr(s, arr, len, n);
	return (arr);
}