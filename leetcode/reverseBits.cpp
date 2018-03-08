
// 190. Reverse Bits

// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
// return 964176192 (represented in binary as 00111001011110000010100101000000).

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        int l=1;
        while(l<32){
            if(n & 1 == 1){
                rev = rev ^ 1;
            }
            rev = rev << 1;
            n = n >> 1;
            l=l+1;
        }
        if(n & 1 == 1){
            rev = rev ^ 1;
        }
        return rev;
    }
};