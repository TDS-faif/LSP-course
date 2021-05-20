#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int main()
{
	struct winsize ws;
	int fd = open("/dev/tty", O_RDONLY);
	ioctl(fd, TIOCGWINSZ, &ws);
	printf("ws_row = %d\n", ws.ws_row);
	printf("ws_col = %d\n", ws.ws_col);
	return 0;
}
