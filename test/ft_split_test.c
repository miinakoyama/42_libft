/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:09:29 by miina             #+#    #+#             */
/*   Updated: 2023/02/19 00:26:49 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	unsigned char *news = s;

	while (n--)
		*news++ = 0;
}

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (!size || !count)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/**
//いくつに分けるか
static size_t ft_wordcount(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			count++;
		while (*s == c)
			s++;
		if (*s != '\0')
			s++;
	}
	if (*(s - 1) == c)
		return (count);
	return (count + 1);
}
*/

// 新しいの
// いくつの単語に分けるかを数える
static size_t ft_wordcount(char const *s, char c)
{
	size_t count;

	if (!s) // s=NULLの時とりあえずwordcountは0にしておく
		return (0);
	count = 0;
	while (*s != '\0')
	{
		while (*s == c) // cを読み飛ばす
			s++;
		if (*s != c && *s != '\0') // cじゃないのが来たらcount++
			count++;
		while (*s != c && *s != '\0') // cじゃないのを読み飛ばす
			s++;
	}
	return (count);
}

// cを読み飛ばす->cじゃない文字(¥0でもない)が来た時点でcount++->cじゃない文字を読み飛ばす

// cを'\0'に置き換える
/*
static char	*ft_changec(char *s, char c)
{
	while (*++s != '\0')
	{
		if (*s = c)
			*s = '\0';
	}
	return (s);
}
*/

//*sからlen文字だけ別の文字列に入れる
static char *ft_strndup(const char *s, size_t len)
{
	char *ans;
	size_t i;

	i = 0;
	ans = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	while (len)
	{
		ans[i] = s[i];
		len--;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// 1単語が何文字かを数える
static size_t ft_wordlen(const char *s, char c)
{
	size_t count;

	count = 0;
	while (*s != c && *s != '\0') // sが終わるかcがくるかまでカウント
	{
		count++;
		s++;
	}
	return (count);
}

// 全部freeする
// ポインタで移動しない方がいい？？
static char **ft_free(char **str)
{
	char **head;

	head = str; // 下のwhileでstrを動かしちゃってるから1番下のfreeように最初のポインタを保存しておく
	if (!str)	// split関数のansのmallocが失敗した時用
		return (NULL);
	while (*str)
	{
		free(*str);
		str++;
	}
	free(head);
	return (NULL);
}

/*
char **ft_split(char const *s, char c)
{
	char **ans;
	char **anscpy;
	size_t wordcount;
	size_t wordlen;

	while (*s == c) // 最初にcがついてたら飛ばす
		s++;
	wordcount = ft_wordcount(s, c);
	if (!(ans = (char **)malloc(sizeof(char *) * (wordcount + 1))) || !s)
		return (NULL);
	anscpy = ans;
	//if (!ans || !s)
	//	return (NULL);
	while (wordcount)
	{
		wordlen = ft_wordlen(s, c); //1単語が何文字か
		if (!(*ans = ft_strndup(s, wordlen))) //1単語分を入れる
			ans = ft_free(ans);
		//if (!ans)
			//ans = ft_free(ans);
		while (wordlen--) s++;
		while (*s == c) s++; // 次の文字列の最初に移る
		ans++; // 次の文字列に行きたい
		wordcount--;
	}
	*ans = NULL;
	return (anscpy);
}
*/

/*
char **ft_split(char const *s, char c)
{
	char **ans;
	char **anscpy;
	size_t wordcount;
	size_t wordlen;

	if (!s)
		return (NULL);
	wordcount = ft_wordcount(s, c);
	while (*s == c)
		s++;
	//s += (*s == c); // 最初のcを飛ばす: これできてない
	ans = (char **)ft_calloc(sizeof(char *), wordcount + 1); //callocの方がいい!!!
	if (!ans || !s) //sがNULLの処理は最初に!!!
		return (NULL);
	anscpy = ans;
	while (wordcount--) //wordcountと同じ回し方(最初にcを飛ばす)
	{
		wordlen = ft_wordlen(s, c);
		*ans = ft_strndup(s, wordlen);
		if (!*ans)
			return(ft_free(ans));
		while (wordlen--)
			s++;
		while (*s == c)
			s++;
		ans++;
	}
	*ans = NULL;
	return (anscpy);
}
*/

// 新しいの
char **ft_split(char const *s, char c)
{
	char **ans;
	char **anscpy;
	size_t wordcount;
	size_t wordlen;

	wordcount = ft_wordcount(s, c); // まずいくつに分けるかを数える
	// if (s) //<-これいらない!!!!(splitはs=NULLの時定義されてないから?)
	ans = (char **)ft_calloc(wordcount + 1, sizeof(char *)); // mallocだと値が初期化されていなくて変な値が入っているかもしれないから初期化した方が安全
	if (!ans || !s)											 // ここでs=NULLの時に割り当てられたのがfreeされてないのが問題だった
		return (ft_free(ans));
	anscpy = ans;
	while (wordcount--)
	{
		while (*s == c) // cを読み飛ばす
			s++;
		wordlen = ft_wordlen(s, c);	   // 1単語の長さを数える
		*ans = ft_strndup(s, wordlen); // 1単語分のメモリ割り当てる(終端文字はこの関数で入れてるから大丈夫)
		if (!*ans)
			return (ft_free(ans));	  // mallocが失敗したら今まで割り当てたのを全部freeする　<-これansじゃなくてanscpyの方がいい
		while (*s != c && *s != '\0') // cじゃないのを読み飛ばす <-これはなくてもおけ??
			s++;
		ans++; // 次の単語にいく
	}
	*ans = NULL;
	return (anscpy);
}

__attribute__((destructor)) static void destructor(void) // leak確認
{
	system("leaks -q a.out");
}

int main(void)
{
	size_t i = 0;
	char **str = ft_split("bbAAbbBBbbCCbb", 'b');
	printf("%s\n", *str);
	printf("%s\n", *(str + 1));
	printf("%s\n", *(str + 2));
	printf("%s\n", *(str + 3));
	printf("----------------\n");

	i = 0;
	char **str1 = ft_split("bbAAbbBBbbCCbbDDbbEE", 'b');
	while (i < 6)
	{
		printf("%s\n", *(str1 + i));
		i++;
	}
	ft_free(str1);
	printf("----------------\n");

	i = 0;
	char **str2 = ft_split("AAbbBBbbCCbbDDbbEEbb", 'b');
	while (i < 6)
	{
		printf("%s\n", *(str2 + i));
		i++;
	}
	ft_free(str2);
	printf("----------------\n");

	i = 0;
	char **str3 = ft_split("  AA123,BB4,C,DD,EEEEEEEE", ',');
	while (i < 6)
	{
		printf("%s\n", *(str3 + i));
		i++;
	}
	ft_free(str3);
	printf("----------------\n");

	//(null)
	i = 0;
	char **str4 = ft_split("\0aa\0bbb", '\0');
	while (i < 1)
	{
		printf("%s\n", *(str4 + i));
		i++;
	}
	ft_free(str4);
	printf("----------------\n");

	i = 0;
	char **str5 = ft_split("      split       this for   me  !       ", ' ');
	while (i < 6)
	{
		printf("%s\n", *(str5 + i));
		i++;
	}
	ft_free(str5);
	printf("----------------\n");

	ft_free(str);

	// 0x0
	//  i = 0;
	//  char **str6 = ft_split(NULL, ' ');

	// 	printf("%p\n", str6);

	return (0);
}
