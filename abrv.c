#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
abrv(const char *path, const char *home)
{
	const char *final = strrchr(path, '/');
	char last = '/';
	size_t hlen = 0;

	if (final)
		final++;

	if (home && (hlen = strlen(home)) && strncmp(path, home, hlen) == 0) {
		putchar('~');
		path += hlen;
	}

	while (*path) {
		if (path == final) {
			printf("%s", final);
			break;
		}

		if (*path == '/' || last == '/')
			putchar(*path);

		last = *path++;
	}
}

int
main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s PATH\n", argv[0]);
		return EXIT_FAILURE;
	}

	abrv(argv[1], getenv("HOME"));
}
