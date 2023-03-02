#include "libft.h"
#include <stdio.h>
#include <string.h>
//strrcharと同じように変える
char *ft_strrchr(const char *s, int c)
{
	size_t count;

	count = 1; //これが0だと下のwhile分で、先頭の文字が確認されなくなる
	while (*s != '\0')
	{
		s++;
		count++;
	}
	if ((char)c == '\0') //cをcharにキャスト！
		return ((char *)s); //これはなくてもいける
	while (count--)
	{
		if (*s == (char)c) //sがchar型だからchar型と比較しないと変になちゃう(これがないと、ft_strrchr(s, 'l'+256))が変になる
			return ((char *)s);
		if (count != 0) //count=0の時にここきちゃうと、文字列の一個前のアドレス行っちゃう
			s--;
	}
	return (NULL);
}

int main(void)
{
	printf("ft_strrchr: %s\n", ft_strrchr("Hello", 'l'));
	printf("strrchr:    %s\n", strrchr("Hello", 'l'));
	printf("----------------\n");

	printf("ft_strrchr: %s\n", ft_strrchr("Hello", '\0'));
	printf("strrchr:    %s\n", strrchr("Hello", '\0'));
	printf("----------------\n");

	printf("ft_strrchr: %s\n", ft_strrchr("", 'l'));
	printf("strrchr:    %s\n", strrchr("", 'l'));
	printf("----------------\n");

	printf("ft_strrchr: %s\n", ft_strrchr("abbbbbbbb", 'a'));
	printf("strrchr:    %s\n", strrchr("abbbbbbbb", 'a'));
	printf("----------------\n");

	printf("ft_strrchr: %s\n", ft_strrchr("Hello", 'a'));
	printf("strrchr:    %s\n", strrchr("Hello", 'a'));
	printf("----------------\n");

	printf("ft_strrchr: %s\n", ft_strrchr("the cake is a lie !\0I'm hidden lol\r\n", ' '));
	printf("strrchr:    %s\n", strrchr("the cake is a lie !\0I'm hidden lol\r\n", ' '));
	printf("----------------\n");

	// s=NULLだとセグフォ
	// printf("ft_strrchr: %s\n", ft_strrchr(NULL, 'a'));
	// printf("strrchr:    %s\n", strrchr(NULL, 'a'));
	// printf("----------------\n");


	char a[] = "aiueo";
	printf("%s : %s\n", "ft", "lib");
	printf("%s : %s\n", ft_strrchr(a, 'a'), strrchr(a, 'a'));
	printf("%s : %s\n", ft_strrchr(a, 'i'), strrchr(a, 'i'));
	printf("%s : %s\n", ft_strrchr(a, 'u'), strrchr(a, 'u'));
	printf("%s : %s\n", ft_strrchr(a, 'e'), strrchr(a, 'e'));
	printf("%s : %s\n", ft_strrchr(a, 'o'), strrchr(a, 'o'));
	printf("%s : %s\n", ft_strrchr(a, 0), strrchr(a, 0));
	printf("%p : %p\n", ft_strrchr(a, 0), strrchr(a, 0));
	printf("%s : %s\n", ft_strrchr(a, 1), strrchr(a, 1));
	printf("%s : %s\n", ft_strrchr(a, 'z'), strrchr(a, 'z'));

	return (0);
}