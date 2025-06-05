#!/bin/bash

#Check input
# $# == Argc
if [ $# -lt 2 ]; then
	echo "How to use: ./createFolder.sh <folder name> <class name>"
	exit 1
fi

#Names
FOLDERNAME=$1
CLASSNAME=$2

#Colours
ORANGE='\033[38;5;208m'
RESET='\033[0m'

mkdir -p $FOLDERNAME
mkdir -p $FOLDERNAME/src
mkdir -p $FOLDERNAME/includes

cat > $FOLDERNAME/Makefile << EOF
NAME=temp
TESTS = 5

CC = c++
FLAGS = -g3 -Wall -Werror -Wextra -std=c++98

INCLUDE = includes
SRC =	${CLASSNAME}.cpp\\
		main.cpp
SRCS = \$(addprefix src/, \$(SRC))
OBJS = \$(SRCS:.cpp=.o)

RM = rm -f

all: \$(NAME)

\$(NAME): \$(OBJS)
	@\$(CC) \$(FLAGS) -I\$(INCLUDE) -o \$(NAME) \$(OBJS)

src/%.o: src/%.cpp
	@echo "\033[1;32mCompiling	->	\$<\033[0m"
	@\$(CC) \$(FLAGS) -I\$(INCLUDE) -c \$< -o \$@

run: re
	@valgrind ./\$(NAME)

test: run
	@for i in \$(shell seq 1 \$(TESTS)); do \\
		valgrind ./\$(NAME) \$\$i; \\
	done

clean:
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		OBJECTS REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@\$(RM) \$(OBJS)

fclean: clean
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		\$(NAME) REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"	
	@\$(RM) \$(NAME)

re: fclean all

.PHONY: all clean fclean re run test
EOF

echo -e "Folder: ${ORANGE}${FOLDERNAME}${RESET} successfuly created!"

#Create main
cp mainTemplate.cpp main.cpp
sed -i "s/ClassTemplate/${CLASSNAME}/g" main.cpp
mv main.cpp ${FOLDERNAME}/src

#Creates class
./createClass.sh $CLASSNAME $FOLDERNAME
