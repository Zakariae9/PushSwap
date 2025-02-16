FLAGS = -Wall -Werror -Wextra -g
SRC = check_input_1d.c moves2.c sorting_fundamenals.c delete_return_element.c nodes.c\
swap2top_elemenets.c inputmorethanstr.c rank.c pop_then_push.c\
moves1.c libft_functions1.c libft_functions2.c ft_split.c main.c utils.c

#don't forget remove man.c becouse you just test your program
OBJS = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
