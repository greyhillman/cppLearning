// A identifier's scope determines where it is accessible
// Block/local scope: only be accessed within the block of declaration
// global/file scope: only be accessed within the file

// A variable's duration determines when it is created and destroyed
// Automatic duration: created at block start; destroyed at block exit
// Static duration: created at program start; destroyed at program end
// dynamic duration: created by programmer; destroyed by programmer

// An identifier's linkage determines whether multiple instances of an
// identifier refer to the same identifier or not.
// No linkage: Identifier only refers to itself
// internal linkage: refers to the identifier only within the file of declaration
// external linkage: accessed within multiple files

// Forward declaration to access function in other file
// extern keyword for access to variable with external linkage in another file
