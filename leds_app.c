#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#define LED1_PATH "/sys/class/leds/user-led1/brightness"
#define LED_BRIGHTNESS 255
int leds_control( void)
{
    int fd = 0, retvalue = 0;
    char writebuf[1] = "";
    fd = open(LED1_PATH,O_RDWR);
    if(fd < 0){
        printf("Can't open file %s\r\n", LED1_PATH);
        return -1;
    }
     writebuf[0] = LED_BRIGHTNESS;
    // 打开 led
    write(fd, writebuf, 1);
    retvalue = close(fd);
    if(retvalue < 0){
        printf("Can't close file %s\r\n", LED1_PATH);
        return -1;
    }

    return 0;
}
