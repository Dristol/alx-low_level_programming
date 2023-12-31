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

	ssize_t x, r, w;
	char *buffer;


	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	x = open(filename, O_RDONLY);
	r = read(x, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);


	if (x == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(x);

	return (w);
}
