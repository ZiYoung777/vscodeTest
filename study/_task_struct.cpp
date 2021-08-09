struct task_struct

{

    long state; /*任务的运行状态（-1 不可运行，0 可运行(就绪)，>0 已停止）*/

    long counter; /*运行时间片计数器(递减)*/

    long priority; /*优先级*/

    long signal; /*信号*/

    struct sigaction sigaction[32]; /*信号执行属性结构，对应信号将要执行的操作和标志信息*/

    long blocked; /* bitmap of masked signals */

    /* various fields */

    int exit_code; /*任务执行停止的退出码*/

    unsigned long start_code, end_code, end_data, brk, start_stack; /*代码段地址 代码长度（字节数） 

                                        代码长度 + 数据长度（字节数）总长度 堆栈段地址*/

    long pid, father, pgrp, session, leader; /*进程标识号(进程号) 父进程号 父进程组号 会话号 会话首领*/

    unsigned short uid, euid, suid; /*用户标识号（用户id） 有效用户id 保存的用户id*/

    unsigned short gid, egid, sgid; /*组标识号（组id） 有效组id 保存的组id*/

    long alarm; /*报警定时值*/

    long utime, stime, cutime, cstime, start_time; /*用户态运行时间 内核态运行时间 子进程用户态运行时间 

                               子进程内核态运行时间 进程开始运行时刻*/

    unsigned short used_math; /*标志：是否使用协处理器*/

    /* file system info */

    int tty; /* -1 if no tty, so it must be signed */

    unsigned short umask; /*文件创建属性屏蔽位*/

    struct m_inode *pwd; /*当前工作目录i 节点结构*/

    struct m_inode *root; /*根目录i节点结构*/

    struct m_inode *executable; /*执行文件i节点结构*/

    unsigned long close_on_exec; /*执行时关闭文件句柄位图标志*/

    struct file *filp[NR_OPEN]; /*进程使用的文件表结构*/

    /* ldt for this task 0 - zero 1 - cs 2 - ds&ss */

    struct desc_struct ldt[3]; /*本任务的局部描述符表。0-空，1-代码段cs，2-数据和堆栈段ds&ss*/

    /* tss for this task */

    struct tss_struct tss; /*本进程的任务状态段信息结构*/
};