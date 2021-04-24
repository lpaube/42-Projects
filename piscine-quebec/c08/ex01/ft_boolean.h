#ifndef FT_BOOL
#define FT_BOOL

#include <unistd.h>

typedef enum {
	false,
	true
}	t_bool;

#define EVEN(x) ((x) % 2 == 0)

#define TRUE true
#define FALSE false

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

#define SUCCESS 0

#endif
