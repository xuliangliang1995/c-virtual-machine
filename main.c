#include <stdio.h>

typedef unsigned long long MarkWord;
typedef unsigned int Bit;
#define BIT_0 0b0
#define BIT_1 0b1

void Print_MarkWord(const MarkWord *markWord) {
    int bit_size = sizeof(MarkWord) * 8;
    for (int i = 0; i < bit_size; ++i) {
        Bit bit = *markWord >> (bit_size - 1 - i) & 0x01;
        printf("%d", bit);
    }
    printf("\n");
}

void Replace_MarkWord_Bit(MarkWord *markWord, int position, Bit bit) {
    MarkWord _bak = 0b0;
    int bit_size = sizeof(MarkWord) * 8;
    for (int i = 0; i < bit_size; ++i) {
        Bit _bit = (i == position) ? bit : (*markWord >> (bit_size - 1 - i) & 0b1);
        _bak = (_bak + _bit) << ((i + 1 == bit_size) ? 0 : 1);
    }
    *markWord = _bak;
}

Bit MarkWord_Bit(const MarkWord *markWord, int position) {
    return *markWord >> (63 - position) & 0b1;
}

int main() {
    MarkWord markWord = 0b0000000000000000000000000000000000000000000000000000000000000011;
    Print_MarkWord(&markWord);
    Replace_MarkWord_Bit(&markWord, 63, BIT_0);
    Print_MarkWord(&markWord);
    printf("%d\n", MarkWord_Bit(&markWord, 62));
    return 0;
}
