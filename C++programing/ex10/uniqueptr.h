#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template <typename T>
class UniquePtr
{
private:
    T* m_ptr;

public:
    UniquePtr(T* p = nullptr)
    {
            m_ptr = p;
    }
    ~UniquePtr() { delete m_ptr; }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }

    UniquePtr(const UniquePtr& cp) = delete;
    UniquePtr& operator= (const UniquePtr & ) = delete;

    UniquePtr(UniquePtr && mv)
    {
        if(mv.m_ptr != nullptr)
        {
            this->m_ptr = mv.m_ptr;
            mv.m_ptr = nullptr;
        }
    }

    UniquePtr& operator=(UniquePtr&& mv)
    {
        if(mv.m_ptr != nullptr)
        {
            this->m_ptr = mv.m_ptr;
            mv.m_ptr = nullptr;
        }
        return *this;
    }
};

#endif // UNIQUEPTR_H
