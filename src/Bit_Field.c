#include "Bit_Field.h"

static const uint8_t SET_MASK[8] =
    { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };

static const uint8_t CLEAR_MASK[8] =
    { 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE };

/*============================================================================*/
void Set_Bit_Block( uint8_t* block, uint8_t bit_index )
{
    block[bit_index/8] |= SET_MASK[bit_index%8];
}
/*----------------------------------------------------------------------------*/
void Clear_Bit_Block( uint8_t* block, uint8_t bit_index )
{
    block[bit_index/8] &= CLEAR_MASK[bit_index%8];
}
/*----------------------------------------------------------------------------*/
bool Test_Bit_Block( const uint8_t* block, uint8_t bit_index )
{
    return ((block[bit_index/8] & SET_MASK[bit_index%8])!=0) ? true : false;
}
/*----------------------------------------------------------------------------*/
void Permute_Bits(
    const uint8_t* input_block,
    uint8_t output_block_size,
    uint8_t* output_block,
    const uint8_t* permutation_table )
{
    for ( uint8_t out_bit_idx=0; out_bit_idx<output_block_size; out_bit_idx++ )
    {
        uint8_t in_bit_idx = permutation_table[out_bit_idx];
        if( Test_Bit_Block( input_block, in_bit_idx ) )
        {
            Set_Bit_Block( output_block, out_bit_idx );
        }
        else
        {
            Clear_Bit_Block( output_block, out_bit_idx );
        }
    }
}
