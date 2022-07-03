NAME			=	a.out
SRCS			=	main.cpp
OBJS_DIR		=	./objs
OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

CXX				=	c++
#CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
#CXXFLAGS		+=	-g -fsanitize=address
RM				=	rm -f

.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CXX) $(OBJS) $(CXXFLAGS) -o $@

$(OBJS_DIR)/%.o	:	%.cpp iter.hpp
					@[ -d $(OBJS_DIR) ]
					$(CXX) $(CXXFLAGS) -c $< -o $@

clean			:
					$(RM) $(OBJS)

fclean			:
					$(RM) $(OBJS) $(NAME) 

re				:	fclean all
