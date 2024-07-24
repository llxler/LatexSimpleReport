void *kalloc(void) {
    struct run *r_ptr;
    acquire(&kmem.lock);
    r_ptr = kmem.freelist;
    if (r_ptr != 0) {
        kmem.freelist = r_ptr->next;
        --kmem.npage;
    }
    release(&kmem.lock);
    if (r_ptr != 0) memset((char *)r_ptr, 5, PGSIZE);
    return (void *)r_ptr;
}