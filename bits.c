/* 
 * CS:APP Data Lab 
 * 
 * Marika Murphy mmm7782
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
//shift desired byte to LSB and use mask to extract
  return ((x >> (n<<3)) & (0xff)) ;

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
//do arithmetic shift, and create mask of 0s to account for negatives
//mask:put 1 as MSB, rest = 0s, copy 1s n-1 times, then flip
	
  return (x >> n) & ~(((0x1<<31) >> n)<<1);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  	int pat2 = (0x55 << 8)+0x55; //0101...
	int pat4 = (0x33 << 8) + 0x33;//0011...
	int pat8 = (0x0f << 8)+ 0x0f;//00001111...
	int pat16 = (0xff << 16) + 0xff;
	int pat32 = (0xff <<8) + 0xff;
	pat2 = (pat2 << 16) + pat2;
	pat4 = (pat4 << 16) + pat4;
	pat8 = (pat8 << 16) + pat8;
	
	//add up # of 1s in e/ two bits and store in 2 bits
	//00->00 01->01 10->01 11->10
	x = (x & pat2 ) + ((x >>  1) & pat2 ); 
    	x = (x & pat4 ) + ((x >>  2) & pat4 ); //repeat with 4 bits
    	x = (x & pat8 ) + ((x >>  4) & pat8 ); //repeat with 8
    	x = (x & pat16 ) + ((x >>  8) & pat16 );  //with 16
    	x = (x & pat32) + ((x >> 16) & pat32); //with 32 

    	return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
//(x | (~x+1)) will make the most significant sign bit 1 if x!=0
//or 0 if x=0
//>>31 to make all 0s or all 1s
//add 1 to flip -1 to 0 and 0 to 1
  return ((x | (~x+1))>>31)+1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
//minimum is 0x80000000
  return (0x01<<31); 
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
//shift left  (32-n) than right (32-n)
//if unchanged -> it works!
	int shift = 0x20 + (~n + 0x01);
  return !(((x<<shift)>>shift)^x);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <=30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^| + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	//1 if x negative, 0 if positive
	int mask = (x >> 31) & ((1 << n) + ~0);
	//add mask to round towards 0
	return (x + (mask)) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
//2's complement
  return (~x+1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	//1 if x<0 0 if x>=0
	int sign_x = (x >> 31);
	//1 if 0, 0 if not
	int isZero = !((~x+1)^x);
	
  	return !(isZero|sign_x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  	//1 if neg, 0 if pos
        int sign_x = x >> 31;

        //1 if neg, 0 if pos
        int sign_y = y >> 31;

	// if same sign
	// if x larger, sign bit of (~y + x) is 0
	// if x smaller, sign bit of (~y + x) is 1
	int same_sign = (!(sign_x ^ sign_y)) & ((~y + x) >> 31);

	// if opp signs check if x pos and y neg
	int dif_sign = sign_x & (!sign_y);

	return ( same_sign | dif_sign);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */	
int ilog2(int x) {

	int pat2 = (0x55 << 8)+0x55; //0101...
	int pat4 = (0x33 << 8) + 0x33;//0011...
	int pat8 = (0x0f << 8)+ 0x0f;//00001111...
	int pat16 = (0xff << 16) + 0xff;
	int pat32 = (0xff <<8) + 0xff;
	pat2 = (pat2 << 16) + pat2;
	pat4 = (pat4 << 16) + pat4;
	pat8 = (pat8 << 16) + pat8;
	
	//find highest bit of 1 and set all bits after it to 1
 	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	
	//add up # of 1s in e/ two bits and store in 2 bits
	//00->00 01->01 10->01 11->10
	x = (x & pat2 ) + ((x >>  1) & pat2 ); 
    	x = (x & pat4 ) + ((x >>  2) & pat4 ); //repeat with 4 bits
    	x = (x & pat8 ) + ((x >>  4) & pat8 ); //repeat with 8
    	x = (x & pat16 ) + ((x >>  8) & pat16 );  //with 16
    	x = (x & pat32) + ((x >> 16) & pat32); //with 32

	//after count number of '1's, subtract 1
    return x+~0;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 
	//get exponent
	int exponent = (uf >> 23) & 0xFF; 
	//get fractional part
	int fraction = (uf << 9);  
	//if exponent all 1s and fraction is not all 0s ->Nan
	if ((exponent == 0xFF) && (fraction) != 0) 
	{
  		return uf; 
	}
	
	//otherwise flip sign bit
	return uf ^ (1 << 31);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	int round = 0;
	int exp = 0;
	int sign_mask = 0x01<<31;
	int sign = x & sign_mask;
	int frac_mask = ~((sign_mask)>>8);
	int frac = 0;
	//absolute value
	if (sign) x = -x;
	//if max int -> return equivalent fraction
	if (x == sign_mask)
	{			
		return 0xcf<<24;
	}
	//if 0, still 0
	if(x == 0) 
		return 0; 
	
	// calculate the exp 
    	while ((x >> (exp+1)) != 0) {
        	exp ++;
    	}
	//clear to left of msb
	x = x << (31 - exp); 
	//get fraction
  	frac = (x >> 8) & frac_mask;

	// round to even (nearest) 
  	if (exp > 23) {
    		round = x & 0xFF; // byte to round

    		if ((round > 128) || ((round == 128) && (frac & 1))) {
      			frac += 1;
      			if (frac >> 23) {
        				exp += 1;
        				frac = 0;
      			} 
    		}
  	}
	//add bias and shift to proper spot
	exp = (exp +127) <<23;
	return sign + exp + frac;

}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

	int exponent = (uf >> 23) & 0xFF;
    	int sign = uf & (0x01<<31);
	int edge = (((0x7f<<8)+0xff)<<8)+0xff;
    	int fraction = uf & edge;
	//if denormalized, return it
    	if (exponent == 255 || (exponent == 0 && fraction == 0))
        	return uf;
	//multiply by 2
    	if (exponent) {
        	exponent++;
    	} 
	//if on the edge, decremement fraction and increment exponent
	else if (fraction == edge) {
        	fraction--;
        	exponent++;
    	} 
	//multiply by 2
	else {
        	fraction <<= 1;
    	}

    	return (sign) + (exponent << 23) + (fraction); 

}
