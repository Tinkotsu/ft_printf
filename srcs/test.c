#include "../includes/ft_printf.h"
#include <limits.h>

typedef union {
	double d;
	struct {
		unsigned long int mantisa : 52;
		unsigned long int exponent : 11;
		unsigned long int sign : 1;
	} d_parts;
} cast_d;

typedef union {
	float f;
	struct {
		unsigned long int mantisa : 23;
		unsigned long int exponent : 8;
		unsigned long int sign : 1;
	} f_parts;
} cast_f;

char *to_binary(unsigned long int n)
{
	char				*arr;
	int					len;
	unsigned long int	nb;

	len = 1;
	nb = n;
	while (nb /= 2)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = n % 2 + 48;
	while (n /= 2)
		arr[--len] = n % 2 + 48;
	return (arr);
}

int main(void) {
	cast_d d1;
	cast_f f1;

	d1.d = 0.15625;
	f1.f = 0.15625;
	printf("sign = %s\n", to_binary(d1.d_parts.sign));
	printf("exponent = %s\n", to_binary(d1.d_parts.exponent));
	printf("mantisa = %s\n", to_binary(d1.d_parts.mantisa));
	printf("_________________________\n");
	printf("sign = %s\n", to_binary(f1.f_parts.sign));
	printf("exponent = %s\n", to_binary(f1.f_parts.exponent));
	printf("mantisa = %s\n", to_binary(f1.f_parts.mantisa));
}
/*int		main(void)
{
	int		n;

	n = printf("%#.o, %#.0o", 0, 0);
	printf("%d\n", n);

	n = ft_printf("%#.o, %#.0o", 0, 0);
	ft_printf("%d\n", n);

	printf("_________________________\n");



	return (1);
}*/
