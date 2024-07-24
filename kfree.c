void kfree(void *phys_addr) {
    struct run *r_ptr;

    if (kernel_end > (char *)phys_addr || PHYSTOP <= (uint64)phys_addr ||
        ((uint64)phys_addr % PGSIZE) != 0)
        panic("kfree");

    memset(phys_addr, 1, PGSIZE);
    r_ptr = (struct run *)phys_addr;
    acquire(&kmem.lock);
    r_ptr->next = kmem.freelist;
    kmem.freelist = r_ptr;
    ++kmem.npage;
    release(&kmem.lock);
}