/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:26:55 by miina             #+#    #+#             */
/*   Updated: 2023/02/16 02:14:47 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// int ft_isalpha(int c)
// {
//   if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
//     return (1);

//   return (0);
// }

//書き方かえた
int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}


int main(void)
{
  printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
  printf("isalpha('A'): %d\n", isalpha('A'));
  printf("----------------\n");
  printf("ft_isalpha('D'): %d\n", ft_isalpha('D'));
  printf("isalpha('D'): %d\n", isalpha('D'));
  printf("----------------\n");
  printf("ft_isalpha('r'): %d\n", ft_isalpha('r'));
  printf("isalpha('r'): %d\n", isalpha('r'));
  printf("----------------\n");
  printf("ft_isalpha('f'): %d\n", ft_isalpha('f'));
  printf("isalpha('f'): %d\n", isalpha('f'));
  printf("----------------\n");
  printf("ft_isalpha('2'): %d\n", ft_isalpha('2'));
  printf("isalpha('2'): %d\n", isalpha('2'));
  printf("----------------\n");
  printf("ft_isalpha('!'): %d\n", ft_isalpha('!'));
  printf("isalpha('!'): %d\n", isalpha('!'));

  return (0);
}