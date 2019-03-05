//
//

#include "Thread.hpp"

Thread::Thread(){}


Thread::Thread(ifstream &fin, int thd_priority, int t_arrival, int bCount, int thread_id, int pproc){
    arrivalTime = t_arrival;
    burstCount = bCount;
    priority = thd_priority;
    thd_state = 0;
    id = thread_id;
    parent_proc = pproc;
    //inputFile = fin; 
    
    //loop to add bursts
    for(int i = 0; i < (bCount - 1); i ++){
        bursts.push(this->nxtBst(fin));
    }
    //add the last cpu burst
    int finalBurst;
    fin >> finalBurst;
    Burst* final = new Burst(finalBurst, 0);
    bursts.push(final);
}

Burst* Thread::nxtBst(ifstream &fin){
    int t_cpu, t_io; 
    fin >> t_cpu >> t_io;
    Burst* burst = new Burst(t_cpu, t_io);
    return burst;
};

queue<Burst*> Thread::getBurstQ(){
    return bursts; 
};

int Thread::getArrival(){
    return arrivalTime;
};

int Thread::getBurstCount(){
    return burstCount;
};

int Thread::getThreadID(){
    return id;
};

int Thread::getPriority(){
    return priority;
};

int Thread::getParentID(){
    return parent_proc;
};

