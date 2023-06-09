#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define F_MINUS (1)
#define F_PLUS (1 << 1)
#define F_ZERO (2)
#define F_HASH (1 << 3)
#define F_SPACE (4)

/* SIZES */
#define S_LONG (1 << 1)
#define S_SHORT (1 << 1)

/**
 * struct frt - struct op
 * @frt: the format
 * @fnct: the function
 */

struct frt
{
	char frt;
	int (*fnct)(va_list, char[], int, int, int, int);
};

/**
 * struct funct - struct op
 * @f_rt: the format
 * @funct: the function
 */

typedef struct funct
{
	char f_rt;
	int (*funct)(va_list, char[], int, int, int, int);
} funct;
int _printf(const char *format, ...);
int handle_print(const char *frt, int *i,
		va_list arg, char buffer[], int flg, int wi, int p, int size);


/****************** FUNCTIONS ******************/

/* Function to print chars and strings */
int print_char(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_str(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_per(va_list typ, char buffer[],
		int flg, int wi, int p, int size);

/* Functions to print numbers */
int print_int(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_bin(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_unsnd(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_oct(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_hexadc(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_hexa_up(va_list typ, char buffer[],
		int flg, int wi, int p, int size);
int print_hexa(va_list typ, char map_t[],
		char buffer[], int flg, char flg_c, int wi, int p, int size);

/* Function to print non printable characters */
int print_non_printable(va_list typ, char buffer[],
		int flg, int wi, int p, int size);

/* Functions to print memory address */
int print_point(va_list typ, char buffer[],
		int flg, int wi, int p, int size);

/* Functions to handle other specifiers */
int hand_flg(const char *format, int *q);
int hand_wi(const char *format, int *q, va_list arg);
int hand_p(const char *format, int *q, va_list arg);
int hand_size(const char *format, int *q);

/* Function to print string in reverse */
int print_rev(va_list typ, char buffer[],
		int flg, int wi, int p, int size);

/* Function to print a string in rot 13 */
int print_rot13str(va_list typ, char buffer[],
		int flg, int wi, int p, int size);

/* Handle Width */
int write_char(char c, char buffer[],
		int flg, int wi, int p, int size);

int write_num(int is_neg, int ind, char buffer[],
		int flg, int wi, int p, int size);
int write_numb(int ind, char buffer[], int flg, int wi, int p, int len,
		char padd, int extra_char);
int write_point(char buffer[], int ind, int len,
		int wi, int flg, char padd, char extra_char, int padd_start);
int write_unsnd(int is_neg, int ind, char buffer[],
		int flag, int wi, int p, int size);

/****************** UTILITY FUNCTIONS ******************/

int is_print(char);
int append_hexa_code(char, char[], int);
int is_dig(char);

long int conv_size_num(long int num, int size);
long int conv_size_unsnd(unsigned long int num, int size);

#endif /* MAIN_H */
