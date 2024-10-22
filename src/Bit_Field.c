#include "Bit_Field.h"


static const uint8_t SET_MASK_BYTE[8] =
    { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };

static const uint8_t RESET_MASK_BYTE[8] =
    { 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE };


/*============================================================================*/
void Set_Bit_Byte( uint8_t* field, uint8_t bit_index )
{
    (*field) |= SET_MASK_BYTE[bit_index];
}
/*----------------------------------------------------------------------------*/
void Reset_Bit_Byte( uint8_t* field, uint8_t bit_index )
{
    (*field) &= RESET_MASK_BYTE[bit_index];
}
/*----------------------------------------------------------------------------*/
bool Test_Bit_Byte( const uint8_t* field, uint8_t bit_index )
{
    return  ((*field) & SET_MASK_BYTE[bit_index]) ? true : false;
}


/*============================================================================*/
void Set_Bit_Block( uint8_t* block, uint8_t bit_index )
{
    block[bit_index/8] |= SET_MASK_BYTE[bit_index%8];
}
/*----------------------------------------------------------------------------*/
void Reset_Bit_Block( uint8_t* block, uint8_t bit_index )
{
    block[bit_index/8] &= RESET_MASK_BYTE[bit_index%8];
}
/*----------------------------------------------------------------------------*/
bool Test_Bit_Block( const uint8_t* block, uint8_t bit_index )
{
    return ((block[bit_index/8]&SET_MASK_BYTE[bit_index%8])!=0)?true:false;
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
