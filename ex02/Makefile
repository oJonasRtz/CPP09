NAME=PmergeMe


CC = c++
FLAGS = -g3 -Wall -Werror -Wextra -std=c++98

INCLUDE = includes
SRC =	PmergeMe.cpp\
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
	@valgrind ./$(NAME) | true

test: run
	valgrind ./$(NAME) 1 2 3 4 5
	valgrind ./$(NAME) 1 2 3 4 5 "" | true
	valgrind ./$(NAME) "" 1 2 3 4 | true
	valgrind ./$(NAME) 1 2 3 4 abc | true
	valgrind ./$(NAME) 1 2 3abc 4 | true
	valgrind ./$(NAME) 4294967295
	valgrind ./$(NAME) 4294967297 | true
	valgrind ./$(NAME) 1 2 3 -5 | true
	valgrind ./$(NAME) 5 4 3 2 1 
	valgrind ./$(NAME) 1 2 3 4
	valgrind ./$(NAME) 2 4 1 7 3
	valgrind ./$(NAME) $(shell shuf -i 1-100000 -n 3000 | tr "\n" " ")

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
