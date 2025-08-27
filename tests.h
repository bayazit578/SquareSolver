#ifndef TESTS_H
#define TESTS_H

//------------------------------------------------------------
//! Run all unit tests;
//------------------------------------------------------------
void RunAll();

//------------------------------------------------------------
//! Run square equation solver test;
//!
//! @return Quantity of failed tests by square equation solver
//!
//------------------------------------------------------------
int Run_KBADPATKA();

//------------------------------------------------------------
//! Run linear equation solver test;
//!
//! @return Quantity of failed tests by linear equation solver
//!
//------------------------------------------------------------
int Run_LNHENKA();

//------------------------------------------------------------
//! Tests square equation solver
//!
//! @param [in]  line coefficients, reference roots
//!                   and reference number of roots
//!
//! @return 1 in case of fail, 0 in case of success
//!
//------------------------------------------------------------
int Test_KBADPATKA(struct TestSqu* quadro);

//------------------------------------------------------------
//! Tests linear equation solver
//!
//! @param [in]  line coefficients, reference roots
//!                   and reference number of roots
//!
//! @return 1 in case of fail, 0 in case of success
//!
//------------------------------------------------------------
int Test_LNHENKA(struct TestLine* line);

#endif // TESTS_H
