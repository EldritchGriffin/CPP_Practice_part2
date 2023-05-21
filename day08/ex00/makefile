NAME:=easyfind
SRCS:= *.cpp
HEADERS:= *.hpp
CFLAGS:= -Wall -Wextra -Werror -std=c++98

all : $(SRCS) $(HEADERS)
	c++ $(CFLAGS) -o $(NAME) $(SRCS)

clean : 
	rm -f $(NAME)

re : clean all
