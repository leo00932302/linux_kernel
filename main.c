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
                 char __user* user_space_buffer,
                 size_t count,
                 loff_t* offset){
        int result;
        char msg[] = "hello\n";
        
        size_t len = strlen(msg);
        if(*offset>=len) return 0;
        printk(KERN_INFO "rui read\n");
        result = copy_to_user(user_space_buffer,msg,len);
        *offset += len;
        return len;
    }
static struct proc_ops driver_proc_ops = {
        .proc_read = rui_read,
        .proc_lseek = default_llseek
    };
    
//finction defination
static int __init hello_init(void) {
    printk(KERN_INFO "Hello, kernel main!\n");
    custom_proc_node = proc_create("my_driver",0,NULL,&driver_proc_ops);
    if(custom_proc_node == NULL){
        printk(KERN_INFO "init error\n");
        return -1;
    }
    return 0;
}
static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, kernel main!\n");
    proc_remove(custom_proc_node);
}
//the entry and exit
module_init(hello_init);
module_exit(hello_exit);
