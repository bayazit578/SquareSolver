#ifndef ASSERT_H
#define ASSERT_H

#define MY_ASSERT(condition) ASSsert(condition, #condition, __FILE__, __PRETTY_FUNCTION__, __LINE__)

void ASSsert(int condition, const char* exp, const char* file, const char* function, int line);

#endif // ASSERT_H
