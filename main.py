import sys


if __name__ == "__main__":
    sys.path.append("build")
    import my_ext

    print(my_ext.add(423, 123))
    print(my_ext.the_answer)

    rex = my_ext.Dog("Rex")
    print(rex)
    print(rex.bark())
