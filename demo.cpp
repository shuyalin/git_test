#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WAKEUP_SIGNAL 3
#define READ_SN 4
#define SLEEP_SIGNAL 5
#define ENC_READ_SIGNAL 6
unsigned char receve[100];

int main()
{
	int i;
	unsigned char response_buffer[2] = {0};
	unsigned char transmit_buffer[2]={0x05,0x04};
    int g_fd = open("/dev/atsha204a", O_RDWR);
    if(g_fd < 0)
    {
        printf("open device sha204 failed!\n");
        return -1;
    }

	while(1)
	{
		//ioctl(g_fd,WAKEUP_SIGNAL);
		//read(g_fd,receve,100);
		//for(i=0;i<receve[0];i++)
		//	printf("%d ",receve[i+1]);
		//printf("\n\n");
		//
		////usleep(400);
		//ioctl(g_fd,READ_SN);
		//read(g_fd,receve,100);
		//for(i=0;i<receve[0];i++)
		//	printf("0x%x ",receve[i+1]);
		//printf("\n\n");
		//
		//ioctl(g_fd,SLEEP_SIGNAL,transmit_buffer);
		//read(g_fd,receve,100);
		//for(i=0;i<receve[0];i++)
		//	printf("0x%x ",receve[i+1]);
		//printf("\n\n");
		
		ioctl(g_fd,ENC_READ_SIGNAL,response_buffer);
		read(g_fd,receve,100);
		for(i=0;i<receve[0];i++)
			printf("0x%x ",receve[i+1]);
		printf("\n\n\n\n\n\n\n\n");
		sleep(2);
	}
  
	return 0;
}



