// Copy user memory from parent to child.
if (0 > uvmcopy(p->pagetable, np->pagetable, np->kpagetable, p->sz)) {
    freeproc(np);
    release(&np->lock);
    return -1;
}
np->parent = p;
np->sz = p->sz;
// copy tracing mask from parent.
np->tmask = p->tmask;
// copy saved user registers.
*(np->trapframe) = *(p->trapframe);
// Cause fork to return 0 in the child.
np->trapframe->a0 = 0;
// increment reference counts on open file descriptors.
for (idx = 0; idx < NOFILE; ++idx)
    if (p->ofile[idx]) np->ofile[idx] = filedup(p->ofile[idx]);