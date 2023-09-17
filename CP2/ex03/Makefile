NAME := fixed

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

PATH_SRC := ./src
PATH_OBJ := ./obj
PATH_INCL := ./incl

INCL := $(PATH_INCL)/Fixed.hpp $(PATH_INCL)/Point.hpp $(PATH_INCL)/bsp.h

SRCS := $(PATH_SRC)/main.cpp $(PATH_SRC)/Fixed.cpp $(PATH_SRC)/Point.cpp $(PATH_SRC)/bsp.cpp

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_SRC)%.cpp
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(PATH_OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re