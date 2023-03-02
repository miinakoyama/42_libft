#include "libft.h"
#include <string.h>
#include <stdio.h>

// s1と s2をn 文字比べて
// s1が小さい場合　　→負の値
// s1とs2が同じ場合  →0
// 1が大きい場合　　  →正の値
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *ns1;
	const unsigned char *ns2;

	if (n == 0) //s1かs2がNULLでn=0の時は0になる(これないとセグフォ)
		return (0);
	ns1 = (const unsigned char *)s1;
	ns2 = (const unsigned char *)s2;
	while ((*ns1 != '\0' || *ns2 != '\0') && n--) //*ns2 != '\0'はなくてもできる
	{
		if (*ns1 != *ns2)
			return ((int)(*ns1 - *ns2)); //ここで引き算をしてintにキャストするからからunsinged charにする
		ns1++;
		ns2++;
	}
	return (0);
}

int main(void)
{
	printf("strncmp:    %d\n", strncmp("Hello", "Hello, World", 4));
	printf("ft_strncmp: %d\n", ft_strncmp("Hello", "Hello, World", 4));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp("Hello", "Hello, World", 8));
	printf("ft_strncmp: %d\n", ft_strncmp("Hello", "Hello, World", 8));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp("Hello, World", "Hello", 8));
	printf("ft_strncmp: %d\n", ft_strncmp("Hello, World", "Hello", 8));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp("", "", 4));
	printf("ft_strncmp: %d\n", ft_strncmp("", "", 4));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp("", "", 0));
	printf("ft_strncmp: %d\n", ft_strncmp("", "", 0));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp("Hello", "Hello", 0));
	printf("ft_strncmp: %d\n", ft_strncmp("Hello", "Hello", 0));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp(NULL, "Hello", 0));
	printf("ft_strncmp: %d\n", ft_strncmp(NULL, "Hello", 0));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp("Hello", NULL, 0));
	printf("ft_strncmp: %d\n", ft_strncmp("Hello", NULL, 0));
	printf("----------------\n");

	printf("strncmp:    %d\n", strncmp(NULL, NULL, 0));
	printf("ft_strncmp: %d\n", ft_strncmp(NULL, NULL, 0));
	printf("----------------\n");

	return (0);
}