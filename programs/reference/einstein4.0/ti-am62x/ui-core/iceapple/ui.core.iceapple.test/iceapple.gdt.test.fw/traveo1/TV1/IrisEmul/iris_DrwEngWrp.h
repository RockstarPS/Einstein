#ifndef IRIS_DRWENGWRP_H
#define IRIS_DRWENGWRP_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    eFirstPoint,
    eNextPoint,
    eLastPoint,
    eInvalidPoint
}tSinglePoint;


typedef enum
{
    eLine,
    eBezierQuad,
    eBezierCubic,
    eInvalidCurve
}tDrawInstruction;

typedef enum
{
    eMML_GDC_DE_DATA_FORMAT_S16_6,       /**< Default: 32 bit Integer representing a signed fixed point s26.6 notation. */
    eMML_GDC_DE_DATA_FORMAT_FLOAT,       /**< 32 bit float. */
    eMML_GDC_DE_DATA_FORMAT_S32,         /**< 32 bit signed Integer. */
    eMML_GDC_DE_DATA_FORMAT_S16,         /**< 16 bit signed Integer. */
    eMML_GDC_DE_DATA_FORMAT_S08          /**< 8 bit signed Integer. */
} tMML_GDC_DE_DATA_FORMAT;

typedef struct DrwEng_coord_tag
{
    unsigned char cmd;
    float X[3];
    float Y[3];
} tDrwEng_coord;





#ifdef __cplusplus
}
#endif

#endif