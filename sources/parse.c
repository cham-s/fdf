void	parse(t_env *e, int fd)
{
	int ret;
	int x1;
	int y1;
	
	x1 = 0;
	y1 = 0;
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	ret = -1;
	while (buff[++ret] != '\0')
	{
		if (buff[ret] > 29 && buff[ret] < 40)
		{
			e->map_para->x = 
		}
	}

}
