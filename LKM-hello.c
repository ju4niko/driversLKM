#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL"); 
MODULE_AUTHOR("Alejandro Furfaro") ; 
MODULE_VERSION("1.0") ; 
MODULE_DESCRIPTION("HolaMundo LKM");

static int __init hello_init(void) {

  printk(KERN_ALERT "Hola mundo Kernel!. Soy un driver!\n");
  printk(KERN_ALERT "desde el PID:%d...\n",current->pid);
  printk(KERN_ALERT "Nombre del programa: %s\n", current->mm->exe_file->f_path.dentry->d_name.name);
  return 0; 
}

static void __exit hello_exit(void) {

  printk(KERN_ALERT "Adios mundo Kernel... \n"); 
  printk(KERN_ALERT "Nombre del programa: %s\n", current->mm->exe_file->f_path.dentry->d_name.name);
  printk(KERN_ALERT "El proceso actual no tiene un programa asociado.\n");
}

module_init(hello_init); 
module_exit(hello_exit);

