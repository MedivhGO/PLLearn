#include <bits/stdc++.h>

using namespace std;

struct Datum {
    union {
        const int64_t* int64_;
        const uint64_t* uint64_;
        const int32_t*  int32t_;
        const uint32_t* uint32t_;
        const int16_t* int16t_;
        const uint16_t* uint16t_;
        const int8_t*   int8t_;
        const uint8_t*  uint8t_;
    };
    
    uint8_t* ptr;
    
    inline int8_t get_int8() {
        return static_cast<int8_t>(*int8t_);
    }
    
    inline uint8_t get_uint8() const
    {
        return static_cast<uint8_t>(*uint8t_);
    }
    
    inline int16_t get_smallint() const
    {
        return static_cast<int16_t>(*int16t_);
    }
    
    inline uint16_t get_usmallint() const
    {
        return static_cast<uint16_t>(*uint16t_);
    }
    
    inline int32_t get_int32() const
    {
        return static_cast<int32_t>(*int32t_);
    }
    
    inline uint32_t get_uint32() const
    {
        return static_cast<uint32_t>(*uint32t_);
    }
    
    inline int64_t get_int64() const
    {
        return static_cast<int64_t>(*int64_);
    }
    
    inline uint64_t get_uint64() const
    {
        return static_cast<uint64_t>(*uint64_);
    }
} __attribute__((packed));

void inline int8_convert_int32(int32_t* ptr, int8_t* src) {
    uint8_t mask = (*src) & 0x80 ? 0xFF : 0; 
    memset(ptr, mask, sizeof(int32_t));
    memcpy(ptr, src, sizeof(int8_t)); 
}

void inline uint8_convert_int32(int32_t* ptr, uint8_t* src) {
    uint8_t mask = 0;
    memset(ptr, mask, sizeof(int32_t));
    memcpy(ptr, src, sizeof(uint8_t)); 
}

void inline uint16_convert_int32(int32_t* ptr, uint16_t* src) {
    uint8_t mask = 0;
    memset(ptr, mask, sizeof(int32_t));
    memcpy(ptr, src, sizeof(uint16_t)); 
}

void inline int16_convert_int32(int32_t* ptr, int16_t* src) {
    uint8_t mask = (*src) & 0x8000 ? 0xFF : 0; 
    memset(ptr, mask, sizeof(int32_t));
    memcpy(ptr, src, sizeof(int16_t)); 
}

int main()
{
//    int8_t data = -128;
//    Datum datum;
//    datum.int8t_ = &data;
//    
//    int64_t i64 = 3838232323;
//    datum.int64_ = &i64;
//    
//    int32_t i32 = 127;
//    bitset<32> iset(i32);
//    cout <<iset << endl;
//    
//    cout << datum.get_int64() << endl;
//    cout << datum.get_int32() << endl;
//    cout << (int32_t)datum.get_int8() << endl;
    
    int32_t dst;
    
    
//    int8_t data = -128;
//    int8_t max_data = 127;
//    int8_convert_int32(&dst, &data);
//    bitset<32> iset(dst);
//    cout << iset << endl;
//    cout << dst << endl;
//    int8_convert_int32(&dst, &max_data);
//    cout << dst << endl;

    int16_t min_i16 = INT16_MIN;
    int16_convert_int32(&dst, &min_i16);
    cout << min_i16 << endl;
    cout << dst << endl;
}

