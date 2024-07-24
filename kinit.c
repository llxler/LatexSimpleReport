void kinit() {
    initlock(&kmem.lock, "kmem");
    kmem.npage = 0;
    kmem.freelist = 0;
    freerange(kernel_end, (void *)PHYSTOP);
#ifdef DEBUG
    printf("kernel_end: %p, phystop: %p\nkinit\n", kernel_end, (void *)PHYSTOP);
#endif
}