void freerange(void *pa_st, void *pa_ed) {
    char *page_ptr;
    
    // 将起始地址向上对齐到页面边界
    page_ptr = (char *)PGROUNDUP((uint64)pa_st);
    
    // 释放从 page_ptr 到 pa_ed 之间的每一页
    for (; (char *)pa_ed >= PGSIZE + page_ptr; page_ptr += PGSIZE) {
        kfree(page_ptr); // 释放页面
    }
}
