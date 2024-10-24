#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Bit_Field.h"

int main()
{
    /* Tests on bit field on a byte */
    uint8_t byte_1 = 0;
    assert( byte_1 == 0 );
    for ( uint8_t bit_idx = 0; bit_idx < 8; bit_idx++ )
    {
        assert( TEST_BIT(byte_1, bit_idx) == false );
    }

    for (uint8_t bit_idx = 0; bit_idx < 8; bit_idx++)
    {
        SET_BIT( byte_1, bit_idx );
        assert( TEST_BIT( byte_1, bit_idx ) == true );
        CLEAR_BIT( byte_1, bit_idx );
        assert( TEST_BIT( byte_1, bit_idx ) == false );
    }
    
    /* Tests on bit field on a word */
    uint16_t word_1 = 0;
    assert( word_1 == 0 );
    for ( uint8_t bit_idx = 0; bit_idx < 16; bit_idx++ )
    {
        assert( TEST_BIT(word_1, bit_idx) == false );
    }

    for (uint8_t bit_idx = 0; bit_idx < 16; bit_idx++)
    {
        SET_BIT( word_1, bit_idx );
        assert( TEST_BIT( word_1, bit_idx ) == true );
        CLEAR_BIT( word_1, bit_idx );
        assert( TEST_BIT( word_1, bit_idx ) == false );
    }

    /* Tests on bit field on a block */
    uint8_t block_40[5] = { 0 };
    for ( uint8_t bit_idx = 0; bit_idx < 40; bit_idx++ )
    {
        assert( Test_Bit_Block( block_40, bit_idx ) == false );
    }

    for (uint8_t bit_idx = 0; bit_idx < 8; bit_idx++)
    {
        Set_Bit_Block( block_40, bit_idx );
        assert( Test_Bit_Block( block_40, bit_idx ) == true );
        Clear_Bit_Block( block_40, bit_idx );
        assert( Test_Bit_Block( block_40, bit_idx ) == false );
    }

    return EXIT_SUCCESS;
}
