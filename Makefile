NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = src/main.c src/utils/parsing.c src/utils/utils.c src/utils/create_forks.c src/utils/create_threads.c src/routine/routine.c src/utils/time.c src/monitor/monitor.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
