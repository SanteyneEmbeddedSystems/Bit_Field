#include "Bit_Field.h"


/*============================================================================*/
void Set_Bit_Block( uint8_t* block, uint8_t bit_index )
{
    block[bit_index/8] |= SET_MASK[bit_index%8];
}
/*----------------------------------------------------------------------------*/
void Reset_Bit_Block( uint8_t* block, uint8_t bit_index )
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
            Reset_Bit_Block( output_block, out_bit_idx );
        }
    }
}
