#import <Foundation/Foundation.h>

CF_EXTERN_C_BEGIN

#define FLOAT_PRECISION (1e-6)

//==0
CF_EXPORT bool insFloatE0(double var);
//==
CF_EXPORT bool insFloatE(double var1, double var2);
//<
CF_EXPORT bool insFloatL(double var1, double var2);
//<=
CF_EXPORT bool insFloatLE(double var1, double var2);
//>
CF_EXPORT bool insFloatG(double var1, double var2);
//>=
CF_EXPORT bool insFloatGE(double var1, double var2);

CF_EXTERN_C_END
