void yield(void) {
    struct proc *Proc = myproc();
    acquire(&Proc->lock);
    Proc->state = RUNNABLE;
    sched();
    release(&Proc->lock);
}