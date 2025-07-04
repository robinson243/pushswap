/* #include <stdio.h>
#include <limits.h>

long	ft_atoi_modif(char *str);

int	main(void)
{
	char *tests[] = {
		"2147483647",      // INT_MAX
		"2147483648",      // INT_MAX + 1 (overflow)
		"-2147483648",     // INT_MIN
		"-2147483649",     // INT_MIN - 1 (overflow)
		"0",               // zéro
		"-0",              // zéro signé
		"+0",              // zéro signé plus
		"",                // chaîne vide
		"   123",          // espaces avant nombre
		"      ",          // que des espaces
		" -123",           // espaces + signe -
		" +123",           // espaces + signe +
		"123abc",          // caractères invalides après nombre
		"999999999999999", // très grand nombre (overflow)
		NULL
	};

	int i = 0;
	long res;

	while (tests[i])
	{
		res = ft_atoi_modif(tests[i]);
		if (res == 99999999999999)
			printf("ft_atoi_modif(\"%s\") = ERREUR\n", tests[i]);
		else
			printf("ft_atoi_modif(\"%s\") = %ld\n", tests[i], res);
		i++;
	}
	return (0);
}
 */