/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/02 13:14:03 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Special thanks to Jelle van der Kooi (jelvan-d), Tessa vand er Loo  */
/* (tevan-de) & Cosima Uechtritz (ceuchtri) for helping me fix my bugs <3 */

#include "../inc/libft.h"

static void	ft_free_str(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*ft_find_line(char *buffer)
{
	char	*end;
	char	*line;
	size_t	i;

	i = 0;
	end = ft_strchr_gnl(buffer, '\n');
	if (end == NULL)
		end = ft_strchr_gnl(buffer, '\0');
	else
		end = end + 1;
	while (&buffer[i] != &end[0])
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	return (line);
}

static char	*ft_read_check(char **buffer, char *read_char, int bytes)
{
	char		*temp;

	temp = NULL;
	if (bytes < 0)
		return (ft_free_str(buffer), NULL);
	if (bytes > 0)
	{
		temp = *buffer;
		*buffer = ft_strjoin_gnl(temp, read_char);
		ft_free_str(&temp);
	}
	return (*buffer);
}

/*	this is the function that actually reads the file.
		the variable "bytes" is set to buffer_size to start off with so

	reads unless buffer contains \n and till EOF */
static char	*ft_read_file(int fd, char *buffer)
{
	int			bytes;
	char		*read_char;

	bytes = BUFFER_SIZE;
	read_char = NULL;
	while (ft_strchr_gnl(buffer, '\n') == NULL && bytes == BUFFER_SIZE)
	{
		read_char = ft_calloc(bytes + 1, sizeof(char));
		if (!read_char)
			return (NULL);
		bytes = read(fd, read_char, BUFFER_SIZE);
		if (bytes == 0)
			return (ft_free_str(&read_char), buffer);
		buffer = ft_read_check(&buffer, read_char, bytes);
		ft_free_str(&read_char);
	}
	return (buffer);
}

//	this is the general get_next_line function.
//		it checks for errors such as:
//			- read errors
//			- fd errors
//			- buffer size being too small to use
//		it then calls on the function used to read the file and safes the
//		outcome to the variable "line".

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;
	char		*new_buffer;
	size_t		len;

	line = NULL;
	new_buffer = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (ft_free_str(&buffer[fd]), NULL);
	if (ft_strchr_gnl(buffer[fd], '\n') == NULL)
		buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (buffer[fd])
	{
		if (buffer[fd][0] == '\0')
			return (ft_free_str(&buffer[fd]), NULL);
		line = ft_find_line(buffer[fd]);
		len = ft_strlen_gnl(buffer[fd] + ft_strlen_gnl(line));
		new_buffer = ft_calloc(len + 1, sizeof(char));
		if (!new_buffer)
			return (ft_free_str(&buffer[fd]), NULL);
		ft_memcpy(new_buffer, buffer[fd] + ft_strlen_gnl(line), len);
		ft_free_str(&buffer[fd]);
		buffer[fd] = new_buffer;
	}
	return (line);
}

//	in this main i take a textfile as argument and open it.
//		it starts of with eror handling such as:
//			- no argument
//			- error with opening file
//		after this it calls on the get_next_line function with the given fd
//		in a loop, printing it each time, untill error or EOF.

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line = "start";

// 	if (argc != 2)
// 	{
// 		printf("\nplease enter one filename as argument\n\n");
// 		return (0);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("\nencountered problem opening file\nfd = %i\n\n", fd);
// 		return (fd);
// 	}
// 	while ((line = get_next_line(fd)) > 0)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	system("leaks a.out");
// 	close(fd);
// 	return (0);
// }
