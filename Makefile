NAME	= palindrome

CC	= gcc

RM	= rm -f

SRCS	= ./requirement.c \
	  ./source/get_flag.c \
	  ./source/main.c \
	  ./source/palindrome.c \
	  ./source/source.c \
	  ./source/source2.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
