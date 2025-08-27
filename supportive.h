#ifndef LOGIC_H
#define LOGIC_H

//------------------------------------------------------------
//! Compares double numbers or NAN's
//!
//! @param [in] a 1st number / NAN
//! @param [in] b 2nd number / NAN
//!
//! @return true in case of equality,
//!         false in case of inequality
//!
//! @note   In case of both NAN's return true.
//------------------------------------------------------------
bool is_equal(double a, double b);

#endif // LOGIC_H
