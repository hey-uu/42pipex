# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:35:23 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/14 05:43:22 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands and flags
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# file names
LIBFT_FILE = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_strchr \
		ft_strdup \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_tolower \
		ft_toupper \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_push_swap_atol \
		ft_exit \
		ft_malloc \
		ft_max
		
PRINTF_FILE = ft_printf \
			printf_utils \
			put_characters \
			put_integers_utils \
			put_integers

GNL_FILE = get_next_line_utils \
			get_next_line

BONUS_FILE = ft_lstadd_back \
		 	ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstnew \
			ft_lstsize \
			ft_lstlast \
			ft_lstmap

# directory files
OBJCS_DIR = objcs
LIBFT_DIR = libft_mandatory
BONUS_DIR = libft_bonus
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

# header
INC_DIR = includes

# object files
LIBFT_OBJCS = $(addprefix $(OBJCS_DIR)/$(LIBFT_DIR)/, $(addsuffix .o, $(LIBFT_FILE)))
BONUS_OBJCS = $(addprefix $(OBJCS_DIR)/$(BONUS_DIR)/, $(addsuffix .o, $(BONUS_FILE)))
PRINTF_OBJCS = $(addprefix $(OBJCS_DIR)/$(PRINTF_DIR)/, $(addsuffix .o, $(PRINTF_FILE)))
GNL_OBJCS = $(addprefix $(OBJCS_DIR)/$(GNL_DIR)/, $(addsuffix .o, $(GNL_FILE)))
OBJCS = $(LIBFT_OBJCS) $(B_OBJCS) $(P_OBJCS) $(G_OBJCS)

# variables
ifdef WITH_BONUS
	B_OBJCS = $(BONUS_OBJCS)
endif

ifdef WITH_PRINTF
	P_OBJCS = $(PRINTF_OBJCS)
endif

ifdef WITH_GNL
	G_OBJCS = $(GNL_OBJCS)
endif
