#include "../incl/ft_lib.h" 

int	main(void)
{
	MYSQL	*conn;

	conn = mysql_init(NULL);
	ft_connect_db(conn);
	return (0);
}
