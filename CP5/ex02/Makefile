# Variables
NAME := form
CC := g++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g
PATH_SRC := ./src
PATH_OBJ := ./obj
PATH_INCL := ./incl
INCL := $(addprefix $(PATH_INCL)/, Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp)
SRCS := $(addprefix $(PATH_SRC)/, Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp)
OBJS := $(SRCS:$(PATH_SRC)/%.cpp=$(PATH_OBJ)/%.o)

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
NC := \033[0m # No Color

# Default goal
.DEFAULT_GOAL := all

all: $(NAME)

# Ensure PATH_OBJ exists
$(PATH_OBJ):
	@echo "$(GREEN)Creating object directory...$(NC)"
	@mkdir -p $(PATH_OBJ)

# Rule for creating object files
$(PATH_OBJ)/%.o: $(PATH_SRC)/%.cpp | $(PATH_OBJ)
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I $(PATH_INCL) -c $< -o $@

# Rule for creating the executable
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(NC)"

# Cleanup rules
clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Removing object directory...$(NC)"
	@rm -rf $(PATH_OBJ)
	@echo "$(RED)Removing executable...$(NC)"
	@rm -f $(NAME)
	@rm -rf *_shrubbery

re: fclean all

# Phony targets
.PHONY: all clean fclean re
