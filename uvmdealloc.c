int npages = (PGROUNDUP(presz) - PGROUNDUP(newsz)) / PGSIZE;
vmunmap(kpgtb, PGROUNDUP(newsz), npages, 0),
vmunmap(pgtb, PGROUNDUP(newsz), npages, 1);