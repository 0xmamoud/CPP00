
NAME = phonebook

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM	= rm -rf


SRC = Contact.cpp\
	PhoneBook.cpp\
	main.cpp\
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -I PhoneBook.hpp -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re