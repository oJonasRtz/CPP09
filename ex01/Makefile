NAME=RPN
TESTS = 5

CC = c++
FLAGS = -g3 -Wall -Werror -Wextra -std=c++98

INCLUDE = includes
SRC =	RPN.cpp\
		main.cpp
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS)

src/%.o: src/%.cpp
	@echo "\033[1;32mCompiling	->	$<\033[0m"
	@$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

run: re
	@valgrind ./$(NAME)

test: run
	@echo "\033[1;32m=======================================================================\033[0m"
	@echo "\t\t\t42 Tests"
	@echo "\033[1;32m=======================================================================\033[0m"
	@valgrind ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@valgrind ./$(NAME) "7 7  * 7 -"
	@valgrind ./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@valgrind ./$(NAME) "(1 + 1)"
	@echo "\033[1;32m=======================================================================\033[0m"
	@echo "\t\tMy tests"
	@echo "\033[1;32m=======================================================================\033[0m"
	@valgrind ./$(NAME) "4 0 /"
	@valgrind ./$(NAME) "0 4 /"
	@valgrind ./$(NAME) "5 5 + 2 * 1 -"
	@valgrind ./$(NAME) ""
	@valgrind ./$(NAME) "4 3"
	@valgrind ./$(NAME) "0000000000000000 2 +"
	@valgrind ./$(NAME) "5.2 5 +"
	@valgrind ./$(NAME) "+ 2 3"
	@valgrind ./$(NAME) "5      1  2    +    *"
	@valgrind ./$(NAME) "1 2 3 4 5 6 7 8 9"
	@valgrind ./$(NAME) "4 +"
	@valgrind ./$(NAME) "5 5 + 2 * 10 + 5 5 + + 2 * 2 5 + + 2 / 1 -"
	@valgrind ./$(NAME) "100 500 -"
	@valgrind ./$(NAME) "abc  5 +"
	@valgrind ./$(NAME) "5 999999999999999  +"
	@valgrind ./$(NAME) "5 -2147483646  +"
	@valgrind ./$(NAME) "5 2 + -2"

clean:
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		OBJECTS REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		$(NAME) REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"	
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run test
