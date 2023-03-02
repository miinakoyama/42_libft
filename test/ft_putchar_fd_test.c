/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:43:10 by miina             #+#    #+#             */
/*   Updated: 2023/02/17 16:49:00 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

// 指定されたファイルディスクリプタで文字cを出力
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
//write関数----->fdへ、bufに格納されているbyte分のデータを書きこむ
//write(int fd, *buf, byte)
//fd: ファイルディスクリプタ(照準出力->1, 入力->0, エラー->2)
//*buf: 書き込むデータが格納されている領域のポインタ(データアドレス)
//ファイルに書き込むバイト数


int main(void)
{
	int fd;
	char c = 'A';

	fd = open("output_putchar.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
}