C++
//无需实现
struct MemEntry {
    //如果>capacity, 开辟一块大小为size的内存
    size_t alloc(size_t size);

    //释放当前内存
    void free();

    //获取当前内存指针
    uint8_t* data();

    size_t capacity{ 0 };

    uint8_t* mem{ nullptr };
};

struct DataMem {
    uint64_t seq;
    size_t size;
    size_t capacity;
    uint8_t* data;
};

struct DataMemPool {
    //获取DataMemPool单例 
    static DataMemPool& instance() {
        //TODO
        static DataMemPool ins;
    }

    //申请一个DataMem
    DataMem alloc(size_t size) {
        //TODO
    }

    //返还一个DataMem
    void free(DataMem& data_mem) {
        //TODO
    }

    //获取内存池当前总大小Bytes
    uint64_t totalSize() {
        //TODO
    }

    //释放内存池所有资源
    void destroy() {
        //TODO
    }
private:
    //扩展内存池，从内存里开辟一个新的内存空间
    uint64_t expandMemEntries(size_t size) {
        //TODO
    }

    //获取一个可用且满足size要求的DataMem 
    DataMem getDataMem(uint64_t seq, size_t size) {
        //TODO
    }
    std::mutex mtx;
    std::map<uint64_t, std::set<uint64_t>> free_seqs;
    std::map<uint64_t, MemEntry> mem_entries;
}；