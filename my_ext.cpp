#include <string>
#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>  // Required to convert C++ std:string <-> Python str

namespace nb = nanobind;

int add(int a, int b = 1) { return a + b; }

struct Dog {
    std::string name;

    std::string bark() const {
        return name + ": woof!";
    }
};

NB_MODULE(my_ext, m) {
    m.doc() = "A simple example python extension";

    m.def("add", &add, nb::arg("a"), nb::arg("b") = 1,
          "This function adds two numbers and increments if only one is provided.");

    nb::class_<Dog>(m, "Dog")
        .def(nb::init<>())
        .def(nb::init<const std::string &>())
        .def("bark", &Dog::bark)
        .def_rw("name", &Dog::name);  // _rw stands for read/write access

    m.attr("the_answer") = 42;
}
