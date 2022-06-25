# Round-Robbin-using-queues 
One of the main functions of an operation system (OS) is to schedule programs in executions
(aka "processes"). Round Robin is a popular scheduling algorithm, where new processes join the
back of a FIFO queue. The OS picks the process at the front of the queue to run on the processor.
After a specified time (called quantum), the OS preempts the process, takes it away from the
processor, puts it at the back of the queue, and picks the process at the front of the queue to run
on the processor, and so on. If a process halts (i.e., finishes execution), it leaves the processor and
the OS picks the process from the queue front to run on the processor.
This project simulates how a processor schedules processes using the round robbin algorithm. This was implemented using queues that were written from scratch.
