NAME	= ex03

SRCS	= AForm.cpp			\
		  Bureaucrat.cpp	\
		  Intern.cpp		\
		  main.cpp			\
		  ShrubberyCreationForm.cpp	\
		  RobotomyRequestForm.cpp	\
		  PresidentialPardonForm.cpp	\

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re