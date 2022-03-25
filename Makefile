NAME = containers

INC = 	srcs/vector/vector.hpp \
		srcs/stack/stack.hpp \
		srcs/iterators/iterator_traits.hpp \
		debug_test.hpp \

# SRCS = vector_main.cpp
SRCS = 	stack_main.cpp
#SRCS = map_main.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
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