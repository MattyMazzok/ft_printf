#include "ft_printf.h"

int	main()
{
	int ret = 0;
	int ret2 = 0;
	ret = ft_printf("C: %s\n", "ciao");
	ret2 = printf("D: %s\n", "ciao");
	printf("M: %d, V: %d\n",ret, ret2);
	return (0);
}
