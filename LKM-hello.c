#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL"); 
MODULE_AUTHOR("Alejandro Furfaro") ; 
MODULE_VERSION("1.0") ; 
MODULE_DESCRIPTION("HolaMundo LKM");

static int __init hello_init(void) {

  printk(KERN_ALERT "Hola mundo Kernel!. Soy un driver!\n");
  return 0; 
}

static void __exit hello_exit(void) {

  printk(KERN_ALERT "Adios mundo Kernel... \n"); 
}

module_init(hello_init); 
module_exit(hello_exit);

