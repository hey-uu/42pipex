# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 01:41:38 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/16 01:53:31 by hyeyukim         ###   ########.fr        #
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
LIBFT_INC_DIR = libft/includes

# file names
MAN_FILE = 	pipex_main \
			parse_cmd \
			fork_and_execute \
			pipex_utils \

BON_FILE = 	pipex_main_bonus \
			parse_cmd_bonus \
			fork_and_execute_bonus \
			pipex_utils_bonus \
			here_doc_bonus

# directories of files
MAN_DIR = mandatory
BON_DIR = bonus
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = objcs

# object files
MAN_OBJ = $(addprefix $(OBJ_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ = $(addprefix $(OBJ_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

# header files
MAN_INC = $(addprefix $(INC_DIR)/$(MAN_DIR)/, $(addsuffix .h, $(MAN_FILE)))
BON_INC = $(addprefix $(INC_DIR)/$(BON_DIR)/, $(addsuffix .h, $(BON_FILE)))

# option
ifndef WITH_BONUS
	OBJ = $(MAN_OBJ)
	INC = $(MAN_INC)
else
	OBJ = $(BON_OBJ)
	INC = $(BON_INC)
endif