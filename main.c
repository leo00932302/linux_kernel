#include <linux/init.h>
#include <linux/module.h>
#include<linux/kernel.h>
#include<linux/proc_fs.h>


//the license
MODULE_LICENSE("GPL");
MODULE_AUTHOR("leo");
MODULE_DESCRIPTION("A simple module");

//proc function 
static struct proc_dir_entry *custom_proc_node;
ssize_t rui_read(struct file *file_pointer,
                 char* user_space_buffer,
                 size_t count,
                 loff_t* offset){
        printk(KERN_INFO "rui read\n");
        return 0;
    }
struct proc_ops driver_proc_ops = {
        .proc_read = rui_read
    };
    
//finction defination
static int __init hello_init(void) {
    printk(KERN_INFO "Hello, kernel main!\n");
    custom_proc_node = proc_create("my_driver",0,NULL,&driver_proc_ops);
    return 0;
}
static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, kernel main!\n");
    proc_remove(custom_proc_node);
}
//the entry and exit
module_init(hello_init);
module_exit(hello_exit);
