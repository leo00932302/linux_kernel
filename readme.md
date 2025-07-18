# Simple Linux Kernel Module

This kernel module was created to help you learn the basic functionalities of a Linux module.  
It demonstrates how to:

- Create a kernel module from scratch
- Use the virtual file system (`/proc`) to interact with user-space applications
- Configure VSCode for kernel module development

---

##  Prerequisites

Before building and inserting the module, install the essential development packages:

```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
```

---

## Usage

### Build the Module

Use a Makefile to build the module:

```bash
make
```

### Insert the Module

```bash
sudo insmod main.ko         # Install the module
sudo dmesg | tail -n 10     # Check the kernel log (look for "Hello, kernel!")
```

### Check if Module is Loaded

```bash
lsmod | grep module_name    # Replace with your actual module name
```

### Remove the Module

```bash
sudo rmmod main             # Uninstall the module
```

### View Module Info

```bash
modinfo main.ko
```

---

## VSCode Configuration

Add the following to your `.vscode/c_cpp_properties.json` file for better IntelliSense support:

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/lib/modules/5.15.0-133-generic/build/include",
                "/lib/modules/5.15.0-133-generic/build/include/uapi",
                "/lib/modules/5.15.0-133-generic/build/include/generated",
                "/lib/modules/5.15.0-133-generic/build/include/generated/uapi",
                "/lib/modules/5.15.0-133-generic/build/arch/x86/include",
                "/lib/modules/5.15.0-133-generic/build/arch/x86/include/generated",
                "/lib/modules/5.15.0-133-generic/build/arch/x86/include/uapi",
                "/lib/modules/5.15.0-133-generic/build/arch/x86/include/generated/uapi"
            ],
            "defines": [
                "__KERNEL__",
                "MODULE"
            ],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64",
            "configurationProvider": "ms-vscode.makefile-tools"
        }
    ],
    "version": 4
}
```

> Feel free to modify the include paths to match your kernel version.

---

## Reference

- [Linux Kernel Module Programming Tutorial (YouTube)](https://www.youtube.com/watch?v=iSiyDHobXHA&t=7052s)
