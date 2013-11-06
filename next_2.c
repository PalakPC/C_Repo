 
// Defining __KERNEL__ and MODULE allows us to access kernel-level code not usually available to userspace programs.
#undef __KERNEL__
#define __KERNEL__
 
#undef MODULE
#define MODULE
 
// Linux Kernel/LKM headers: module.h is needed by all modules and kernel.h is needed for KERN_INFO.
#include <linux/module.h>    // included for all kernel modules
#include <linux/moduleparam.h>
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>        // included for __init and __exit macros
#include <linux/stat.h>


static char message[25][25];
int num = 0;
module_param_array(message, charp, &num , 0000);
MODULE_PARM_DESC(message, "A character string array");
 
static int __init hello_init(void)
{
	int i=0;
	for(i=0; i<num; ++i)
	{
		printk(KERN_INFO "%s", message[i]);
	}
	return 0;    // Non-zero return means that the module couldn't be loaded.   
}
 
static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}
 
module_init(hello_init);
module_exit(hello_cleanup);
 
