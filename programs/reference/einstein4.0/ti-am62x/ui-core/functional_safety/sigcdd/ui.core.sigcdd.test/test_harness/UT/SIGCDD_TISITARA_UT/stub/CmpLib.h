
#define CMPLIB_INSTANCE( name )  \
    static Std_ReturnType CmpInit ( void ); \
    static Std_ReturnType CmpDeInit ( void ); \
    static Std_ReturnType CmpActive ( void ); \
    static Std_ReturnType CmpActivation ( void ); \
    static Std_ReturnType CmpDeActivation ( void ); \
    static Std_ReturnType CmpDiag ( void ); \
    static Std_ReturnType CmpDiagReturn ( void );