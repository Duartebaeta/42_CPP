NAME := file

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

PATH_SRC := ./
PATH_OBJ := ./obj/

SRCS := $(PATH_SRC)/main.cpp

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_SRC)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(PATH_OBJ)
	@rm -f $(NAME)
	@rm *.replace

re: fclean all

.PHONY:	all clean fclean re