#ifndef SHAREDPTR_H
#define SHAREDPTR_H

template <typename T>
class SharedPtr
{
private:
    T* m_ptr;
    int* m_cnt = nullptr;

public:
    SharedPtr(T* p = nullptr)
    {
        m_ptr = p;
        m_cnt = new int;
        *m_cnt = 1;
    }

    ~SharedPtr()
    {
        (*this->m_cnt)--;
        if (*m_cnt == 0)
        {
            delete m_cnt;
            delete m_ptr;
        }
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const{ return m_ptr; }
    int useCount() {return *m_cnt; }

    SharedPtr(const SharedPtr& cp)
    {
        if (cp.m_ptr != nullptr)
        {
            this->m_ptr = cp.m_ptr;
            this->m_cnt = cp.m_cnt;
            (*this->m_cnt)++;
        }
    }

    SharedPtr& operator= (const SharedPtr &cp )
    {
        if(cp.m_ptr != nullptr){
            this->m_ptr = cp.m_ptr;
            this->m_cnt = cp.m_cnt;
            (*this->m_cnt)++;
        }
        return *this;
    }


    SharedPtr(SharedPtr && mv)
    {
        if (mv.m_ptr != nullptr)
        {
            this->m_ptr = mv.m_ptr;
            this->m_cnt = mv.m_cnt;
            mv.m_ptr = nullptr;
            mv.m_cnt = nullptr;
        }
    }

    SharedPtr& operator=(SharedPtr&& mv)
    {
        if(mv.m_ptr != nullptr){
            this->m_ptr = mv.m_ptr;
            mv.m_ptr = nullptr;
            this->m_cnt = mv.m_cnt;
            mv.m_cnt = nullptr;
        }
        return *this;
    }
};

#endif // SHAREDPTR_H
