int npages = (PGROUNDUP(presz) - PGROUNDUP(newsz)) / PGSIZE;
vmunmap(kpgtb, PGROUNDUP(newsz), npages, 0); // 解除内核页映射
vmunmap(pgtb, PGROUNDUP(newsz), npages, 1);  // 解除用户页映射