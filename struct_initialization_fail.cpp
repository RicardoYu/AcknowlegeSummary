/* we can get the same issue in the website of Stack Overflow, and 
the title named "Why do I get “warning: missing initializer for member”? [-Wmissing-field-initializers]"

https://stackoverflow.com/questions/21658485/why-do-i-get-warning-missing-initializer-for-member-wmissing-field-initial

I'm wondering why I am getting an warning about initialization in one case, but not the other. The code is in a C++ source file, and using GCC 4.7 with -std=c++11.
*/
struct sigaction old_handler, new_handler;
//The above produces NO warnings with -Wall and -Wextra.

struct sigaction old_handler={}, new_handler={};
struct sigaction old_handler={0}, new_handler={0};
//The above produces warnings:
#if 0
warning: missing initializer for member ‘sigaction::__sigaction_handler’ [-Wmissing-field-initializers]
warning: missing initializer for member ‘sigaction::sa_mask’ [-Wmissing-field-initializers]
warning: missing initializer for member ‘sigaction::sa_flags’ [-Wmissing-field-initializers]
warning: missing initializer for member ‘sigaction::sa_restorer’ [-Wmissing-field-initializers]
#endif
/*I've read through How should I properly initialize a C struct from C++?, Why is the compiler throwing this warning: "missing initializer"? Isn't the structure initialized?, and bug reports like http://gcc.gnu.org/bugzilla/show_bug.cgi?id=36750. I don't understand why the uninitialized struct is not generating a warning, while the initialized struct is generating a warning.
*/
truct sigaction old_handler;
memset(&old_handler,0,sizeof(sigaction));

