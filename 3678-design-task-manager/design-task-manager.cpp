class TaskManager {
    priority_queue<pair<int,int>> tasks;
    unordered_map<int,int> tpriority;
    unordered_map<int,int> owner;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(const auto& task : tasks) {
            add(task[0],task[1], task[2]);
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        tasks.push({priority,taskId});
        tpriority[taskId] = priority;
        owner[taskId] = userId;
        
    }
    
    void edit(int taskId, int newPriority) {
        tasks.push({newPriority, taskId});
        tpriority[taskId] = newPriority;
        
    }
    
    void rmv(int taskId) {
        tpriority[taskId] = -1;
        
    }
    
    int execTop() {

        while(!tasks.empty()) {
            auto task = tasks.top();
            tasks.pop();
            if(task.first == tpriority[task.second]) {
                tpriority[task.second] = -1;
                return owner[task.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */