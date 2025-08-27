#ifndef SOLVER_H
#define SOLVER_H

//------------------------------------------------------------
//! Solves all types of square equation ax2 + bx + c = 0;
//!
//! @param [in]  coeff_a a-coefficient
//! @param [in]  coeff_b b-coefficient
//! @param [in]  coeff_c c-coefficient
//! @param [out] x1      Pointer to the 1st root
//! @param [out] x2      Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns Quantity_Infinity
//------------------------------------------------------------
int solution_both(double coeff_a, double coeff_b, double coeff_c,
                  double* x1, double* x2);

//------------------------------------------------------------
//! Solves types of square equation ax2 + bx + c = 0
//! with a non-zero a-coefficient
//!
//! @param [in]  coeff_a a-coefficient
//! @param [in]  coeff_b b-coefficient
//! @param [in]  coeff_c c-coefficient
//! @param [out] x1      Pointer to the 1st root
//! @param [out] x2      Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns Quantity_Infinity.
//------------------------------------------------------------
int solution_square(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2);

//------------------------------------------------------------
//! Solves all types of linear equation bx + c = 0
//!
//! @param [in]  coeff_a a-coefficient
//! @param [in]  coeff_b b-coefficient
//! @param [in]  coeff_c c-coefficient
//! @param [out] x1      Pointer to the 1st root
//! @param [out] x2      Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns Quantity_Infinity.
//------------------------------------------------------------
int solution_linear(double coeff_b, double coeff_c, double* x1);

enum Quantity {
    Quantity_Zero = 0,
    Quantity_One = 1,
    Quantity_Two = 2,
    Quantity_Infinity = 3
};

#endif // SOLVER_H
