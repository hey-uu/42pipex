# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 12:39:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/14 01:46:01 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(MAN_OBJCS)
	make -C $(LIB_DIR) gnl
	$(CC) $(CFLAGS) $(MAN_OBJCS) $(LIB) -o $@ 

.PHONY : bonus
bonus : $(BON_OBJCS)
	make -C $(LIB_DIR) gnl
	$(CC) $(CFLAGS) $(BON_OBJCS) $(LIB) -o $(NAME)

include config/compile_rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJCS_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all
