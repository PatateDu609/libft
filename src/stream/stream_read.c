#include "ft_stream.h"
#include "libft.h"
#include <unistd.h>

static ssize_t __sread_file(ft_stream *stream, void *buffer, size_t size);

static ssize_t __sread_buffer(ft_stream *stream, void *buffer, size_t size, ssize_t ret)
{
	if (!stream->max && !ret && !stream->pos)
		return (0);

	const size_t n = MIN(size, stream->max - stream->pos);
	ft_memcpy(buffer, stream->buffer + stream->pos, n);
	stream->pos += n;

	if (stream->pos >= stream->max) // we have read the whole buffer
		stream->max = 0;
	if (!stream->max && !ret) // we have read the whole file
		stream->pos = 0;
	if (n == size) // we have read just what we asked for
		return (n);

	if (ret)
		return (__sread_file(stream, buffer + n, size - n));
	return (n);
}

/*
 * __sread_file_read: read from file stream (or internal buffer) and return the number of bytes read
 * @stream: stream to read from
 * @buffer: buffer to read into
 * @size: size of buffer
 */
ssize_t __sread_file(ft_stream *stream, void *buffer, size_t size)
{
	if (stream->max)
		return (__sread_buffer(stream, buffer, size, 1));
	ft_memset(stream->buffer, 0, stream->size);
	ssize_t max = read(stream->fd, stream->buffer, stream->size);
	if (max < 0)
		return (-1);
	stream->filesize += max; // update file size
	if (max > 0)
	{
		stream->pos = 0;
		stream->max = max;
	}

	return (__sread_buffer(stream, buffer, size, (size_t)max >= size));
}

ssize_t ft_sread(ft_stream *stream, void *buffer, size_t size)
{
	if (stream->type == FT_STREAM_TYPE_FILE)
		return (__sread_file(stream, buffer, size));
	else if (stream->type == FT_STREAM_TYPE_STRING) //! Not tested
	{
		if (stream->pos + size > stream->max)
			size = stream->max - stream->pos;
		ft_memcpy(buffer, stream->buffer + stream->pos, size);
		stream->pos += size;
		return (size);
	}
	return (-1);
}
