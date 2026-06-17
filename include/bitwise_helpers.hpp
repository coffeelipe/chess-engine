#define set_bit(bit, index) ((bit) |= (1ULL << (index)))
#define clear_bit(bit, index) ((bit) &= ~(1ULL << (index)))
#define get_bit(bit, index) ((bit) & (1ULL << (index)))
