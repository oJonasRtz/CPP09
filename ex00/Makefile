NAME=btc
TESTS = 5
TESTINPUT=input.txt

CC = c++
FLAGS = -g3 -Wall -Werror -Wextra -std=c++98

INCLUDE = includes
SRC =	BitcoinExchange.cpp\
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

input:
	@touch $(TESTINPUT)
	@echo "date | value" > $(TESTINPUT)
	@echo "2011-01-03 | 3" >> $(TESTINPUT)
	@echo "2011-01-03 | 2" >> $(TESTINPUT)
	@echo "2011-01-03 | 1" >> $(TESTINPUT)
	@echo "2011-01-03 | 1.2" >> $(TESTINPUT)
	@echo "2011-01-09 | 1" >> $(TESTINPUT)
	@echo "2012-01-11 | -1" >> $(TESTINPUT)
	@echo "2001-42-42" >> $(TESTINPUT)
	@echo "2012-01-11 | 1" >> $(TESTINPUT)
	@echo "2012-01-11 | 2147483648" >> $(TESTINPUT)
	@echo "2013-05-15 | 10.5" >> $(TESTINPUT)
	@echo "2013-13-01 | 5" >> $(TESTINPUT)
	@echo "2010-12-31 | 0" >> $(TESTINPUT)
	@echo "2011-01-02 | abc" >> $(TESTINPUT)
	@echo "2012-06-28 | 999.99" >> $(TESTINPUT)
	@echo "2011-01-01 | 500" >> $(TESTINPUT)
	@echo "01-2009-121 | 10" >> $(TESTINPUT)
	@echo "01-02-2001 | 10" >> $(TESTINPUT)
	@echo "2010-50-20 | 12" >> $(TESTINPUT)
	@echo "2070-05-09 | 9" >> $(TESTINPUT)
	@echo "1950-05-09 | 9" >> $(TESTINPUT)
	@echo "2015-05-09 | .........." >> $(TESTINPUT)
	@echo "2015-05-09 | 3." >> $(TESTINPUT)
	@echo "2015-05-09 | 3.0" >> $(TESTINPUT)

test: re input
	@valgrind ./$(NAME) $(TESTINPUT)

clean:
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		OBJECTS REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@$(RM) $(OBJS)
	@$(RM) $(TESTINPUT)

fclean: clean
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		$(NAME) REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"	
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test input
