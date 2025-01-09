#ifndef LITECHFRAMEWORK_PRINT_H
#define LITECHFRAMEWORK_PRINT_H

#ifdef LITECH_DEBUG
template <typename ... Args>
void liTechPrint(std::string str, Args&& ... args) {
    printf("[liTech]: ");
    printf(str.c_str(), std::forward<Args>(args)...);
    putchar('\n');
}
#else
template <typename ... args>
void liTechPrint(std::string str, Args&& ... args) {
}
#endif

#endif