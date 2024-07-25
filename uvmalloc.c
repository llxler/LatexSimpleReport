for (uint64 a = presz; newsz > a; a += PGSIZE) {
    mem = kalloc();
    if (NULL == mem) {
        uvmdealloc(pgtb, kpgtb, a, presz);
        return 0;
    }
    memset(mem, 0, PGSIZE);
    if (mappages(pgtb, a, PGSIZE, (uint64)mem,
                    PTE_W | PTE_X | PTE_R | PTE_U)) {
        kfree(mem);
        uvmdealloc(pgtb, kpgtb, a, presz);
        return 0;
    }
    if (mappages(kpgtb, a, PGSIZE, (uint64)mem, PTE_W | PTE_X | PTE_R)) {
        int npages = (a - presz) / PGSIZE;
        vmunmap(pgtb, presz, npages + 1, 1);
        vmunmap(kpgtb, presz, npages, 0);
        return 0;
    }
}