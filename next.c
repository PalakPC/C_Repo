 
// Defining __KERNEL__ and MODULE allows us to access kernel-level code not usually available to userspace programs.
#undef __KERNEL__
#define __KERNEL__
 
#undef MODULE
#define MODULE
 
// Linux Kernel/LKM headers: module.h is needed by all modules and kernel.h is needed for KERN_INFO.
#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>        // included for __init and __exit macros

#define message_length 80
static char message[message_length];
 
static int __init hello_init(void)
{
    	int l;
    	int *p;
   	printk(KERN_INFO "Hello world!\n");
    	printk(KERN_INFO "Enter length of string: ");
   	put_user(l, p);
   	char *buf;
    	for (int i=0; i<l; ++i)
   	{
		get_user(message[i], buf+i);
    	}
    	message[i]='\0';
	char *ptr=(char *)kmalloc((l+1)*sizeof(char), GFP_KERNEL);
	for(i=0; message[i]!='\0'; ++i)
	{
		*(ptr+i)=message[i];
	} 
	printk(KERN_INFO "String is:\n"); 
	for (i=0; i<l; ++i)
	{
		printk(KERN_INFO , *(ptr+i));
	}  
	return 0;    // Non-zero return means that the module couldn't be loaded.   
}
 
static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}
 
module_init(hello_init);
module_exit(hello_cleanup);
 
