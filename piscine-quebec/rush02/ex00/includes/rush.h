#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <stdio.h>

// STRUCTS
typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;


// MAIN PROTOTYPES
char	*ft_number_is_valid(char *str);
int 	input_manip(char *vinput, t_dict *dict);

// DICTIONARY PROTOTYPES
t_dict	*create_dict(char *path);
char	*dict_to_str(char *path);
