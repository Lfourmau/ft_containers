NAME = containers

INC = 	srcs/vector/vector.hpp \
		srcs/stack/stack.hpp \
		srcs/map/map.hpp \
		srcs/map/red_black_tree.hpp \
		srcs/set/set.hpp \
		srcs/iterators/iterator_traits.hpp \

SRCS = mains/main.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address
CXX = clang++

all : $(NAME) 

%.o : %.cpp $(INC)
	$(CXX) -c $(CXXFLAGS) $< -o $(<:.cpp=.o) -g

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o ${NAME} $(OBJS)


clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re