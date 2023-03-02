/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:49:12 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 21:27:45 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

//オーバーフローするとき1、しないとき0を返す
static int	check_ov(long ans, char str, int sign)
{
	long ov_div;
	long ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (sign == -1) //マイナスの時はオーバーフローする絶対値が1増えるから+1する
		ov_mod++;
	if (ans > ov_div) //ans*10 > LONG_MAX/MINってことだからこれはもう絶対にオーバーフローする
		return (1);
	else if (ans == ov_div && ov_mod < str - '0') //ansに次のstrをくっつけたやつととLONG_MAX/MINの1桁目だけがい違う時に1桁目をくらべてる
		return (1);
	else
		return (0);
}

//int	ft_atoi(const char *str)
//{
//	int	sign;
//	long	ans;
//
//	ans = 0;
//	sign = 1;
//	while (*str == '\t' || *str == '\n' || *str == '\v' ||
//				*str == '\f' || *str == '\r' || *str == ' ') // 見えないのを飛ばす
//		str++;
//	if (!(ft_isdigit(*str)))
//	{
//		sign = 44 - *str; //+: 1, -: -1
//		if ((sign != 1 && sign != -1) || !ft_isdigit(*(str + 1)))
//			return (0);
//		str++;
//	}
//	while (ft_isdigit(*str))
//	{
//		if (sign == 1 && check_ov(ans, *str, sign))
//			return ((int)LONG_MAX);
//		if (sign == -1 && check_ov(ans, *str, sign))
//			return ((int)LONG_MIN);
//		ans = 10 * ans + (*str - '0');
//		str++;
//	}
//	return ((int)(ans * sign));
//}

//+ならsign=1, -ならsign=-1, +でも-でもないならsign=2に一旦しておく
static int setsign(const char *str)
{
	if (*str == '+' || *str == '-') //ここシンプルにした方がいいかも
		return(44 - *str); //+: 43, -: 45
	else
		return (2);
}

//- か + の符号1つとその直後に続く半角数字（ 0 から 9 ）で構成された「数字」をint型にして返す。数字の前にある空白を除いて、左から順に数字以外（ヌル文字含む）が出現するまで変換し続ける
// 正の方向にオーバーフローした場合には LONG_MAX が返り、 負の方向にオーバーフローした場合には LONG_MIN が返る
int ft_atoi(const char *str)
{
	int sign;
	long ans; //long longにしておいた方がいい

	ans = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
		   *str == '\f' || *str == '\r' || *str == ' ') // 見えないのを飛ばす('\t': タブ, '\n': 改行, '\v': 垂直のタブ, '\f': 改ページ, '\r': 復帰, ' ': 空白)
		str++;
	if (!(ft_isdigit(*str)))
	{
		sign = setsign(str);
		if (sign == 2) //sign=なら先頭が+でも-でも数字でもないから0を返す
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (sign == 1 && check_ov(ans, *str, sign))
			return ((int)LONG_MAX);
		if (sign == -1 && check_ov(ans, *str, sign))
			return ((int)LONG_MIN);
		ans = 10 * ans + (*str - '0'); //ex) 123: 1 -> 1*10+2=12 -> 12*10+3=123
		//ここでansにINT_MAX+1が入る可能性がある(オーバーフローチェックするときにマイナスだとLONG_MAX+1まで許してるから)
		str++;
	}
	return ((int)(ans * sign));
}

int main(void)
{
	char str1[] = "324";
	printf("atoi:    %d\n", atoi(str1));
	printf("ft_atoi: %d\n", ft_atoi(str1));
	printf("----------------\n");

	char str2[] = "-721";
	printf("atoi:    %d\n", atoi(str2));
	printf("ft_atoi: %d\n", ft_atoi(str2));
	printf("----------------\n");

	char str3[] = "--721";
	printf("atoi:    %d\n", atoi(str3));
	printf("ft_atoi: %d\n", ft_atoi(str3));
	printf("----------------\n");

	char str4[] = "abcd";
	printf("atoi:    %d\n", atoi(str4));
	printf("ft_atoi: %d\n", ft_atoi(str4));
	printf("----------------\n");

	char str5[] = "2147483649";
	printf("atoi:    %d\n", atoi(str5));
	printf("ft_atoi: %d\n", ft_atoi(str5));
	printf("----------------\n");

	char str6[] = "-2147483649";
	printf("atoi:    %d\n", atoi(str6));
	printf("ft_atoi: %d\n", ft_atoi(str6));
	printf("----------------\n");

	char str7[] = "  		21";
	printf("atoi:    %d\n", atoi(str7));
	printf("ft_atoi: %d\n", ft_atoi(str7));
	printf("----------------\n");

	char str8[] = "+298";
	printf("atoi: %d\n", atoi(str8));
	printf("ft_atoi: %d\n", ft_atoi(str8));
	printf("----------------\n");

	char str9[] = "\e6050";
	printf("atoi: %d\n", atoi(str9));
	printf("ft_atoi: %d\n", ft_atoi(str9));
	printf("----------------\n");

	char str10[] = "*6050";
	printf("atoi: %d\n", atoi(str10));
	printf("ft_atoi: %d\n", ft_atoi(str10));
	printf("----------------\n");

	char str11[] = " 6050";
	printf("atoi: %d\n", atoi(str11));
	printf("ft_atoi: %d\n", ft_atoi(str11));
	printf("----------------\n");

	char str12[] = "- 6050";
	printf("atoi: %d\n", atoi(str12));
	printf("ft_atoi: %d\n", ft_atoi(str12));
	printf("----------------\n");

	return (0);
}