void *kalloc(void) {
    struct run *r_ptr;
    // 获取 kmem 锁，以确保分配操作的原子性
    acquire(&kmem.lock);
    // 从空闲列表中获取一个页面
    r_ptr = kmem.freelist;
    if (r_ptr != 0) {
        // 更新空闲列表，指向下一个空闲页面
        kmem.freelist = r_ptr->next;
        // 减少空闲页面计数
        --kmem.npage;
    }
    // 释放 kmem 锁
    release(&kmem.lock);
    // 如果成功分配页面，将其清零
    if (r_ptr != 0) memset((char *)r_ptr, 5, PGSIZE);
    // 返回分配的页面指针
    return (void *)r_ptr;
}
