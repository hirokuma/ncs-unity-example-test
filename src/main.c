#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "foo/foo.h"
#include "uut/uut.h"

int main(void)
{
    int ret;

    ret = uut_init(&ret);
    if (ret != 0) {
        printk("bad result\n");
        return ret;
    }
    printk("good!\n");
    return 0;
}
