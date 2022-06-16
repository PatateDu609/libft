#include "ft_stream.h"
#include <unistd.h>

void ft_sclose(ft_stream *stream)
{
	if (stream->fd != -1)
	{
		close(stream->fd);
		stream->fd = -1;
	}
	free((char *)stream->path);
	stream->path = NULL;
	free(stream->buffer);
	stream->buffer = NULL;
	free(stream);
}
