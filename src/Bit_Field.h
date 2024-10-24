#ifndef BIT_FIELD_H
#define BIT_FIELD_H

#include <stdint.h>
#include <stdbool.h>


/*============================================================================*/
/*
Bits are ordered from 0, the LSB, to 7, the MSB.
*/
static const uint8_t SET_MASK[8] =
    { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

static const uint8_t CLEAR_MASK[8] =
    { 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F };

#define SET_BIT( field, bit )    (field |= SET_MASK[bit])
#define CLEAR_BIT( field, bit )  (field &= CLEAR_MASK[bit])
#define TEST_BIT( field, bit )   ((field & SET_MASK[bit]) ? true : false)


/*============================================================================*/
/*
On each byte, bits are ordered from 0, the LSB, to 7, the MSB.
On the block bits are ordered as follow :
7 6 5 4 3 2 1 0 15 14 13 12 11 10 9 8 23 22 21 20 19 18 17 16 etc.
*/
void Set_Bit_Block( uint8_t* block, uint8_t bit_index );
void Reset_Bit_Block( uint8_t* block, uint8_t bit_index );
bool Test_Bit_Block( const uint8_t* block, uint8_t bit_index );
/* Permute_Bits
output_block_size :
    Nb of bits in output_block (=8*array size).
permutation_table : 
    Its size equals output_block_size.
    It is a list of indexes.
    The nth element of permutation_table is the index of the bit of the
    input_block that is set at the nth bit of the output block.
*/
void Permute_Bits(
    const uint8_t* input_block,
    uint8_t output_block_size,
    uint8_t* output_block,
    const uint8_t* permutation_table );

#endif
