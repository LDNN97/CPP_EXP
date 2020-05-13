#include <fstream>
#include "taskflow/taskflow.hpp"

int evaluate(int x) {
    for (int i = 0;  i < 1000000; i++)
        x++;
    return x;
}

int main(){

    tf::Executor executor;

    // Create a taskflow of eight tasks
    tf::Taskflow taskflow;

    int nn[8] {1, 2, 3, 4, 5, 6, 7, 8};
    int ans[8] {};
    int anss;
    for (int i = 0; i < 8; i++) {
        auto item = taskflow.emplace([&nn, &ans, i]() { ans[i] = evaluate(nn[i]); });
        item.name(std::to_string(i));
    }
    // create a default observer
    auto observer = executor.make_observer<tf::ExecutorObserver>();

    // run the taskflow
    auto result = executor.run(taskflow);
    result.get();

    for (int i = 0; i < 8; i++)
        std::cout << i << " " << ans[i] << std::endl;

    // dump the execution timeline to json (view at chrome://tracing)
    std::ofstream ofs("timestamps.json");
    observer->dump(ofs);
    return 0;
}