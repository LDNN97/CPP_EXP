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
    auto A = taskflow.emplace([&nn, &ans] () { ans[0] = evaluate(nn[0]); });
    auto B = taskflow.emplace([&nn, &ans] () { ans[1] = evaluate(nn[1]); });
    auto C = taskflow.emplace([&nn, &ans] () { ans[2] = evaluate(nn[2]); });
    auto D = taskflow.emplace([&nn, &ans] () { ans[3] = evaluate(nn[3]); });
    auto A1 = taskflow.emplace([&nn, &ans] () { ans[4] = evaluate(nn[4]); });
    auto B1 = taskflow.emplace([&nn, &ans] () { ans[5] = evaluate(nn[5]); });
    auto C1 = taskflow.emplace([&nn, &ans] () { ans[6] = evaluate(nn[6]); });
    auto D1 = taskflow.emplace([&nn, &ans] () { ans[7] = evaluate(nn[7]); });
    A.name("A");
    B.name("B");
    C.name("C");
    D.name("D");
    A1.name("A1");
    B1.name("B1");
    C1.name("C1");
    D1.name("D1");


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