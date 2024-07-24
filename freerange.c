void freerange(void *pa_st, void *pa_ed) {
    char *page_ptr;
    page_ptr = (char *)PGROUNDUP((uint64)pa_st);
    for (; (char *)pa_ed >= PGSIZE + page_ptr; page_ptr += PGSIZE) {
        kfree(page_ptr);
    }
}