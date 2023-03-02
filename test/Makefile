NAME = libft.a
SRCS = ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c\
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all: $(NAME)
#target: dependencies
#<tab>commands
#↑みたいに書く
#target-> 実行可能ファイルまたはオブジェクトファイルの名前
#dependencies-> ターゲットファイルを出力するために必要な入力ファイル
#commands-> makeによって実行されるアクション

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
#ar: .aファイルを作成するコマンド
#r:アーカイブにファイルを追加する
#アーカイブが存在しない時に新しいアーカイブを追加する
#ライブラリにシンボルテーブル(ライブラリ内の各関数のアドレスが含まれている)を追加する 

clean: #途中生成物を消す
	rm -f $(OBJS)

fclean: clean #最終生成物を消す
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re 
#例えばcleanってファイルがあったらmake cleanってやってももうcleanってファイルあるから何も起きない
#けどphonyを入れることでそれを防ぐことができる