/********************************************************************
Engineer        : Omar Elsobkey
Version         : 1.0
Date            : 10/7/2021
********************************************************************/

#ifndef MACROS
#define MACROS

#define SET_BIT(REG, BIT) ((REG) |= (1 << (BIT)))
#define TOG_BIT(REG, BIT) ((REG) ^= (1 << (BIT)))
#define CLR_BIT(REG, BIT) ((REG) &= ~(1 << (BIT)))
#define GET_BIT(REG, BIT) (((REG) >> (BIT)) & 1)

#endif