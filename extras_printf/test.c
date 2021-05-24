#include "../printf/includes/ft_printf.h"

int	main(void)
{
	char	*nice = "ok";
	char	*not_nice = 0;
	// Character (c)
	printf("Char(c):\n");
	printf("real(c): Test1: '%c' | Test2: '%4c' | Test3: '%5c' | Test4: '%-5c' | Test5: '%-*c'\n", 'H', 'H', 'H', 'H', 2, 'A');
	ft_printf("ft(c)  : Test1: '%c' | Test2: '%4c' | Test3: '%5c' | Test4: '%-5c' | Test5: '%-*c'\n", 'H', 'H', 'H', 'H', 2, 'A');
	// String (s)
	printf("\nString(s):\n");
	printf("real(s): Test1: '%s' | Test2: '%.4s' | Test3: '%6.4s' | Test4: '%-6.4s' | Test5: '%4.6s' | Test6: '%*.*s'\n", "Hello", "Hello", "Hello", "Hello", "Hello", 6, 3, "Hello");
	ft_printf("ft(s)  : Test1: '%s' | Test2: '%.4s' | Test3: '%6.4s' | Test4: '%-6.4s' | Test5: '%4.6s' | Test6: '%*.*s'\n", "Hello", "Hello", "Hello", "Hello", "Hello", 6, 3, "Hello");
	// Pointer (p)
	printf("\nPointer(p):\n");
	printf("real(p): Test1: '%p' | Test2: '%14p' | Test3: '%-14p' | Test4: '%*p'\n", nice, not_nice, nice, 14, nice);
	ft_printf("ft(p)  : Test1: '%p' | Test2: '%14p' | Test3: '%-14p' | Test4: '%*p'\n", nice, not_nice, nice, 14, nice);
	// Integer (d)
	printf("\nInteger(d):\n");
	printf("real(d): Test1: '%10.d' | Test2: '%015.4d' | Test3: '%-10.7d' | Test4: '%-*.*d' | Test5: '%010.8d' | Test 6: '%2.d'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	ft_printf("ft(d)  : Test1: '%10.d' | Test2: '%015.4d' | Test3: '%-10.7d' | Test4: '%-*.*d' | Test5: '%010.8d' | Test 6: '%2.d'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	// Integer (i)
	printf("\nInteger(i):\n");
	printf("real(i): Test1: '%10.i' | Test2: '%015.4i' | Test3: '%-10.7i' | Test4: '%-*.*i' | Test5: '%010.8i' | Test 6: '%2.i'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	ft_printf("ft(i)  : Test1: '%10.i' | Test2: '%015.4i' | Test3: '%-10.7i' | Test4: '%-*.*i' | Test5: '%010.8i' | Test 6: '%2.i'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	// Unsigned Integer (u)
	printf("\nUnsigned Integer(u):\n");
	printf("real(i): Test1: '%10.u' | Test2: '%015.4u' | Test3: '%-10.7u' | Test4: '%-*.*u' | Test5: '%010.8u' | Test 6: '%2.u'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	ft_printf("ft(i)  : Test1: '%10.u' | Test2: '%015.4u' | Test3: '%-10.7u' | Test4: '%-*.*u' | Test5: '%010.8u' | Test 6: '%2.u'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	// Hexadecimal (x)
	printf("\nHexadecimal (x & X):\n");
	printf("real(x): Test1: '%12x' | Test2: '%-12X' | Test3: '%12.5x' | Test4: '%012.5X'%% |%%%% Test5: '%012x'\n", 79527482, 79527482, 79527482, 79527482, -79527482);
	ft_printf("ft(x)  : Test1: '%12x' | Test2: '%-12X' | Test3: '%12.5x' | Test4: '%012.5X'%% |%%%% Test5: '%012x'\n", 79527482, 79527482, 79527482, 79527482, -79527482);

	ft_printf("\nd FT  : '%0-8.5d'\n", 34);
	printf("d REAL: '%0-8.5d'\n", 34);

	ft_printf("\nd FT  : '%.0d'\n", 0);
	printf("d REAL: '%.0d'\n", 0);

	ft_printf("\nx FT  : '%x'\n", 0);
	printf("x REAL: '%x'\n", 0);

	ft_printf("\nu FT  : '%.20u'\n", 4294967295u);
	printf("u REAL: '%.20u'\n", 4294967295u);
}
