void yield(void) {
    struct proc *Proc = myproc();    // 获取当前进程
    acquire(&Proc->lock);            // 获取进程锁
    Proc->state = RUNNABLE;          // 将进程状态设置为可运行
    sched();                         // 调度其他进程
    release(&Proc->lock);            // 释放进程锁
}