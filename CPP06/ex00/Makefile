NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = 	main.cpp\
		ScalarConverter.cpp 

		
OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	bash ./test_convert1.sh
	bash ./test_convert2.sh
	bash ./test_convert3.sh

.PHONY: all clean fclean re test

