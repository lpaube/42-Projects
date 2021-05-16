/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:02:37 by laube             #+#    #+#             */
/*   Updated: 2021/05/13 17:05:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

#define	BLUE "\033[34m"
#define	RESET "\033[0m"
#define	RED "\033[31m"
#define CYAN "\033[36m"

/* MAIN FUNCTIONS */
void	test_ft_memset(void)
{
	printf(BLUE "	*** ft_memset ***\n" RESET);
	char *str1 = malloc(8);
	char *str2 = malloc(8);
	int i;
	int	state;
	size_t len;
	int c;

	/* Test 1*/
	len = 7;
	c = '$';
	i = 0;
	state = 0;
	printf("Test 1: ");
	str1 = ft_memset(str1, c, len);
	str2 = memset(str2, c, len);
	while ((size_t)i < len)
	{
		if (str1[i] != str2[i])
		{
			state = 1;
			printf(RED "Returns: %c | Should be: %c\n" RESET, str1[i], str2[i]);
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");

	/* Test 2*/
	len = 8;
	c = 'a';
	i = 0;
	state = 0;
	printf("Test 2: ");
	str1 = ft_memset(str1, c, len);
	str2 = memset(str2, c, len);
	while ((size_t)i < len)
	{
		if (str1[i] != str2[i])
		{
			state = 1;
			printf(RED "Returns: %c | Should be: %c\n" RESET, str1[i], str2[i]);
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");
	printf("\n");
}

void	test_ft_bzero(void)
{
	printf(BLUE "	*** ft_bzero ***\n" RESET);
	char *str1 = malloc(8);
	char *str2 = malloc(8);
	int i;
	int	state;
	size_t len;

	/* Test 1*/
	len = 7;
	i = 0;
	state = 0;
	printf("Test 1: ");
	str1[1] = 'a';
	str2[1] = 'a';
	ft_bzero(str1, len);
	bzero(str2, len);
	while ((size_t)i < len)
	{
		if (str1[i] != str2[i])
		{
			state = 1;
			printf(RED "Returns: %c | Should be: %c\n" RESET, str1[i], str2[i]);
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");

	/* Test 2*/
	len = 0;
	i = 0;
	state = 0;
	printf("Test 2: ");
	str1[1] = 'a';
	str2[1] = 'a';
	ft_bzero(str1, len);
	bzero(str2, len);
	while ((size_t)i < len)
	{
		if (str1[i] != str2[i])
		{
			state = 1;
			printf(RED "Returns: %c | Should be: %c\n" RESET, str1[i], str2[i]);
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");
	printf("\n");
}

void	test_ft_memcpy(void)
{
	printf(BLUE "	*** ft_memcpy ***\n" RESET);
	char	*ft_res = malloc(10);
	char	*res = malloc(10);
	char	*src = malloc(10);
	src = "This is y";

	/* Test 1 */
	printf("Test 1: ");
	ft_res = ft_memcpy(ft_res, src, 10);
	res = memcpy(res, src, 10);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	ft_res = malloc(1);
	res = malloc(1);
	src = malloc(10);
	printf("Test 2: ");
	ft_res = ft_memcpy(ft_res, src, 10);
	res = memcpy(res, src, 10);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 3 */
	ft_res = malloc(10);
	res = malloc(10);
	src = malloc(1);
	src = "";
	printf("Test 3: ");
	ft_res = ft_memcpy(ft_res, src, 10);
	res = memcpy(res, src, 10);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_memccpy(void)
{
	printf(BLUE "	*** ft_memccpy ***\n" RESET);
	char	*ft_res = malloc(10);
	char	*res = malloc(10);
	char	*src = malloc(10);
	int		c;
	src = "This is y";

	/* Test 1 */
	printf("Test 1: ");
	c = 'y';
	ft_res = ft_memccpy(ft_res, src, c, 10);
	res = memccpy(res, src, c, 10);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	char	*ft_res3 = malloc(10);
	char	*res3 = malloc(10);
	printf("Test 2: ");
	ft_res = ft_memccpy(ft_res3, src, c, 10);
	res = memccpy(res3, src, c, 10);
	if (strcmp(ft_res3, res3) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res3, res3);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_memmove(void)
{
	printf(BLUE "	*** ft_memmove ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	char src[100] = "Testing";
	char dst[100] = "Attention";
	size_t len = 15;
	char *res = ft_memmove(dst, src, len);
	if (strcmp(res, dst) != 0 && res[1] != 'e')
		printf(RED "Returns: %s | Should be: Testing\n" RESET, res);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_memchr(void)
{
	printf(BLUE "	*** ft_memchr ***\n" RESET);

	/* Test 1 */
	printf("Test 1: ");
	char *res1;
	char *ft_res1;
	char s1[] = "okay yes";
	int c1 = 'k';
	size_t n1 = 4;
	res1 = memchr(s1, c1, n1);
	ft_res1 = ft_memchr(s1, c1, n1);
	if (strcmp(res1, ft_res1) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, res1, ft_res1);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	char *res2;
	char *ft_res2;
	char s2[] = "WOWZERS";
	int c2 = 'k';
	size_t n2 = 4;
	res2 = memchr(s2, c2, n2);
	ft_res2 = ft_memchr(s2, c2, n2);
	if (res2 == NULL || ft_res2 == NULL)
		printf("OK\n");
	else if (strcmp(res2, ft_res2) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, res2, ft_res2);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_memcmp(void)
{
	printf(BLUE "	*** ft_memcmp ***\n" RESET);

	/* Test 1 */
	printf("Test 1: ");
	char s1[] = "What is this?";
	char s2[] = "What is that?";
	size_t n = 13;
	int res = memcmp(s1, s2, n);
	int ft_res = ft_memcmp(s1, s2, n);
	if (res != ft_res)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	char s3[] = "";
	char s4[] = "";
	size_t n1 = 0;
	res = memcmp(s3, s4, n1);
	ft_res = ft_memcmp(s3, s4, n1);
	if (res != ft_res)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_res, res);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_strlen(void)
{
	printf(BLUE "	*** ft_strlen ***\n" RESET);
	char	*str;
	int		ft_res;
	int		res;

	/* Test 1 */
	printf("Test 1: ");
	str = "This has some letters0.";
	ft_res = ft_strlen(str);
	res = strlen(str);
	if (ft_res != res)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	str = "";
	ft_res = ft_strlen(str);
	res = strlen(str);
	if (ft_res != res)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_res, res);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_strlcpy(void)
{
	printf(BLUE "	*** ft_strlcpy ***\n" RESET);

	/* Test 1 */
	printf("Test 1: ");
	const char *src = "What is this wow";
	size_t dstsize = 16;
	char dst[dstsize + 1];
	char ft_dst[dstsize + 1];
	int	ft_res = ft_strlcpy(ft_dst, src, dstsize);
	int	res = strlcpy(dst, src, dstsize);
	if (ft_res != res)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	if (strcmp(dst, ft_dst) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_dst, dst);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_strlcat(void)
{
	printf(BLUE "	*** ft_strlcat ***\n" RESET);

	/* Test 1 */
	printf("Test 1: ");
	char buffer[] = "What is this wow";
	char buffa[] = "What is this wow";
	const char src[] = ", hell";
	size_t dstsize = 30;
	char dst[dstsize];
	char ft_dst[dstsize];

	strcpy(ft_dst, buffer);
	strcpy(dst, buffa);

	int	ft_res = ft_strlcat(ft_dst, src, dstsize);
	int	res = strlcat(dst, src, dstsize);
	if (ft_res != res)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	if (strcmp(dst, ft_dst) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_dst, dst);
	else
		printf("OK\n");
	printf("\n");
}

void	test_ft_strchr(void)
{
	printf(BLUE "	*** ft_strchr ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	const char *s = "Here it is";
	int c = 's';
	char *ft_res = ft_strchr(s, c);
	char *res = strchr(s, c);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	const char *s1 = "Here";
	int c1 = 's';
	char *ft_res1 = ft_strchr(s1, c1);
	char *res1 = strchr(s1, c1);
	if (!res1 && !ft_res1)
		printf("OK\n");
	else
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res1, res1);
	printf("\n");
}

void	test_ft_strrchr(void)
{
	printf(BLUE "	*** ft_strrchr ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	const char *s = "Here it is";
	int c = 's';
	char *ft_res = ft_strrchr(s, c);
	char *res = strrchr(s, c);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	const char *s1 = "Here";
	int c1 = 's';
	char *ft_res1 = ft_strrchr(s1, c1);
	char *res1 = strrchr(s1, c1);
	if (!res1 && !ft_res1)
		printf("OK\n");
	else
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res1, res1);
	printf("\n");
}

void	test_ft_strnstr(void)
{
	printf(BLUE "	*** ft_strnstr ***\n" RESET);

	/* Test 1 */
	printf("Test 1: ");
	const char *haystack = "Well this is hay.";
	const char *needle = "is";
	size_t len = 20;
	char *ft_res = ft_strnstr(haystack, needle, len);
	char *res = strnstr(haystack, needle, len);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	const char *haystack2 = "Well this is hay.";
	const char *needle2 = "is";
	size_t len2 = 2;
	char *ft_res2 = ft_strnstr(haystack2, needle2, len2);
	char *res2 = strnstr(haystack2, needle2, len2);
	if (!ft_res2 && !res2)
		printf("OK\n");
	else
		printf(RED "Wrong! Should return NULL\n" RESET);
	printf("\n");
}

void	test_ft_strncmp(void)
{
	printf(BLUE "	*** ft_strncmp ***\n" RESET);
	int	ft_num;
	int	c_num;
	size_t	n;

	/* Test 1 */
	char	*s1 = "Hello There";
	char	*s2 = "Hell";
	n = 5;
	ft_num = ft_strncmp(s1, s2, n);
	c_num = strncmp(s1, s2, n);
	printf("Test 1: ");
	if (ft_num != c_num)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	}
	else if (ft_num == c_num)
	{
		printf("OK\n");
	}

	/* Test 2 */
	n = 0;
	printf("Test 2: ");
	if (ft_num != c_num)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	}
	else if (ft_num == c_num)
	{
		printf("OK\n");
	}

	/* Test 3 */
	n = 20;
	s1 = "What is this";
	s2 = "What is this";
	ft_num = ft_strncmp(s1, s2, n);
	c_num = strncmp(s1, s2, n);
	printf("Test 3: ");
	if (ft_num != c_num)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	}
	else if (ft_num == c_num)
	{
		printf("OK\n");
	}

	/* Test 4 (negative) */
	n = 20;
	s1 = "Wha";
	s2 = "What is this";
	ft_num = ft_strncmp(s1, s2, n);
	c_num = strncmp(s1, s2, n);
	printf("Test 4: ");
	if (ft_num != c_num)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	}
	else if (ft_num == c_num)
	{
		printf("OK\n");
	}

	/* Test 5 (negative) */
	n = 20;
	s1 = "Whaa is this";
	s2 = "What is this";
	ft_num = ft_strncmp(s1, s2, n);
	c_num = strncmp(s1, s2, n);
	printf("Test 5: ");
	if (ft_num != c_num)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	}
	else if (ft_num == c_num)
	{
		printf("OK\n");
	}
	printf("\n");
}

void	test_ft_atoi(void)
{
	printf(BLUE "\t*** ft_atoi ***\n" RESET);
	int		ft_num;
	int		c_num;
	
	/* Test 1 */
	printf("Test 1: ");
	char	*str = "542";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");
	
	/* Test 2 */
	printf("Test 2: ");
	str = "-542";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	str = "-2147483648";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	str = "  	-532";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");

	/* Test 5 */
	printf("Test 5: ");
	str = "  	+532";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");

	/* Test 6 */
	printf("Test 6: ");
	str = "  	+ 532";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");

	/* Test 7 */
	printf("Test 7: ");
	str = "  	--532";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");
	
	/* Test 8 */
	printf("Test 8: ");
	str = "  	532dfs";
	ft_num = ft_atoi(str);
	c_num = atoi(str);
	if (ft_num != c_num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, ft_num, c_num);
	else if (ft_num == c_num)
		printf("OK\n");
	printf("\n");
}

void	test_ft_isalpha(void)
{
	printf(BLUE "	*** ft_isalpha ***\n" RESET);
	char	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 'a';
	res_ft = ft_isalpha(c);
	res_c = isalpha(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}

	/* Test 2 */
	printf("Test 2: ");
	c = '\n';
	res_ft = ft_isalpha(c);
	res_c = isalpha(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}

	/* Test 3 */
	printf("Test 3: ");
	c = '9';
	res_ft = ft_isalpha(c);
	res_c = isalpha(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_isalpha(c);
	res_c = isalpha(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}
	printf("\n");
}

void	test_ft_isdigit(void)
{
	printf(BLUE "	*** ft_isdigit ***\n" RESET);
	char	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 'a';
	res_ft = ft_isdigit(c);
	res_c = isdigit(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}

	/* Test 2 */
	printf("Test 2: ");
	c = '\n';
	res_ft = ft_isdigit(c);
	res_c = isdigit(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}

	/* Test 3 */
	printf("Test 3: ");
	c = '9';
	res_ft = ft_isdigit(c);
	res_c = isdigit(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_isdigit(c);
	res_c = isdigit(c);
	if (res_ft != res_c)
	{
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	}
	else if (res_ft == res_c)
	{
		printf("OK\n");
	}
	printf("\n");
}

void	test_ft_isalnum(void)
{
	printf(BLUE "	*** ft_isalnum ***\n" RESET);
	char	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 'a';
	res_ft = ft_isalnum(c);
	res_c = isalnum(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	c = '\n';
	res_ft = ft_isalnum(c);
	res_c = isalnum(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	c = '9';
	res_ft = ft_isalnum(c);
	res_c = isalnum(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_isalnum(c);
	res_c = isalnum(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");
	printf("\n");
}

void	test_ft_isascii(void)
{
	printf(BLUE "	*** ft_isascii ***\n" RESET);
	int	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 'a';
	res_ft = ft_isascii(c);
	res_c = isascii(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	c = '\n';
	res_ft = ft_isascii(c);
	res_c = isascii(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	c = '9';
	res_ft = ft_isascii(c);
	res_c = isascii(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_isascii(c);
	res_c = isascii(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 5 */
	printf("Test 5: ");
	c = 2000;
	res_ft = ft_isascii(c);
	res_c = isascii(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");
	printf("\n");
}

void	test_ft_isprint(void)
{
	printf(BLUE "	*** ft_isprint ***\n" RESET);
	int	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 2;
	res_ft = ft_isprint(c);
	res_c = isprint(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	c = '\n';
	res_ft = ft_isprint(c);
	res_c = isprint(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	c = '9';
	res_ft = ft_isprint(c);
	res_c = isprint(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_isprint(c);
	res_c = isprint(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 5 */
	printf("Test 5: ");
	c = 200;
	res_ft = ft_isprint(c);
	res_c = isprint(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");
	printf("\n");
}

void	test_ft_toupper(void)
{
	printf(BLUE "	*** ft_toupper ***\n" RESET);
	int	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 'a';
	res_ft = ft_toupper(c);
	res_c = toupper(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	c = 'z';
	res_ft = ft_toupper(c);
	res_c = toupper(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	c = 'F';
	res_ft = ft_toupper(c);
	res_c = toupper(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_toupper(c);
	res_c = toupper(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 5 */
	printf("Test 5: ");
	c = 200;
	res_ft = ft_toupper(c);
	res_c = toupper(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");
	printf("\n");
}

void	test_ft_tolower(void)
{
	printf(BLUE "	*** ft_tolower ***\n" RESET);
	int	c;
	int	res_ft;
	int	res_c;

	/* Test 1 */
	printf("Test 1: ");
	c = 'A';
	res_ft = ft_tolower(c);
	res_c = tolower(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	c = 'Z';
	res_ft = ft_tolower(c);
	res_c = tolower(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	c = 'f';
	res_ft = ft_tolower(c);
	res_c = tolower(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	c = -10;
	res_ft = ft_tolower(c);
	res_c = tolower(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");

	/* Test 5 */
	printf("Test 5: ");
	c = 200;
	res_ft = ft_tolower(c);
	res_c = tolower(c);
	if (res_ft != res_c)
		printf(RED "Returns: %d | Should be: %d\n" RESET, res_ft, res_c);
	else if (res_ft == res_c)
		printf("OK\n");
	printf("\n");
}

/* ************************************* */
/*			SUPPORTING FUNCTIONS	     */
/* ************************************* */

void	test_ft_substr(void)
{
	printf(CYAN "	*** ft_substr ***\n" RESET);
	char			*str;
	unsigned int	start;
	size_t			len;
	char			*ft_res;
	char			*res;
	int				state = 0;
	int				i;

	/* Test 1 */
	printf("Test 1: ");
	i = 0;
	str = "Hello what is going on";
	len = 100;
	start = 2;
	ft_res = ft_substr(str, start, len);
	res = "llo what is going on";
	while (res[i])
	{
		if (ft_res[i] != res[i])
		{
			printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
			break;
			state = 1;
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	i = 0;
	str = "Hello what is going on";
	len = 2;
	start = 2;
	state = 0;
	ft_res = ft_substr(str, start, len);
	res = "ll";
	while (res[i])
	{
		if (ft_res[i] != res[i])
		{
			printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
			break;
			state = 1;
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");
	printf("\n");
}

void	test_ft_strjoin(void)
{
	printf(CYAN "	*** ft_strjoin ***\n" RESET);
	char const *s1;
	char const *s2;
	char *ft_res;
	char *res;
	int	state;
	int i;

	/* Test 1 */
	printf("Test 1: ");
	i = 0;
	state = 0;
	s1 = "Hello ";
	s2 = "World";
	ft_res = ft_strjoin(s1, s2);
	res = "Hello World";
	while (res[i])
	{
		if (res[i] != ft_res[i])
		{
			printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
			state = 1;
			break;
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	i = 0;
	state = 0;
	s1 = "";
	s2 = "1";
	ft_res = ft_strjoin(s1, s2);
	res = "1";
	while (res[i])
	{
		if (res[i] != ft_res[i])
		{
			printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
			state = 1;
			break;
		}
		i++;
	}
	if (state == 0)
		printf("OK\n");
	printf("\n");
}

void	test_ft_strtrim(void)
{
	printf(CYAN "	*** ft_strtrim ***\n" RESET);
	char const *s1;
	char const *set;
	char *ft_res;
	char *res;
	int state;
	int i;

	/* Test 1 */
	state = 0;
	i = 0;
	printf("Test 1: ");
	s1 = "okthis should work laaal";
	set = "la";
	ft_res = ft_strtrim(s1, set);
	res = "okthis should work ";
	while (res[i])
	{
		if (res[i] != ft_res[i])
		{
			printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
			state = 1;
			break;
		}
		i++;
	}
	if (res[i] == ft_res[i] && state == 0)
		printf("OK\n");
	else
		printf(RED "Error after \"\\n\"\n");

	/* Test 2 */
	state = 0;
	i = 0;
	printf("Test 2: ");
	s1 = "LaaaWhat the heLl is going opnpp";
	set = "Ladp";
	ft_res = ft_strtrim(s1, set);
	res = "What the heLl is going opn";
	while (res[i])
	{
		if (res[i] != ft_res[i])
		{
			printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
			state = 1;
			break;
		}
		i++;
	}
	if (res[i] == ft_res[i] && state == 0)
		printf("OK\n");
	else
		printf(RED "Error after \"\\n\"");
	printf("\n");
}

void	test_ft_split(void)
{
	printf(CYAN "	*** ft_split ***\n" RESET);
	char const *s;
	char c;
	char **str;
	int	i;

	/* Test 1 */
	printf("Test 1: ");
	s = "hello this is now";
	c = ' ';
	str = ft_split(s, c);
	i = 0;
	if (strcmp(str[0], "hello") != 0 && i == 0)
	{
		printf(RED "Returns '%s' | Should be: 'hello'\n" RESET, str[0]);
		i = 1;
	}
	if (strcmp(str[1], "this") != 0 && i == 0)
	{
		printf(RED "Returns '%s' | Should be: 'this'\n" RESET, str[1]);
		i = 1;
	}
	if (strcmp(str[2], "is") != 0 && i == 0)
	{
		printf(RED "Returns '%s' | Should be: 'is'\n" RESET, str[2]);
		i = 1;
	}
	if (strcmp(str[3], "now") != 0 && i == 0)
	{
		printf(RED "Returns '%s' | Should be: 'now'\n" RESET, str[3]);
		i = 1;
	}
	if (i == 0)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	s = "what is this really?";
	c = 'i';
	str = ft_split(s, c);
	i = 0;
	if (strcmp(str[0], "what ") != 0 && i == 0)
	{
		printf(RED "Returns: '%s' | Should be: 'what '\n" RESET, str[0]);
		i = 1;
	}
	if (strcmp(str[1], "s th") != 0 && i == 0)
	{
		printf(RED "Returns: '%s' | Should be: 's th'\n" RESET, str[1]);
		i = 1;
	}
	if (strcmp(str[2], "s really?") != 0 && i == 0)
	{
		printf(RED "Returns: '%s' | Should be: 's really?'\n" RESET, str[2]);
		i = 1;
	}
	if (i == 0)
		printf("OK\n");
	printf("\n");
}

void	test_ft_itoa(void)
{
	printf(CYAN "	*** ft_itoa ***\n" RESET);
	char	*str;
	int		num;

	/* Test 1 */
	printf("Test 1: ");
	num = INT_MAX;
	str = ft_itoa(num);
	if (atoi(str) != num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, atoi(str), num);
	else if (atoi(str) == num)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	num = INT_MIN + 1;
	str = ft_itoa(num);
	if (atoi(str) != num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, atoi(str), num);
	else if (atoi(str) == num)
		printf("OK\n");

	/* Test 3 */
	printf("Test 3: ");
	num = INT_MIN;
	str = ft_itoa(num);
	if (atoi(str) != num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, atoi(str), num);
	else if (atoi(str) == num)
		printf("OK\n");

	/* Test 4 */
	printf("Test 4: ");
	num = 0;
	str = ft_itoa(num);
	if (atoi(str) != num)
		printf(RED "Returns: %d | Should be: %d\n" RESET, atoi(str), num);
	else if (atoi(str) == num)
		printf("OK\n");
	printf("\n");
}

char	ft_to_upper(unsigned int pos, char c)
{
	(void)pos;
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

void	test_ft_strmapi(void)
{
	printf(CYAN "	*** ft_strmapi ***\n" RESET);
	char	*ft_res;
	char	*init_str;
	char	*res;

	/* Test 1 */
	printf("Test 1: ");
	init_str = "Hello how Are yoU?";
	res = "HELLO HOW ARE YOU?";
	ft_res = ft_strmapi(init_str, ft_to_upper);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else if (strcmp(ft_res, res) == 0)
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	init_str = "";
	res = "";
	ft_res = ft_strmapi(init_str, ft_to_upper);
	if (strcmp(ft_res, res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, ft_res, res);
	else if (strcmp(ft_res, res) == 0)
		printf("OK\n");
	printf("\n");
}

void	test_ft_putchar_fd(void)
{
	printf(CYAN "	*** ft_putchar_fd ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	fflush(stdout);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	ft_putchar_fd('\n', 1);
	printf("\n");
}

void	test_ft_putstr_fd(void)
{
	printf(CYAN "	*** ft_putstr_fd ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	fflush(stdout);
	ft_putstr_fd("OK\n", 1);
	printf("\n");
}

void	test_ft_putendl_fd(void)
{
	printf(CYAN "	*** ft_putendl_fd ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	fflush(stdout);
	ft_putendl_fd("OK", 1);
	printf("\n");
}

void	test_ft_putnbr_fd(void)
{
	printf(CYAN "	*** ft_putnbr_fd ***\n" RESET);
	/* Test 1 */
	printf("Test 1: Should be: 42 | Returns: ");
	fflush(stdout);
	ft_putnbr_fd(42, 1);
	printf("\n");

	/* Test 2 */
	printf("Test 2: Should be: -2147483648 | Returns: ");
	fflush(stdout);
	ft_putnbr_fd(INT_MIN, 1);
	printf("\n");
	printf("\n");
}

void	test_ft_calloc(void)
{
	printf(BLUE "	*** ft_calloc ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	char *ft_res = ft_calloc(5, 5);
	char *res = calloc(5, 5);
	if (ft_res[10] == 0 && res[10] == 0)
		printf("OK\n");
	else
		printf(RED "index 10 does not equal 0\n" RESET);

	/* Test 2 */
	printf("Test 2: ");
	if (ft_res[11] == 0 && res[11] == 0)
		printf("OK\n");
	else
		printf(RED "index 11 does not equal 0\n" RESET);
	printf("\n");
}

void	test_ft_strdup(void)
{
	printf(BLUE "	*** ft_strdup ***\n" RESET);
	/* Test 1 */
	printf("Test 1: ");
	char *src = "This is a copy.";
	char *res = strdup(src);
	char *ft_res = ft_strdup(src);
	if (strcmp(res, ft_res) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, res, ft_res);
	else
		printf("OK\n");

	/* Test 2 */
	printf("Test 2: ");
	char *src2 = "";
	char *res2 = strdup(src2);
	char *ft_res2 = ft_strdup(src2);
	if (strcmp(res2, ft_res2) != 0)
		printf(RED "Returns: %s | Should be: %s\n" RESET, res2, ft_res2);
	else
		printf("OK\n");
	printf("\n");
}

int	main(void)
{
// MAIN FUNCTIONS
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memccpy();
	test_ft_memmove();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strlen();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strnstr();
	test_ft_strncmp();
	test_ft_atoi();
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_calloc();
	test_ft_strdup();

// ADDITIONALS FUNCTIONS
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
}
