CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = philo

SRC = main.c parsing.c philo_init.c philo_routine.c tools.c monitor.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
