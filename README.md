# Stable-NUMA
[Stable-NUMA](https://github.com/skkucsl/stable-numa) is a NUMA-aware thread and page placement scheme for the performance stability of HPC workloads. To minimize the performance variability, Stable-NUMA was carefully designed to mini ize the memory profiling overheads. Furthermore, Stable-NUMA was designed to eliminate policy conflicts between the CPU load balancer and Auto-NUMA.

This repository contains the implementation of Stable-NUMA in the Linux kernel. We will open the source code as soon as possible. Please stay tuned.

Please cite the following paper if you use Stable-NUMA:

**A Performance-Stable NUMA Management Scheme for Linux-Based HPC Systems**.
Jaehyun Song, Minwoo Ahn, Gyusun Lee, Euiseong Seo and Jinkyu Jeong. *IEEE Access*.

## How to Use
1. Compile the kernel and reboot. 

1. After system boot, Stable-NUMA is enabled. To disable Stable-NUMA, execute this command `echo 0 > /proc/sys/kernel/numa_balancing`
