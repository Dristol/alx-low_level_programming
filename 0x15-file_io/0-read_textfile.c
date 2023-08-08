#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 **/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int Fd;
	ssize_t r, w;
	char *buf;

	if (!filename)
		return (0);

	Fd = open(filename, O_RDONLY);

	if (Fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	r = read(Fd, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	close(Fd);

	free(buf);

	return (w);
}
