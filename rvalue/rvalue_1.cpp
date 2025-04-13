
#include <iostream>

class BigMemoryPool {
public:
  static const int PoolSize = 4096;
  BigMemoryPool() : pool_(new char[PoolSize]) {}
  ~BigMemoryPool()
  {
      if (pool_ != nullptr) {
            delete[] pool_;
      }
  }

  BigMemoryPool(BigMemoryPool&& other)
  {
      std::cout << "move big memory pool." << std::endl;
      pool_ = other.pool_;
      other.pool_ = nullptr;
  }

  BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize])
  {
      std::cout << "copy big memory pool." << std::endl;
      memcpy(pool_, other.pool_, PoolSize);
  }

  BigMemoryPool& operator=(BigMemoryPool&& other)
  {
      std::cout << "move(operator=) big memory pool." << std::endl;
      if (pool_ != nullptr) {
            delete[] pool_;
      }
      pool_ = other.pool_;
      other.pool_ = nullptr;
      return *this;
  }

private:

  char *pool_;
};


BigMemoryPool get_pool(const BigMemoryPool& pool)
{
  return pool;
}

BigMemoryPool make_pool()
{
  BigMemoryPool pool;
  return get_pool(pool);
}

int main()
{
  BigMemoryPool my_pool = make_pool();
}
