/*-------------------------------------------------------------------------------------------------------
 *[FILE_NAME]   : common_macros.h
 *[AUTHOR] 		: Mohamed_Abdelhamid_Sayed
 *[DATE] 		: 27, march 2023
 *[DESCRIPTION] : this file contains most macros used for Micro-controller dealings with peripherals
 *-------------------------------------------------------------------------------------------------------*/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/*put 1 on the required bit*/
#define SET_BIT(REG,BIT_NUM) (REG = (REG | (1<<BIT_NUM)))

/*put 0 on the required bit*/
#define CLEAR_BIT(REG,BIT_NUM) (REG = (REG & (~(1<<BIT_NUM))))

/*toggle the required bit*/
#define TOGGLE_BIT(REG,BIT_NUM) (REG = REG ^ (1<<BIT_NUM))

/*rotate right the number of bits required*/
#define ROR(REG,NUM) (REG = (REG >> NUM) | (REG << (8-NUM)))

/*rotate left the number of bits required*/
#define ROL(REG,NUM) (REG = (REG << NUM) | (REG >> (8-NUM)))

/*check if the bit has one from PINX register*/
#define BIT_IS_SET(REG,BIT_NUM) (REG & (1<<BIT_NUM))

/*check if the bit has zero from PINX register*/
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG & (1<<BIT_NUM)))

/*Get Bit at any register*/
#define GET_BIT(REG, BIT) ( (REG & (1<<BIT) ) >> BIT)

#endif
