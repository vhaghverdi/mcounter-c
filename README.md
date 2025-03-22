# Mom's Counter in C Minor

This project is a C port of _Mom's Counter_, a programming exercise from [**Savitch's C++ textbook**](https://www.pearson.com/en-us/subject-catalog/p/problem-solving-with-c/P200000003225/9780137982226) (chapter 10 on classes). It showcases two potential solutions to the lack of classes in C.

Each solution type is created as a [**static library**](https://en.wikipedia.org/wiki/Static_library), which is then used by the demo and test clients.

Unit testing is performed using the [**Unity**](https://www.throwtheswitch.org/unity) testing framework.

## Procedural Solution

We create an [**opaque data type**](https://en.wikipedia.org/wiki/Opaque_data_type) called `MCounter`. The member variables of this struct are not visible to clients. It is constructed dynamically by calling a constructor function, `mc_new` or `mc_new_n`.

Due to C's lack of [**namespaces**](https://en.wikipedia.org/wiki/Namespace), the functions in the interface are all prefixed with `mc_` (e.g., `mc_add_100`). As `MCounter` is created dynamically, it must be freed by calling `mc_free`.

## Object-Oriented Solution

In the second approach, we create a structure called `MooCounter` that is more object-oriented in nature as it contains [**function pointers**](https://en.wikipedia.org/wiki/Function_pointer). As C lacks the [**syntactic sugar**](https://en.wikipedia.org/wiki/Syntactic_sugar) for object orientation, the object itself is, by convention, passed in as the first argument (similar to Python's `self` parameter).

The only functions callable from outside `MooCounter` objects are the constructors, `mooc_new` and `mooc_new_n`. These constructors take on the additional responsibility of binding each new object's function pointers to the corresponding function definitions.

As `MooCounter` is not opaque, "private" variables are denoted with an underscore prefix (e.g., `_count`). Objects are freed by calling a member function (e.g., `my_counter->free(&my_counter)`).
