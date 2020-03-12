#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <string>
#include <utility>
#include <iostream>
#include <array>

namespace py = pybind11;

//int add(int i, int j) {
//    return i + j;
//}
//
//struct Person{
//    std::string name;
//    explicit Person(std::string  na): name(std::move(na)) {};
//    void set_name(const std::string & na) { name = na;}
//    std::string get_name() {return name;}
//};

//PYBIND11_MODULE(mine, m) {
//    m.doc() = "pybind11 example plugin"; // optional module docstring
//    m.def("add", &add, py::arg("i")=1, py::arg("j")=1, "A function which adds two numbers");
//    m.attr("answer") = 42;
//    m.attr("answer1") = py::cast("hello");
//
//    py::class_<Person> (m, "Person")
//            .def(py::init<const std::string &>())
//            .def_property("name", &Person::get_name, &Person::set_name)
//            .def("set_name", &Person::set_name)
//            .def("get_name", &Person::get_name);
//}

int main() {
    py::scoped_interpreter guard{};
//    py::object gym = py::module::import("gym");
//    py::object env = gym.attr("make")("CartPole-v1");

//    py::object state = env.attr("reset")();
//    py::array_t<double, py::array::c_style | py::array::forcecast> st(state);
//    std::vector<double> array_vec(st.size());
//    auto stt = new double [st.size()];
//    std::memcpy(stt, st.data(), st.size() * sizeof(double));
//    std::memcpy(array_vec.data(), st.data(), st.size() * sizeof(double));
//    for (int i = 0; i < 4; i++)
//        std::cout << stt[i] << std::endl;

//    py::list nst_or = env.attr("step")(1);
//    py::array_t<double, py::array::c_style | py::array::forcecast> nst_tr(nst_or[0]);
//    std::vector<double> nst(nst_tr.size());
//    std::memcpy(nst.data(), nst_tr.data(), nst_tr.size() * sizeof(double));
//    for (int i = 0; i < 4; i++)
//        std::cout << nst[i] << std::endl;
//    std::cout << py::cast<double>(nst_or[1]) << " " << py::cast<bool>(nst_or[2]) << std::endl;

//    py::object random = py::module::import("numpy.random");
//    py::object inistate = random.attr("uniform")(-0.05, 0.05, 4);
//    py::print(inistate);
//    env.attr("reset_ini")();
//    py::object state = env.attr("reset")();
//    py::list nst_or = env.attr("step")(1);
//    py::print(nst_or[0]);
//    env.attr("back_step")();
//    nst_or = env.attr("step")(1);
//    py::print(nst_or[0]);


//
//    env.attr("close")();
//    env.attr("render")(2);
//    return 0;
    int n[10];
    for (int i = 0; i < 10; i++)
        n[i] = i;
    std::array<double, 10> nn {};
    for (int i = 0; i < 10; i++) nn[i] = n[i];
//    std::for_each(nn.begin(), nn.end(), [&j, n](int &v){v = n[j++];});
    for (auto item : nn)
        std::cout << item << std::endl;

    std::array<double, 10> nn2 {};
    for (int i = 0; i < 10; i++) nn2[i] = i * i;

    py::object n1 = py::cast(nn);
    py::object n2 = py::cast(nn2);
    py::object plt = py::module::import("matplotlib.pyplot");
    plt.attr("plot")(n1,"r", n2, "b");
    plt.attr("show")();
}

//import time
//import gym
//import numpy as np
//
//env = gym.make('FetchReach-v1')
//obs = env.reset()
//done = False
//while not done:
//action = obs['desired_goal'] - obs['achieved_goal']
//action = np.append(action, 0)
//obs, reward, done, info = env.step(action)
//env.render()
//time.sleep(5)
//env.close()
