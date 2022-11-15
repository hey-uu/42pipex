# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 01:41:38 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/15 00:15:59 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#commands and flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm
RMFLAGS = -rf

# library
LIB_NAME= libft.a
LIB_DIR = libft
LIB = $(LIB_DIR)/$(LIB_NAME)

# file names
MAN_FILE = 	pipex_main \
			parse_cmd \
			fork_and_execute \
			pipex_utils \
			here_doc
BON_FILE = 	pipex_main \
			parse_cmd \
			fork_and_execute \
			pipex_utils \
			here_doc

# directories of files
MAN_DIR = mandatory
BON_DIR = bonus
OBJCS_DIR = objcs

# object files
MAN_OBJCS = $(addprefix $(OBJCS_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJCS = $(addprefix $(OBJCS_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

# header files
HEADERS = 
INC_DIR = includes
LIBFT_INC_DIR = libft/includes
