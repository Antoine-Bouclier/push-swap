#include <stdio.h>

int	ft_abs(int	min_value)
{
	int	absolute_value;

	if (min_value < 0)
	{
		absolute_value = min_value * -1;
		printf("%d\n", absolute_value);
	}
	else
		absolute_value = min_value;
	return (absolute_value);
}

int	main(void)
{
	int	value;
	int	value2;
	int	min_value;

	value = -15;
	value2 = 10;
	min_value = value;
	printf("Original value : %d & ", value);
	printf("%d\n", value2);
	value += ft_abs(min_value);
	value2 += ft_abs(min_value);
	printf("Absolute value : %d & ", value);
	printf("%d\n", value2);
	value -= ft_abs(min_value);
	value2 -= ft_abs(min_value);
	printf("Original value : %d & ", value);
	printf("%d\n", value2);
	return (0);
}