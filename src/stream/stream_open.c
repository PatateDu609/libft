#include "ft_stream.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int ft_get_mode(const char *mode)
{
	int res = -1;

	if (ft_strchr(mode, 'r') != NULL)
		res = O_RDONLY;
	if (ft_strchr(mode, 'w') != NULL)
		res = (res == -1) ? O_WRONLY : O_RDWR;

	if (res == O_WRONLY || res == O_RDWR)
	{
		if (ft_strchr(mode, 'a') != NULL)
			res = (res == O_WRONLY) ? O_WRONLY | O_APPEND : O_RDWR | O_APPEND;
		else if (ft_strchr(mode, '+') != NULL && res == O_WRONLY)
			res = O_RDWR;
		res |= O_CREAT;
	}
	return (res);
}

static int __sopen(ft_stream *stream)
{
	int mode = ft_get_mode(stream->mode_str);
	stream->mode = mode;

	if (mode == -1)
		return (-2);
	int fd = open(stream->path, mode, 0644);

	if (fd == -1)
		return (-1);
	stream->fd = fd;
	return (0);
}

static int __setup_buffer(ft_stream *stream)
{
	stream->size = BUFFER_SIZE;
	stream->pos = 0;

	stream->buffer = ft_calloc(stream->size, sizeof *stream->buffer);
	if (!stream->buffer)
		return (-1);
	return (0);
}

ft_stream *ft_sopen(const char *path, const char *mode)
{
	ft_stream *stream = malloc(sizeof *stream);

	if (stream == NULL)
		return NULL;

	stream->fd = -1;
	stream->buffer = NULL;
	stream->type = FT_STREAM_TYPE_FILE;
	stream->size = 0;
	stream->pos = 0;
	stream->max = 0; // buffer is empty at the beginning
	stream->path = ft_strdup(path);
	stream->mode_str = mode;

	if (__sopen(stream)) // TODO: check return value
	{
		free(stream);
		return NULL;
	}

	if (__setup_buffer(stream))
	{
		close(stream->fd);
		free(stream);
		return NULL;
	}

	return stream;
}
