void kfree(void *phys_addr) {
    struct run *r_ptr;

    // 检查物理地址的有效性
    if (kernel_end > (char *)phys_addr || PHYSTOP <= (uint64)phys_addr ||
        ((uint64)phys_addr % PGSIZE) != 0)
        panic("kfree");

    memset(phys_addr, 1, PGSIZE);       // 将页面内容全部设为 1
    r_ptr = (struct run *)phys_addr;    // 将物理地址转换为 struct run 指针
    acquire(&kmem.lock);                // 获取 kmem 锁，以确保操作的原子性
    r_ptr->next = kmem.freelist;        // 将该页面加入空闲列表
    kmem.freelist = r_ptr;              // 更新空闲列表头指针
    ++kmem.npage;                       // 增加空闲页面计数
    release(&kmem.lock);                // 释放 kmem 锁
}
