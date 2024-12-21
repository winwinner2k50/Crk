CC := gcc
CFLAGS := -Wall -Werror -Wextra -Wpedantic

dir_out_default := out
dir_funcs_default := src
dir_headers_default := inc

dir_out_check := out_check
dir_funcs_check := unit_tests
dir_headers_check := unit_inc

FILE_FUNCS_DEFAULT := $(wildcard ./$(dir_funcs_default)/*.c)

FILE_MAIN := $(dir_funcs_default)/main.c

OBJS_FUNCS_DEFAULT := $(patsubst ./$(dir_funcs_default)/%.c, ./$(dir_out_default)/%.o, $(filter-out ./$(dir_funcs_default)/main.c, $(FILE_FUNCS_DEFAULT)))

OBJS_MAIN_DEFAULT := $(dir_out_default)/main.o
HEADERS := $(wildcard $(dir_headers_default)/*.h)


app.exe : $(dir_out_default) $(OBJS_FUNCS_DEFAULT) $(OBJS_MAIN_DEFAULT) 
	$(CC) $(CFLAGS) $(OBJS_MAIN_DEFAULT) $(OBJS_FUNCS_DEFAULT) -o $@ -lm

$(dir_out_default) :
	mkdir -p $(dir_out_default)

$(dir_out_default)/%.o : $(dir_funcs_default)/%.c $(dir_headers_default)/*.h
	$(CC) $(CFLAGS) -I $(dir_headers_default) -c $< -o $@ -lm