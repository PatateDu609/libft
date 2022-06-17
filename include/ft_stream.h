#ifndef FT_STREAM_H
#define FT_STREAM_H

#include <stdlib.h>
#include <unistd.h>

enum e_ft_stream_stream_type
{
	FT_STREAM_TYPE_FILE,  // file stream
	FT_STREAM_TYPE_STRING // string stream
};

enum e_ft_stream_mode
{
	FT_STREAM_MODE_READ,
	FT_STREAM_MODE_WRITE
};

typedef struct s_ft_stream
{
	enum e_ft_stream_stream_type type;
	enum e_ft_stream_mode mode;

	char *buffer; // buffer for file or string
	size_t size;  // size of buffer
	size_t pos;	  // current position in the buffer
	size_t max;	  // real size of buffer (for file streams)

	int32_t fd;			 // file descriptor
	__int128_t filesize; // file size
	const char *path;
	const char *mode_str;
} ft_stream;

ft_stream *ft_sopen(const char *path, const char *mode);
ft_stream *ft_sopen_fd(int fd);
void ft_sclose(ft_stream *stream);

ssize_t ft_sread(ft_stream *stream, void *buffer, size_t size);
ssize_t ft_swrite(ft_stream *stream, const void *buffer, size_t size);

#endif
