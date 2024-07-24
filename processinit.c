// Look in the process table for an UNUSED proc.
// If found, initialize state required to run in the kernel,
// and return with p->lock held.
// If there are no free procs, or a memory allocation fails, return 0.
static struct proc *allocproc(void) {
    struct proc *new_proc;
    for (new_proc = proc; &proc[NPROC] > new_proc; ++new_proc) {
        acquire(&new_proc->lock);
        if (new_proc->state != UNUSED) {
            release(&new_proc->lock);
        } else
            goto found;
    }
    return NULL;

found:
    new_proc->ktime = 1;
    new_proc->utime = 1;
    new_proc->pid = allocpid();
    new_proc->vma = NULL;
    if ((new_proc->trapframe = (struct trapframe *)kalloc()) == NULL) {
        release(&new_proc->lock);
        return NULL;
    }
    // An empty user page table.
    // And an identical kernel page table for this proc.
    if ((new_proc->pagetable = proc_pagetable(new_proc)) == NULL ||
        (new_proc->kpagetable = proc_kpagetable()) == NULL) {
        freeproc(new_proc);
        release(&new_proc->lock);
        return NULL;
    }

    new_proc->kstack = VKSTACK;

    // Set up new context to start executing at forkret,
    // which returns to user space.
    memset(&new_proc->context, 0, sizeof(new_proc->context));
    new_proc->context.ra = (uint64)forkret;
    new_proc->context.sp = PGSIZE + new_proc->kstack;
    return new_proc;
}
