/*
 * stdTypes.h
 *
 *  Created on	: Mar 31, 2020
 *  Version		: 1.0.0
 *  Author		: Ahmed El-Gaafarwy
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

/*typedef <dataType> <newName>*/

typedef unsigned char                 uint_8    ;
typedef unsigned short int            uint_16   ;
typedef unsigned long int             uint_32   ;
typedef unsigned long long int        uint_64   ;

typedef signed char                   sint_8    ;
typedef signed short int              sint_16   ;
typedef signed long int               sint_32   ;
typedef signed long long int          sint_64   ;


typedef unsigned char*                puint_8   ;
typedef unsigned short int*           puint_16  ;
typedef unsigned long int*            puint_32  ;
typedef unsigned long long int*       puint_64  ;

typedef signed char*                  psint_8   ;
typedef signed short int*             psint_16  ;
typedef signed long int*              psint_32  ;
typedef signed long long int*         psint_64  ;


typedef float                         f32       ;
typedef double                        f64       ;
typedef long double                   f80       ;

typedef char                          str       ;
typedef char*                         pstr      ;



#endif /* STDTYPES_H_ */
