NAME := phonebook

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

PATH_SRC := src/
PATH_OBJ := obj/
PATH_INCL := incl/

INCL := $(PATH_INCL)./Contact.hpp \
		$(PATH_INCL)./PhoneBook.hpp

SRCS := $(PATH_SRC)/Contact.class.cpp \
		$(PATH_SRC)/PhoneBook.class.cpp \
		$(PATH_SRC)/main.cpp

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCL) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(PATH_OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re