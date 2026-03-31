NAME = PmergeMe

SRC = main.cpp \
	  PmergeMe.cpp \
      PmergeMe_utils.cpp \
      PmergeMe_vector.cpp \
      PmergeMe_deque.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all