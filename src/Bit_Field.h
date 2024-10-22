#ifndef BIT_FIELD_H
#define BIT_FIELD_H

#include <stdint.h>
#include <stdbool.h>


/*============================================================================*/
void Set_Bit_Byte( uint8_t* field, uint8_t bit_index );
void Reset_Bit_Byte( uint8_t* field, uint8_t bit_index );
bool Test_Bit_Byte( const uint8_t* field, uint8_t bit_index );


/*============================================================================*/
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
