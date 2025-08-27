#ifndef DIALOGUE_H
#define DIALOGUE_H


//------------------------------------------------------------
//! Output results of program execution in case of correct
//! input from the user
//!
//! @param [in] roots actual quantity of roots in equation
//! @param [in] x1    1st root
//! @param [in] x2    2nd root
//!
//------------------------------------------------------------
void Correct_Input(int var, double x1, double x2);

//------------------------------------------------------------
//! Output results of program execution in case of incorrect
//! input from the user
//!
//! @return true in case of continue the program, false in
//!         end the program
//!
//------------------------------------------------------------
bool Incorrect_Input();

#endif // DIALOGUE_H
