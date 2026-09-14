#ifndef ECCTEST_H
#define ECCTEST_H

#define ECC_FIT_ENABLE      STD_OFF

#if (ECC_FIT_ENABLE == STD_ON)
extern void EccTest_MainFunction(void);
extern void EccTest_ExecuteTestCase(uint8 TestCase);
#endif

#if defined(ECC_ICACHE_TEST) || defined(ECC_DCACHE_TEST)
extern void EccTest_CacheTest(void);
#endif


#endif
