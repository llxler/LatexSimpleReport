for (uint64 a = presz; newsz > a; a += PGSIZE) {
    mem = kalloc();  // 分配一个新的页面
    if (NULL == mem) {
        uvmdealloc(pgtb, kpgtb, a, presz);  // 分配失败，解除分配
        return 0;
    }
    memset(mem, 0, PGSIZE);  // 将新分配的页面清零
    if (mappages(pgtb, a, PGSIZE, (uint64)mem, PTE_W | PTE_X | PTE_R | PTE_U)) {
        kfree(mem);  // 映射失败，释放页面
        uvmdealloc(pgtb, kpgtb, a, presz);  // 解除分配
        return 0;
    }
    if (mappages(kpgtb, a, PGSIZE, (uint64)mem, PTE_W | PTE_X | PTE_R)) {
        int npages = (a - presz) / PGSIZE;
        vmunmap(pgtb, presz, npages + 1, 1);  // 解除用户页映射
        vmunmap(kpgtb, presz, npages, 0);     // 解除内核页映射
        return 0;
    }
}
