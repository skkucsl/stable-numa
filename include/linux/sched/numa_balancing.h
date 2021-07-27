/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_SCHED_NUMA_BALANCING_H
#define _LINUX_SCHED_NUMA_BALANCING_H

/*
 * This is the interface between the scheduler and the MM that
 * implements memory access pattern based NUMA-balancing:
 */

#include <linux/sched.h>

#define TNF_MIGRATED	0x01
#define TNF_NO_GROUP	0x02
#define TNF_SHARED	0x04
#define TNF_FAULT_LOCAL	0x08
#define TNF_MIGRATE_FAIL 0x10

#ifdef CONFIG_NUMA_BALANCING
extern void task_numa_fault(int last_node, int node, int pages, int priv, int flags);
extern pid_t task_numa_group_id(struct task_struct *p);
extern void set_numabalancing_state(bool enabled);
extern void task_numa_free(struct task_struct *p, bool final);
extern bool should_numa_migrate_memory(struct task_struct *p, struct page *page,
					int src_nid, int dst_cpu);
extern int page_numastate_update(struct page *, int last_cpupid);
extern int page_cpupid_set(struct task_struct *, struct page *);

/* Shared or private faults. */
#define NR_NUMA_HINT_FAULT_TYPES 2

/* Memory and CPU locality */
#define NR_NUMA_HINT_FAULT_STATS (NR_NUMA_HINT_FAULT_TYPES * 2)

/* Averaged statistics, and temporary buffers. */
#define NR_NUMA_HINT_FAULT_BUCKETS (NR_NUMA_HINT_FAULT_STATS * 2)

struct numa_sub_group {
        int nr_tasks;
        pid_t sgid;

        spinlock_t lock;
        struct list_head members;

        unsigned long faults[NR_NUMA_HINT_FAULT_STATS];
};

struct numa_group {
        refcount_t refcount;

        spinlock_t lock; /* nr_tasks, tasks */
        int nr_tasks;
        int max_nr_tasks;
        pid_t gid;
        int active_nodes;

        struct rcu_head rcu;
        unsigned long total_faults;
        unsigned long max_faults_cpu;
        /*  
         * Faults_cpu is used to decide whether memory should move
         * towards the CPU. As a consequence, these stats are weighted
         * more by CPU use than by memory faults.
         */
        //unsigned long *faults_cpu;
        //unsigned long faults[0];
        struct numa_sub_group nsg[0];
};

#else
static inline void task_numa_fault(int last_node, int node, int pages,
				   int priv, int flags)
{
}
static inline pid_t task_numa_group_id(struct task_struct *p)
{
	return 0;
}
static inline void set_numabalancing_state(bool enabled)
{
}
static inline void task_numa_free(struct task_struct *p, bool final)
{
}
static inline bool should_numa_migrate_memory(struct task_struct *p,
				struct page *page, int src_nid, int dst_cpu)
{
	return true;
}
static inline int page_numastate_update(struct page *page, int last_cpupid)
{
	return -1;
}
static inline int page_cpupid_set(struct task_struct *, struct page *)
{
	return 0;
}
#endif

#endif /* _LINUX_SCHED_NUMA_BALANCING_H */
