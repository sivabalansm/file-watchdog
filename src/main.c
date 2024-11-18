#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN ( 1024  * ( EVENT_SIZE + 16 ) )
/*

   Steps
   1. Monitor files
   - new files, modified files, deleted files
   	- uses unix domain socket to signal backup program that file event happened
   2. Unix domain sockets
   - learn how 2 programs communicate with unix domain sockets
   3. blackblaze b2 wrapper
   - use python api as reference
   

   */
int main(int argc, char *argv[]) {

	int length, i = 0;
	int fd = inotify_init();
	char buf[EVENT_BUF_LEN];

	if (fd < 0) {
		perror("inotify_init");
	}

	int wd = inotify_add_watch(fd, "/", IN_CREATE);
	while (1) {
		i = 0;
		length = read(fd, buf, EVENT_BUF_LEN);
		printf("Past the read\n");

		while (i < length) {
			struct inotify_event *event = ( struct inotify_event * )&buf[i];

			if (event->len) {
				printf("file to backup: %s\n", event->name);
				// for (int j = 0; j < length; j++) {
				// 	printf("%c\n", buf[j]);
				// }
				// printf("%s\n", );
				
			}
			i += EVENT_SIZE + event->len;
		}
	}

	close(fd);

	return 0;
}
