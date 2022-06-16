#include "ft_stream.h"
#include "libft.h"
#include <unistd.h>

ssize_t ft_swrite(ft_stream *stream, const void *buffer, size_t size)
{
	if (stream->type == FT_STREAM_TYPE_FILE)
		return (write(stream->fd, buffer, size));
	else if (stream->type == FT_STREAM_TYPE_STRING) //! Not tested
	{
		if (stream->pos + size > stream->max)
			size = stream->max - stream->pos;
		ft_memcpy(stream->buffer + stream->pos, buffer, size);
		stream->pos += size;
		return (size);
	}
	return (-1);
}
