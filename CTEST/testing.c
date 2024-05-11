#include "../libft/headers/libft.h"
#include "include/libassert.h"


static bool	filename_errors(char *filename)
{
	if (ft_strlen(filename) < 5)
		return (true);
	else if (!ft_strchr(filename, '.'))
		return (true);
	else if (ft_strncmp(ft_strrchr(filename, '.'), ".fdf", sizeof(".fdf")))
		return (true);
	return (false);
}

int main(void) {
	t_inst	inst[6];
	t_text	infos[4];

	infos[0] = (t_text){"arquivo errado", DEFAULT_T_COLOR};
	infos[1] = (t_text){"se o nome e menor que 5, se tem extensao e se a extensao e .fdf", DEFAULT_D_COLOR};
	infos[2] = (t_text){"DALE!", DEFAULT_O_COLOR};
	infos[3] = (t_text){"HOW?", DEFAULT_K_COLOR};
	for (int i = 0; i < 6; i++)
		set_instance(&inst[i], infos, EQUAL);

	int64_t	exp[6] = {1, 0, 1, 0, 1, 0};
	int64_t	ret[6] = {42};
	char	*filename[6] = {"a", "a.fdf", "abcfdf", "abc.fdf", "42.python", "42.fdf"};

	for (int i = 0; i < 6; i++)
		ret[i] = filename_errors(filename[i]);

	test_int(inst, ret, exp, 6);
	return 0;
}
