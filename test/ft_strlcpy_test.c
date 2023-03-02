#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

//void *ft_memcpy(void *dst, const void *src, size_t n)
//{
//	char *dstcpy;
//	const char *srccpy;
//
//	dstcpy = dst;
//	srccpy = src;
//	while (n-- > 0)
//		*dstcpy++ = *srccpy++;
//	return (dst);
//}

//size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
//{
//	size_t srcsize;
//
//	srcsize = ft_strlen(src);
//	if (srcsize < dstsize)
//	{
//		while (*src != '\0')
//		{
//			*dst++ = *src++;
//		}
//		*dst = '\0';
//	}
//	else if (srcsize >= dstsize)
//	{
//		ft_memcpy(dst, src, dstsize - 1);
//		dst[dstsize - 1] = '\0';
//	}
//	return (srcsize);
//}

// 文字列をコピーする関数(srcをdstにコピー)
// memmoveとの違い:
// strlcpy→文字列をコピー
// memmove→メモリ領域をコピー
// 複写元の文字列 *src の長さ(バイト数)が size_t 型で返る
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
		return ft_strlen(src);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return i;
}

int main(void)
{
	const char *src = "0123456789";
	char dst1[10];
	char dst2[10];
	printf("strlcpy:    return->%lu, ", strlcpy(dst1, src, 6));
	printf("dst->%s\n", dst1);
	printf("ft_strlcpy: return->%lu, ", ft_strlcpy(dst2, src, 6));
	printf("dst->%s\n", dst2);
	printf("----------------\n");

	const char *src2 = "012345";
	printf("strlcpy:    return->%lu\n", strlcpy(NULL, src2, 0));
	printf("ft_strlcpy: return->%lu\n", ft_strlcpy(NULL, src2, 0));
	printf("----------------\n");

	// セグフォ
	//printf("strlcpy:    return->%lu\n", strlcpy(NULL, NULL, 2));
	//printf("ft_strlcpy: return->%lu\n", ft_strlcpy(NULL, NULL, 2));
	//printf("----------------\n");

	//セグフォ
	//const char *src3 = "012345";
	//printf("strlcpy:    return->%lu\n", strlcpy(NULL, src3, 2));
	//printf("ft_strlcpy: return->%lu\n", ft_strlcpy(NULL, src3, 2));
	//printf("----------------\n");

	const char *src4 = "0123456789";
	char dst3[10];
	char dst4[10];
	printf("strlcpy:    return->%lu, ", strlcpy(dst3, src4, 0));
	printf("dst->%s\n", dst3);
	printf("ft_strlcpy: return->%lu, ", ft_strlcpy(dst4, src4, 0));
	printf("dst->%s\n", dst4);
	printf("----------------\n");

	return (0);
}