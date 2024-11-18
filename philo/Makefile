FLAGS = -Wall -Wextra - Werror -pthread -fsanitize=thread
CC = cc
NAME = philo

SRC = main.c parsing.c philo_init.c philo_routine.c tools.c monitor.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DEBUG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all
.SECONDARY: $(OBJ)
