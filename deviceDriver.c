#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sumit Kumar Shah");

static int __init simple_driver_init(void)
{
    pid_t parent_pid = current->real_parent->pid;
    msleep(1000);
    printk(KERN_INFO "simple_driver: Parent Process ID = %d\n", parent_pid);
    return 0;
}

static void __exit simple_driver_exit(void)
{
    int i = 5;
    for (; i > 0; i--)
    {
        msleep(1000);
        printk(KERN_INFO "Unloading Packages in: %d\n", i);
    }

    long total_ctx_switches = current->nvcsw + current->nivcsw;
    printk(KERN_INFO "simple_driver: Total context switches for this process = %ld\n", total_ctx_switches);
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);
