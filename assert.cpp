#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------
//! Verifies the validity of the assertions
//!
//! @param [in] condition condition
//! @param [in] exp       content of the condition
//! @param [in] file      error location file
//! @param [in] function  error location function
//! @param [in] line      error location line
//!
//------------------------------------------------------------
void ASSsert(int condition, const char* exp, const char* file, const char* function, int line) {
    if (!condition) {
        fprintf(stderr, "Assertion failed: %s\n In file: %s, function %s, line %d.\n", exp, file, function, line);
        abort();
    }
}
