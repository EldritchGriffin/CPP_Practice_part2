SRC 	:= main.cpp PmergeMe.cpp
CC 		:= c++
FLAG	:= -Wall -Werror -Wextra -std=c++98
NAME 	:= PmergeMe
HEADERS := PmergeMe.hpp
OBJ		:= $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@c++ $(FLAG) $(SRC) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@c++ $(FLAG) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	
fclean : clean
	@rm -rf $(NAME)
	
re : fclean all